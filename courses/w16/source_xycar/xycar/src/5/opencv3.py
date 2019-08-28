import cv2
import numpy as np

capture = cv2.VideoCapture("1.avi")

while True:
  ret, frame = capture.read()

  hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

  lower_white = np.array([0,0,60])
  upper_white = np.array([179,255,255])

  mask = cv2.inRange(hsv, lower_white, upper_white) # hsv 

  lane_hsv = mask[430:450, 0:640]  # lane roi
  lane_bgr = cv2.cvtColor(lane_hsv, cv2.COLOR_GRAY2BGR)


  left_lane_roi = lane_bgr[2:15, 40:60]
  right_lane_roi = lane_bgr[2:15, 580:600]

  left_roi_cnt = cv2.countNonZero(left_lane_roi)
  right_roi_cnt = cv2.countNonZero(right_lane_roi)


  
  


  stopline = lane_bgr[0:20, 120:520]


  cv2.imshow('frame', lane_bgr)
  if cv2.waitKey(1) > 0:
    break

cap.release()
cv2.destroyAllWindows()
