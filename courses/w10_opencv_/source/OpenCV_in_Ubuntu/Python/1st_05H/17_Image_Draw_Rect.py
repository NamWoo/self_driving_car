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


def imageCopy(src):
    return np.copy(src)


def drawLine(image, point1, point2, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.line(result, point1, point2, color, thickness, lineType)


def drawRect(image, point1, point2, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.rectangle(result, point1, point2, color, thickness, lineType)


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

height = roadColor.shape[0]
width = roadColor.shape[1]
pt1 = (0, int(height * 0.6))
pt2 = (width, height)

roadColor_Line_01 = drawLine(roadColor, pt1, pt2, (255, 0, 0))
imageShow("roadColor_Line_01", roadColor_Line_01)

roadColor_Rect_01 = drawRect(roadColor, pt1, pt2, (255, 0, 0))
imageShow("roadColor_Rect_01", roadColor_Rect_01)

roadColor_Rect_02 = drawRect(roadColor, pt1, pt2, (255, 0, 0), -1)
imageShow("roadColor_Rect_02", roadColor_Rect_02)

cv2.destroyAllWindows()
