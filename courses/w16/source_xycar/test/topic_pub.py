# !/usr/bin/env python

import rospy
from std_msgs.msg import String

rospy.init_node("topic_pub")

pub = rospy.Publisher("test_string",String)

rate = rospy.Rate(2)

while not rospy.is_shutdown():
 pub.publish("AAA-BBB")
 rate.sleep()
