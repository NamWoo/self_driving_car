# !/usr/blin/env python

import rospy
from std_msgs.msg import String

def callback(msg):
 print msg.data

rospy.init_node("topic_sub")

sub = rospy.Subscriber("test_string", String, callback)

rospy.spin()
