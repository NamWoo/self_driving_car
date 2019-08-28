import cv2
import numpy as np

capture = cv2.VideoCapture('1.avi')
capture.set(3,640)
capture.set(4,480)

sty=430,edy=450
stx=120,edx=520
while True:
   ret,frame=capture.read()

   if(ret):
      hsv = cv2.cvtColor(frame,cv2.COLOR_RGB2HSV)
      
      lower_white = np.array([0,0,150])
      upper_white = np.array([179,255,255])

      mask = cv2.inRange(hsv,lower_white, upper_white)
      cv2.imshow('Frame',frame)
      cv2.imshow('line',mask[sty:edy,stx:edx])

      cv2.waitKey(10)
#      if cv2.waitKey(1) > 0 :
#         break

cap.release()
cv2.destroyAllWindows()

