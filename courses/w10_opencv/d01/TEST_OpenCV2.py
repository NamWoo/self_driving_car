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


def imageShow(imagename, image, flag=cv2.WINDOW_GUI_EXPANDED):
    cv2.namedWindow(imagename, flag)
    cv2.imshow(imagename, image)
    cv2.waitKey()


def splitImageByCV(image):
    return cv2.split(image)


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)

def getPixel(image, x, y, c=None):
    return image[y, x, c]


def setPixel(image, x, y, value, c=None):
    image[y, x, c] = value
    return image

def mergeImage(channel1, channel2, channel3):
    return cv2.merge((channel1, channel2, channel3))

path = "../../Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageShow("roadColor", roadColor)

roadHLS = convertColor(roadColor, cv2.COLOR_BGR2HLS)
imageShow("roadHLS", roadHLS)

h2, l2, s2 = splitImageByCV(roadHLS)

for i in range(100, 500):
  for j in range(100, 500):
    l2 = setPixel(l2, i, j, 150)
roadHLS = mergeImage(h2, l2, s2)
roadBGR_L = convertColor(roadHLS , cv2.COLOR_HLS2BGR)

imageShow("roadBGR_L", roadBGR_L)

roadGray = convertColor(roadBGR_L, cv2.COLOR_BGR2GRAY)
imageShow("roadGray", roadGray)

cv2.destroyAllWindows()
