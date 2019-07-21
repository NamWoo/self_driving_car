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


def getPixel(image, x, y, c=None):
    return image[y, x, c]


def setPixel(image, x, y, value, c=None):
    image[y, x, c] = value
    return image


path = "../../Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath1 = path+roadImage_02
roadColor1 = imageRead(openPath1, cv2.IMREAD_COLOR)
imageShow("roadColor1", roadColor1)

openPath2 = path+roadImage_03
roadColor2 = imageRead(openPath2, cv2.IMREAD_COLOR)
imageShow("roadColor2", roadColor2)

openPath3 = path+roadImage_06
roadColor3 = imageRead(openPath3, cv2.IMREAD_COLOR)
imageShow("roadColor3", roadColor3)

x = 100
y = 100

pxvalue = getPixel(roadColor3, x, y)
print("Pixel value in {}, {}: {}".format(x, y, pxvalue))

pxvalue_b = getPixel(roadColor3, x, y, 0)
pxvalue_g = getPixel(roadColor3, x, y, 1)
pxvalue_r = getPixel(roadColor3, x, y, 2)
print("Pixel value in {}, {}: b={}, g={}, r={}".format(x, y, pxvalue_b, pxvalue_g, pxvalue_r))

for i in range(x, x+400):
    for j in range(y, y+400):
        roadColor3 = setPixel(roadColor3, i, j, [0, 0, 0])
imageShow("roadColor3", roadColor3)

cv2.destroyAllWindows()
