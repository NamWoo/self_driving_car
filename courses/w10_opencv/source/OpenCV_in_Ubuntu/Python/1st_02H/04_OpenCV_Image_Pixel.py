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


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageShow("roadColor", roadColor)

x = 100
y = 200

pxvalue = getPixel(roadColor, x, y)
print("Pixel value in {}, {}: {}".format(x, y, pxvalue))

pxvalue_b = getPixel(roadColor, x, y, 0)
pxvalue_g = getPixel(roadColor, x, y, 1)
pxvalue_r = getPixel(roadColor, x, y, 2)
print("Pixel value in {}, {}: b={}, g={}, r={}".format(x, y, pxvalue_b, pxvalue_g, pxvalue_r))

for i in range(x, x+100):
    for j in range(y, y+200):
        roadColor = setPixel(roadColor, i, j, [(i-100)*1.2, 0, 0])
imageShow("roadColor", roadColor)

for i in range(x, x+100):
    for j in range(y, y+200):
        roadColor = setPixel(roadColor, i, j, [0, (i-100)*1.2, 0])
imageShow("roadColor", roadColor)

for i in range(0, roadColor.shape[1]):
    roadColor = setPixel(roadColor, i, y, 0, 0)
    roadColor = setPixel(roadColor, i, y, 255, 1)
    roadColor = setPixel(roadColor, i, y, 0, 2)
imageShow("roadColor", roadColor)

for j in range(0, roadColor.shape[0]):
    roadColor = setPixel(roadColor, x, j, [255, 0, 0])
imageShow("roadColor", roadColor)

pxvalue = getPixel(roadColor, x, y)
print("Pixel value in {}, {}: {}".format(x, y, pxvalue))

pxvalue_b = getPixel(roadColor, x, y, 0)
pxvalue_g = getPixel(roadColor, x, y, 1)
pxvalue_r = getPixel(roadColor, x, y, 2)
print("Pixel value in {}, {}: b={}, g={}, r={}".format(x, y, pxvalue_b, pxvalue_g, pxvalue_r))

cv2.destroyAllWindows()
