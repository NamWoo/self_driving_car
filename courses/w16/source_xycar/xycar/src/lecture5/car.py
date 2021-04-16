import cv2

image = cv2.imread('car.png')
cv2.imshow('car',image[120:270, 270:460])
cv2.waitKey(1000)
