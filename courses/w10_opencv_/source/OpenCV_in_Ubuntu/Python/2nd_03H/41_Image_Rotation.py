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


def imageRotation(image, center=None, angle=0.0, scale=1.0, size=None, flags=cv2.INTER_LINEAR):
    if center is None:
        rows, cols = image.shape[:2]
        center = (cols/2, rows/2)
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
    M = cv2.getRotationMatrix2D(center, angle, scale)
    return cv2.warpAffine(image, M, size, flags=flags)
    


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

center = (width/2, height/2)
angle = 15
scale = 1.2
original_size = (width, height)
modified_size = (int(width*scale),int(height*scale))
roadColor_Rotation_01 = imageRotation(roadColor, center=center, angle=angle, scale=scale, size=modified_size)
roadColor_Rotation_02 = imageRotation(roadColor_Rotation_01, center=center, angle=angle, scale=scale, flags=cv2.WARP_INVERSE_MAP, size=original_size)
roadColor_Rotation_03 = imageRotation(roadColor_Rotation_01, center=center, angle=-angle, scale=1.0/scale, size=original_size)
print(roadColor_Rotation_01.shape[:2]) 
print(roadColor_Rotation_02.shape[:2]) 
print(roadColor_Rotation_03.shape[:2]) 

imageShow("roadColor", roadColor)
imageShow("roadColor_Rotation_01", roadColor_Rotation_01)
imageShow("roadColor_Rotation_02", roadColor_Rotation_02)
imageShow("roadColor_Rotation_03", roadColor_Rotation_03)

cv2.destroyAllWindows()
