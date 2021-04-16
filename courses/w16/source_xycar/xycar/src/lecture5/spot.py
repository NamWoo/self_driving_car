import cv2

width = 640
height = 480

image = cv2.imread('spot.png',cv2.IMREAD_GRAYSCALE)

for i in range(0,height-1):
	for j in range(0,width-1):
		if image[i,j] == 255:
			print(i,j)

cv2.imshow('spot',image)
cv2.waitKey(1000)
