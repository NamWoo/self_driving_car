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


def imageBlur(image, ksize):
    size = ((ksize+1) * 2 - 1, (ksize+1) * 2 - 1)
    return cv2.blur(image, size)


def imageGaussianBlur(image, ksize, sigmaX, sigmaY):
    size = ((ksize+1) * 2 - 1, (ksize+1) * 2 - 1)
    return cv2.GaussianBlur(image, ksize=size, sigmaX=sigmaX, sigmaY=sigmaY)


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
cv2.createTrackbar('sigmaX', 'image', 0, 50, nothing)
cv2.createTrackbar('sigmaY', 'image', 0, 50, nothing)

switch = '0:Mean\n1:Gaussian'
cv2.createTrackbar(switch, 'image', 0, 1, nothing)

while True:
    cv2.imshow('image', img)

    if cv2.waitKey(1) & 0xFF == 27:
        break
    size = cv2.getTrackbarPos('BlurSize', 'image')
    sigmaX = cv2.getTrackbarPos('sigmaX', 'image')
    sigmaY = cv2.getTrackbarPos('sigmaY', 'image')
    s = cv2.getTrackbarPos(switch, 'image')
    if s == 0:
        img = imageBlur(backup, size)
    else:
        img = imageGaussianBlur(backup, size, sigmaX, sigmaY)
    

cv2.destroyAllWindows()
