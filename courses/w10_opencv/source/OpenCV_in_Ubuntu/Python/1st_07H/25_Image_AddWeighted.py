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


def imageCopy(src):
    return np.copy(src)
    
    
def addWeightedImage(image1, w1, imagw2, w2=None):
    if w2 is None:
        return cv2.addWeighted(image1, float(w1) * 0.01, imagw2, float(100 - w1) * 0.01, 0)
    else:
        return cv2.addWeighted(image1, w1 * 0.01, imagw2, w2 * 0.01, 0)


def nothing(x):
    pass


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath_01 = path+roadImage_01
openPath_02 = path+roadImage_06

roadColor1 = imageRead(openPath_01, cv2.IMREAD_COLOR)
imageShow("roadColor1", roadColor1)

roadColor2 = imageRead(openPath_02, cv2.IMREAD_COLOR)
imageShow("roadColor2", roadColor2)

cv2.namedWindow('dst', cv2.WINDOW_GUI_EXPANDED)
cv2.createTrackbar('W1', 'dst', 0, 100, nothing)
cv2.createTrackbar('W2', 'dst', 0, 100, nothing)

switch = '0:OFF\n1:On'
cv2.createTrackbar(switch, 'dst', 1, 1, nothing)
dst = imageCopy(roadColor1)

while True:
    cv2.imshow('dst', dst)

    if cv2.waitKey(1) & 0xFF == 27:
        break

    w1 = cv2.getTrackbarPos('W1', 'dst')
    w2 = cv2.getTrackbarPos('W2', 'dst')
    s = cv2.getTrackbarPos(switch, 'dst')
    
    if s==0:
        dst = addWeightedImage(roadColor1, w1, roadColor2)
    else:
        dst = addWeightedImage(roadColor1, w1, roadColor2, w2)

cv2.destroyAllWindows()
