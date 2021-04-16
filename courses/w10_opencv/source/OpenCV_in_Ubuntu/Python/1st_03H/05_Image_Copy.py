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
    return


def setPixel(image, x, y, value, c=None):
    image[y, x, c] = value
    return image


def imageCopy(src):
    return np.copy(src)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path + roadImage_01

img1 = imageRead(openPath, cv2.IMREAD_COLOR)
img2 = img1
img3 = imageCopy(img1)

imageShow('img1 before function', img1)
imageShow('img2 before function', img2)
imageShow('img3 before function', img3)

for i in range(img1.shape[1]):
    for j in range(img1.shape[0]):
        setPixel(img1, i, j, 255, 0)

imageShow('img1 after pixel modify', img1)
imageShow('img2 after pixel modify', img2)
imageShow('img3 after pixel modify', img3)

cv2.destroyAllWindows()

img1 = imageRead(openPath, cv2.IMREAD_COLOR)
img2 = img1
img3 = imageCopy(img1)

imageShow('img1 before function', img1)
imageShow('img2 before function', img2)
imageShow('img3 before function', img3)

img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)

imageShow('img1 after function', img1)
imageShow('img2 after function', img2)
imageShow('img3 after function', img3)

cv2.destroyAllWindows()
