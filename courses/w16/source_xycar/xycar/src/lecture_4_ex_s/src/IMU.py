#!/usr/bin/env python
import rospy, time
from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue

imu_data = None

def callback(data):
	global imu_data
	imu_data = data.status[0].values
	
rospy.init_node('IMU_receive_node')
rospy.Subscriber("/diagnostics", DiagnosticArray,callback,queue_size=1)

time.sleep(15)

while not rospy.is_shutdown():
	roll = imu_data[0].value
	pitch = imu_data[1].value
	yaw = imu_data[2].value

	print("Roll : {}, Pitch : {}, Yaw : {}".format(roll, pitch, yaw))
	#time.sleep(1)
	time.sleep(0.1)

