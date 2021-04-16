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

openPath = path+roadImage_06

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageShow("roadColor", roadColor)

lower_white_hsv = np.array([0, 0, 150])
upper_white_hsv = np.array([179, 10, 255])
lower_yellow_hsv = np.array([20, 75, 150])
upper_yellow_hsv = np.array([35, 255, 255])

output_W_hsv = splitColor(roadColor, lower_white_hsv, upper_white_hsv, cv2.COLOR_BGR2HSV)
output_Y_hsv = splitColor(roadColor, lower_yellow_hsv, upper_yellow_hsv, cv2.COLOR_BGR2HSV)
output_hsv = output_W_hsv+output_Y_hsv

imageShow("output_W_hsv", output_W_hsv)
imageShow("output_Y_hsv", output_Y_hsv)
imageShow("output_hsv", output_hsv)

lower_white_hls = np.array([0, 200, 0])
upper_white_hls = np.array([179, 255, 255])
lower_yellow_hls = np.array([15, 30, 115])
upper_yellow_hls = np.array([35, 204, 255])

output_W_hls = splitColor(roadColor, lower_white_hls, upper_white_hls, cv2.COLOR_BGR2HLS)
output_Y_hls = splitColor(roadColor, lower_yellow_hls, upper_yellow_hls, cv2.COLOR_BGR2HLS)
output_hls = output_W_hls+output_Y_hls

imageShow("output_W_hls", output_W_hls)
imageShow("output_Y_hls", output_Y_hls)
imageShow("output_hls", output_hls)

cv2.destroyAllWindows()
