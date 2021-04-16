#!/usr/bin/env python

import cv2, time
import rospy
import numpy as np

from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from ackermann_msgs.msg import AckermannDriveStamped

ack_publisher = None

bridge = CvBridge()
cv_image = np.empty(shape=[0])

def img_callback(img_data):
	global bridge
	global cv_image

	cv_image = bridge.imgmsg_to_cv2(img_data,"bgr8")

def drive(steer_val, car_run_speed):
	global ack_publisher
	
	ack_msg = AckermannDriveStamped()
	ack_msg.drive.steering_angle = steer_val
	ack_msg.drive.speed = car_run_speed
	ack_publisher.publish(ack_msg)

	rospy.init_node('go_cam')
	rospy.Subscriber("/usb_cam/image_raw/",Image,img_callback)
	ack_publisher = rospy.Publisher('/ackermann_cmd_mux/input/teleop',AckermannDriveStamped,queue_size=1)


brightness = 60
width = 640
height = 480
rec_width = 20
rec_height = 10
rpos_offset = 320
line_height_offset = 15
thresh_line_pixel_cnt = 150
r_center = 0
x_location = None

time.sleep(1.8)


while not rospy.is_shutdown():
	roi_frame = cv_image[430:450,0:width]
	roi_hsv = cv2.cvtColor(roi_frame,cv2.COLOR_BGR2HSV)

	lower_white = np.array([0,0,brightness],dtype=np.uint8)
	upper_white = np.array([131,255,255],dtype=np.uint8)

	hsv_line = cv2.inRange(roi_hsv, lower_white, upper_white)
	view = cv2.cvtColor(hsv_line, cv2.COLOR_GRAY2BGR)

	rpos = 0

	for rcol in range(rpos_offset, 640):
		detect_area = hsv_line[line_height_offset - rec_height : line_height_offset, (rcol-1):(rcol-1)+rec_width]
		nonzero = cv2.countNonZero(detect_area)

		if nonzero > thresh_line_pixel_cnt:
			rpos = (rcol - 1)
			break

		if x_location == None:
			r_center = rpos

		x_location = (r_center-rpos)
		x_location = (x_location/3)*(0.017)
		detect_area = hsv_line[2:15,120:520]
		cntzero = cv2.countNonZero(detect_area)

		if cntzero > 2400:
			drive(0,0)
			time.sleep(3)
			drive(x_location,0.5)

		cv2.imshow("origin",cv_image)
		cv2.imshow("view",view)

		if cv2.waitKey(1) & 0xff == 27:
			break

	
cv2.destroyAllWindows()
