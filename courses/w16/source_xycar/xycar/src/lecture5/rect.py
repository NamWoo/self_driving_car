import cv2

image=cv2.imread('car.png')

cv2.imshow('car',image[200:270,270:460])

cv2.waitKey(10000)
