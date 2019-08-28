#!/usr/bin/env python
import rospy, time
from sensor_msgs.msg import LaserScan

ranges_list = []

def callback(data):
	global ranges_list
	ranges_list = data.ranges

rospy.init_node('Node_Name')
rospy.Subscriber("/scan", LaserScan, callback, queue_size = 1)

time.sleep(3)

while not rospy.is_shutdown():
	if ranges_list[89] <= 1:		
		rospy.loginfo("WARNING! distance : {}".format(ranges_list[89]))
		time.sleep(0.01)
