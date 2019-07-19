import cv2
import numpy as np


def imageRead(openpath, flag=cv2.IMREAD_UNCHANGED):
    image = cv2.imread(openpath, flag)
    if image is not None:
        print("Image Opened")
        return image
    else:
        print("Image Not Opened")
        print("Program Abort")
        exit()


def imageCopy(src):
    return np.copy(src)


def imageMedianBlur(image, size):
    ksize = (size+1) * 2 - 1
    return cv2.medianBlur(image, ksize)


def nothing(x):
    pass


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

img = imageRead(openPath, cv2.IMREAD_COLOR)
backup = imageCopy(img)
cv2.namedWindow('image', cv2.WINDOW_GUI_EXPANDED)

cv2.createTrackbar('BlurSize', 'image', 0, 10, nothing)

switch = '0:OFF\n1:On'
cv2.createTrackbar(switch, 'image', 1, 1, nothing)


while True:
    cv2.imshow('image', img)

    if cv2.waitKey(1) & 0xFF == 27:
        break
    size = cv2.getTrackbarPos('BlurSize', 'image')
    s = cv2.getTrackbarPos(switch, 'image')

    if s == 1:
        img = imageMedianBlur(backup, size)
    else:
        img = backup

cv2.destroyAllWindows()
