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


def imageResize(image, dsize=None, fx=0.0, fy=0.0, interpolation=cv2.INTER_LINEAR):
    if dsize is None and fx == 0.0 and fy == 0.0:
        fx = 1.0
        fy = 1.0
    return cv2.resize(image, dsize=dsize, fx=fx, fy=fy, interpolation=interpolation)
    


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path + roadImage_03

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
height, width = roadColor.shape[:2]
print(height, width)

roadColor_Resize_01 = imageResize(roadColor, (int(width*0.3), int(height*1.2)))
roadColor_Resize_02 = imageResize(roadColor, fx=0.3, fy=1.2)
print(roadColor_Resize_01.shape[:2]) 
print(roadColor_Resize_02.shape[:2]) 

roadColor_Resize_03 = imageResize(roadColor, (int(width*1.5), int(height*2.5)))
roadColor_Resize_04 = imageResize(roadColor, fx=1.5, fy=2.5)
print(roadColor_Resize_03.shape[:2]) 
print(roadColor_Resize_04.shape[:2]) 

imageShow("roadColor", roadColor)
imageShow("roadColor_Resize_01", roadColor_Resize_01)
imageShow("roadColor_Resize_02", roadColor_Resize_02)
imageShow("roadColor_Resize_03", roadColor_Resize_03)
imageShow("roadColor_Resize_04", roadColor_Resize_04)

cv2.destroyAllWindows()
