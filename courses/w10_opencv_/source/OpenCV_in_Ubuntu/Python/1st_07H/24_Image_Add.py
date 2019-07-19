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


def addImage(image1, image2):
    return cv2.add(image1, image2)


def getPixel(image, x, y, c=None):
    return image[y, x, c]


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def rangeColor(image, lower, upper):
    return cv2.inRange(image, lower, upper)


def splitColor(image, lower, upper, flag=None):
    converted = convertColor(image, flag)
    mask = rangeColor(converted, lower, upper)
    return cv2.bitwise_and(image, image, mask=mask)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath_01 = path+roadImage_01
openPath_02 = path+roadImage_06
openPath_03 = path+roadImage_04

roadColor1 = imageRead(openPath_01, cv2.IMREAD_COLOR)

lower_white_hsv = np.array([0, 0, 150])
upper_white_hsv = np.array([179, 10, 255])
lower_yellow_hsv = np.array([20, 75, 150])
upper_yellow_hsv = np.array([35, 255, 255])

output_W_hsv = splitColor(roadColor1, lower_white_hsv, upper_white_hsv, cv2.COLOR_BGR2HSV)
output_Y_hsv = splitColor(roadColor1, lower_yellow_hsv, upper_yellow_hsv, cv2.COLOR_BGR2HSV)
output_hsv = addImage(output_W_hsv, output_Y_hsv)
output_hsv2 = output_W_hsv+output_Y_hsv

imageShow("output_W_hsv", output_W_hsv)
imageShow("output_Y_hsv", output_Y_hsv)
imageShow("output_hsv", output_hsv)
imageShow("output_hsv2", output_hsv2)

cv2.destroyAllWindows()

roadColor2 = imageRead(openPath_02, cv2.IMREAD_COLOR)
roadColor3 = imageRead(openPath_03, cv2.IMREAD_COLOR)
roadSum1 = addImage(roadColor2, roadColor3)
roadSum2 = roadColor2 + roadColor3

print("roadColor2, value at (463, 175)", getPixel(roadColor2, 463, 175))
print("roadColor3, value at (463, 175)", getPixel(roadColor3, 463, 175))
print("roadSum1, value at (463, 175)", getPixel(roadSum1, 463, 175))
print("roadSum2, value at (463, 175)", getPixel(roadSum2, 463, 175))

imageShow("roadColor2", roadColor2)
imageShow("roadColor3", roadColor3)
imageShow("roadSum1", roadSum1)
imageShow("roadSum2", roadSum2)

cv2.destroyAllWindows()
