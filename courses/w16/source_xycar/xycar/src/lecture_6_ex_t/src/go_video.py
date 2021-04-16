#!/usr/bin/env python

import cv2, time
import rospy, rospkg
import numpy as np

from ackermann_msgs.msg import AckermannDriveStamped

ack_publisher = None

cv_image = np.empty(shape=[0])

def drive(steer_val, car_run_speed):
	global ack_publisher
	ack_msg = AckermannDriveStamped()
	ack_msg.drive.steering_angle = steer_val
	ack_msg.drive.speed = car_run_speed
	ack_publisher.publish(ack_msg)


#video_path = str(rospkg.RosPack().get_path('lecture_6_ex')) + "/video/1.avi"
video_path = "/home/nvidia/xycar/src/lecture_6_ex_t/video/1.avi"
cap = cv2.VideoCapture(video_path)

rospy.init_node('go_video')
ack_publisher = rospy.Publisher('/ackermann_cmd_mux/input/teleop',AckermannDriveStamped,queue_size=1)


brightness = 60

width = 640
height = 480

rec_width = 20
rec_height = 10

rpos_offset = 320

line_height_offset = 15
thresh_line_pixel_cnt=  150

r_center = 0
x_location = None

while not rospy.is_shutdown():
	ret, cv_image = cap.read()

	if cv2.waitKey(1) & 0xff == 27:
		break

	if not ret:
		cap.set(cv2.CAP_PROP_POS_FRAMES,1)
		continue

	roi_frame = cv_image[430:450, 0:width]
	roi_hsv = cv2.cvtColor(roi_frame, cv2.COLOR_BGR2HSV)

	lower_white = np.array([0,0,brightness], dtype = np.uint8)
	upper_white = np.array([131,255,255], dtype = np.uint8)

	hsv_line = cv2.inRange(roi_hsv, lower_white, upper_white)
	view = cv2.cvtColor(hsv_line, cv2.COLOR_GRAY2BGR)

	rpos = 0
	

	for rcol in range(rpos_offset, 640):
		detect_area = hsv_line[line_height_offset - rec_height : line_height_offset, (rcol-1):(rcol-1)+rec_width]
		nonzero = cv2.countNonZero(detect_area)

		if nonzero > thresh_line_pixel_cnt:
			rpos = (rcol)-1
			break

	if x_location == None:
			r_center = rpos

	x_location = r_center - rpos
	x_location = (x_location/3) * (0.017)
	detect_area = hsv_line[2:15, 120:520]
	cntzero = cv2.countNonZero(detect_area)

	if cntzero > 2400:
		drive(0,0)
		time.sleep(3)


	drive(x_location,5)

	cv2.imshow("origin",cv_image)
	cv2.imshow("view",view)
	time.sleep(0.01)

cv2.destoryAllWindows()
