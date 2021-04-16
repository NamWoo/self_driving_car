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


def setPixel(image, x, y, value, c=None):
    image[y, x, c] = value
    return image


def imageThreshold(image, thresh=128, maxval=255, type=cv2.THRESH_BINARY):
    _, res = cv2.threshold(image, thresh=thresh, maxval=maxval, type=type)
    return res


img = np.zeros((512, 512), np.uint8)
for i in range(0, 512):
    for j in range(0, 256):
        roadColor = setPixel(img, i, j, j)
    for j in range(256, 512):
        roadColor = setPixel(img, i, j, 256-j)
imageShow("img", img)

img_THRESH_BINARY = imageThreshold(img, 128, 255, cv2.THRESH_BINARY)
imageShow("img_THRESH_BINARY", img_THRESH_BINARY)

img_THRESH_BINARY_INV = imageThreshold(img, 128, 255, cv2.THRESH_BINARY_INV)
imageShow("img_THRESH_BINARY_INV", img_THRESH_BINARY_INV)

img_THRESH_TRUNC = imageThreshold(img, 128, 255, cv2.THRESH_TRUNC)
imageShow("img_THRESH_TRUNC", img_THRESH_TRUNC)

img_THRESH_TOZERO = imageThreshold(img, 128, 255, cv2.THRESH_TOZERO)
imageShow("img_THRESH_TOZERO", img_THRESH_TOZERO)

img_THRESH_TOZERO_INV = imageThreshold(img, 128, 255, cv2.THRESH_TOZERO_INV)
imageShow("img_THRESH_TOZERO_INV", img_THRESH_TOZERO_INV)

cv2.destroyAllWindows()
