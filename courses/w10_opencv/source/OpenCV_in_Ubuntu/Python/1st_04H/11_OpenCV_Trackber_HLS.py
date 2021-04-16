import cv2
import numpy as np


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def nothing(x):
    pass


img = np.zeros((256, 256, 3), np.uint8)
cv2.namedWindow('image', cv2.WINDOW_GUI_EXPANDED)
cv2.createTrackbar('H', 'image', 0, 179, nothing)
cv2.createTrackbar('L', 'image', 0, 255, nothing)
cv2.createTrackbar('S', 'image', 0, 255, nothing)

while True:
    cv2.imshow('image', img)
    if cv2.waitKey(1) & 0xFF == 27:
        break
    h = cv2.getTrackbarPos('H', 'image')
    l = cv2.getTrackbarPos('L', 'image')
    s = cv2.getTrackbarPos('S', 'image')
    img[:] = [h, l, s]
    img = convertColor(img, cv2.COLOR_HLS2BGR)
cv2.destroyAllWindows()
