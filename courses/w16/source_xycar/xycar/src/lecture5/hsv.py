import cv2
import numpy as np

image=cv2.imread('car.png')
hsv=cv2.cvtColor(image,cv2.COLOR_BGR2HSV)

lower_white=np.array([0,0,50])
upper_white=np.array([179,255,255])

mask=cv2.inRange(hsv,lower_white,upper_white)


cv2.imshow('line',mask)

cv2.waitKey(10000)
