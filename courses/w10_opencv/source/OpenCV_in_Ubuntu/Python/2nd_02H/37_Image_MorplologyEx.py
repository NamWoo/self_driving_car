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


def imageThreshold(image, thresh=128, maxval=255, type=cv2.THRESH_BINARY):
    _, res = cv2.threshold(image, thresh=thresh, maxval=maxval, type=type)
    return res


def imageMorphologyKernel(flag=cv2.MORPH_RECT, size=5):
    return cv2.getStructuringElement(flag, (size, size))
    
    
def imageMorphologyEx(image, op, kernel, iterations=1):
    return cv2.morphologyEx(image, op=op, kernel=kernel, iterations=iterations)
    


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path + roadImage_03

roadGray = imageRead(openPath, cv2.IMREAD_GRAYSCALE)
imageShow("roadGray", roadGray)

roadGray_Threshold = imageThreshold(roadGray, 128, 255, cv2.THRESH_BINARY)
MORPH_RECT = imageMorphologyKernel(cv2.MORPH_RECT, 5)
MORPH_ELLIPSE = imageMorphologyKernel(cv2.MORPH_ELLIPSE, 5)
MORPH_CROSS = imageMorphologyKernel(cv2.MORPH_CROSS, 5)

roadGray_Open_RECT = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_OPEN, MORPH_RECT)
roadGray_Open_ELLIPSE = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_OPEN, MORPH_ELLIPSE)
roadGray_Open_CROSS = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_OPEN, MORPH_CROSS)

imageShow("roadGray_Threshold", roadGray_Threshold)
imageShow("MORPH_RECT", MORPH_RECT)
imageShow("roadGray_Open_RECT", roadGray_Open_RECT)
imageShow("MORPH_ELLIPSE", MORPH_ELLIPSE)
imageShow("roadGray_Open_ELLIPSE", roadGray_Open_ELLIPSE)
imageShow("MORPH_CROSS", MORPH_CROSS)
imageShow("roadGray_Open_CROSS", roadGray_Open_CROSS)

cv2.destroyAllWindows()

roadGray_Close_RECT = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_CLOSE , MORPH_RECT)
roadGray_Close_ELLIPSE = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_CLOSE, MORPH_ELLIPSE)
roadGray_Close_CROSS = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_CLOSE, MORPH_CROSS)

imageShow("roadGray_Threshold", roadGray_Threshold)
imageShow("MORPH_RECT", MORPH_RECT)
imageShow("roadGray_Close_RECT", roadGray_Close_RECT)
imageShow("MORPH_ELLIPSE", MORPH_ELLIPSE)
imageShow("roadGray_Close_ELLIPSE", roadGray_Close_ELLIPSE)
imageShow("MORPH_CROSS", MORPH_CROSS)
imageShow("roadGray_Close_CROSS", roadGray_Close_CROSS)

cv2.destroyAllWindows()

roadGray_Gradient_RECT = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_GRADIENT , MORPH_RECT)
roadGray_Gradient_ELLIPSE = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_GRADIENT , MORPH_ELLIPSE)
roadGray_Gradient_CROSS = imageMorphologyEx(roadGray_Threshold, cv2.MORPH_GRADIENT , MORPH_CROSS)

imageShow("roadGray_Threshold", roadGray_Threshold)
imageShow("MORPH_RECT", MORPH_RECT)
imageShow("roadGray_Gradient_RECT", roadGray_Gradient_RECT)
imageShow("MORPH_ELLIPSE", MORPH_ELLIPSE)
imageShow("roadGray_Gradient_ELLIPSE", roadGray_Gradient_ELLIPSE)
imageShow("MORPH_CROSS", MORPH_CROSS)
imageShow("roadGray_Gradient_CROSS", roadGray_Gradient_CROSS)

cv2.destroyAllWindows()

