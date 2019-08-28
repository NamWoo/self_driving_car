import cv2

image = cv2.imread('black.png',cv2.IMREAD_COLOR)
img = cv2.rectangle(image, (100,100),(300,400),(0,255,0),3)
cv2.imshow('black',img)
cv2.waitKey(10000)
