import cv2

image = cv2.imread('img.png',cv2.IMREAD_COLOR)
cv2.imshow('my_image',image)

cv2.waitKey(0)
cv2.destroyAllWindows()
