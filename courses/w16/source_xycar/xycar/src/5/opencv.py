import cv2

#image = cv2.imread('black.png', cv2.IMREAD_COLOR)
#img = cv2.rectangle(image, (100, 100), (300, 400), (0, 255, 0), 3)

#image = cv2.imread('img.png', cv2.IMREAD_COLOR)

width = 640
height = 480

#image = cv2.imread('spot.png', cv2.IMREAD_GRAYSCALE)

#for i in range(0, height-1):
#  for j in range(0, width-1):
#    if image[i,j] == 255:
#      print(i,j)

image = cv2.imread('car.png')

cv2.imshow('car',image[120:270, 270:460])
#cv2.imshow('spot',image)

cv2.waitKey(10000)
