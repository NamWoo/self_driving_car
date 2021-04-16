#!/usr/bin/env python
import rospy, time
from ackermann_msgs.msg import AckermannDriveStamped

ack_publisher = None

def drive(steer_val, car_run_speed):
	global ack_publisher
	ack_msg = AckermannDriveStamped()
	ack_msg.drive.steering_angle = steer_val
	ack_msg.drive.speed = car_run_speed
	ack_publisher.publish(ack_msg)

rospy.init_node('motor_send_node')
ack_publisher=rospy.Publisher('/ackermann_cmd_mux/input/teleop',AckermannDriveStamped,queue_size=1)

while not rospy.is_shutdown():
	for straight_cnt in range(100):
		drive(0,1)
		time.sleep(0.1)
	for left in range(100):
		drive(0.34,1)
		time.sleep(0.1)
	for right in range(100):
		drive(-0.34,1)
		time.sleep(0.1)
