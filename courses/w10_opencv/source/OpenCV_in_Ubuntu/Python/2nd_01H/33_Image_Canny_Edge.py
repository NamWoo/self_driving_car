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


def cannyEdge(image, threshold1=100, threshold2=200):
    return cv2.Canny(image, threshold1, threshold2) 
    
    
def nothing(x):
    pass
    
    
path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_03

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
backup = imageCopy(roadColor)
cv2.namedWindow('image', cv2.WINDOW_GUI_EXPANDED)

cv2.createTrackbar('threshold1', 'image', 0, 200, nothing)
cv2.createTrackbar('threshold2', 'image', 100, 400, nothing)

switch = '0:OFF\n1:On'
cv2.createTrackbar(switch, 'image', 1, 1, nothing)

while True:
    cv2.imshow('image', roadColor)

    if cv2.waitKey(1) & 0xFF == 27:
        break
    threshold1 = cv2.getTrackbarPos('threshold1', 'image')
    threshold2 = cv2.getTrackbarPos('threshold2', 'image')
    s = cv2.getTrackbarPos(switch, 'image')
    if s == 1:
        roadColor = cannyEdge(backup, threshold1, threshold2)
    else:
        roadColor = backup

cv2.destroyAllWindows()
