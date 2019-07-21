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


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def rangeColor(image, lower, upper):
    return cv2.inRange(image, lower, upper)


def splitColor(image, lower, upper, flag=cv2.COLOR_BGR2HSV):
    converted = convertColor(image, flag)
    mask = rangeColor(converted, lower, upper)
    return cv2.bitwise_and(image, image, mask=mask)


def nothing(x):
    pass


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_06

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
img = imageCopy(roadColor)
cv2.namedWindow('image', cv2.WINDOW_GUI_EXPANDED)
cv2.createTrackbar('H_lower', 'image', 0, 179, nothing)
cv2.createTrackbar('L_lower', 'image', 0, 255, nothing)
cv2.createTrackbar('S_lower', 'image', 0, 255, nothing)
cv2.createTrackbar('H_upper', 'image', 0, 179, nothing)
cv2.createTrackbar('L_upper', 'image', 0, 255, nothing)
cv2.createTrackbar('S_upper', 'image', 0, 255, nothing)

while True:
    cv2.imshow('image', img)
    if cv2.waitKey(1) & 0xFF == 27:
        break
    h_l = cv2.getTrackbarPos('H_lower', 'image')
    l_l = cv2.getTrackbarPos('L_lower', 'image')
    s_l = cv2.getTrackbarPos('S_lower', 'image')
    h_u = cv2.getTrackbarPos('H_upper', 'image')
    l_u = cv2.getTrackbarPos('L_upper', 'image')
    s_u = cv2.getTrackbarPos('S_upper', 'image')
    lower = np.array([h_l, l_l, s_l])
    upper = np.array([h_u, l_u, s_u])
    img = splitColor(roadColor, lower, upper, cv2.COLOR_BGR2HLS)
cv2.destroyAllWindows()
