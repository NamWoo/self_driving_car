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


def drawCircle(image, center, radius, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.circle(result, center, radius, color, thickness, lineType)


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
pt1 = (int(width * 0.5), int(height * 0.5))
r1 = 10
t1 = -1
pt2 = (int(width * 0.25), int(height * 0.25))
r2 = 20
t2 = 0
pt3 = (int(width * 0.75), int(height * 0.75))
r3 = 40
t3 = 5

roadColor_Circle_01 = drawCircle(roadColor, pt1, r1, (255, 0, 0), t1)
imageShow("roadColor_Circle_01", roadColor_Circle_01)

roadColor_Circle_02 = drawCircle(roadColor, pt2, r2, (0, 255, 0), t2)
imageShow("roadColor_Circle_02", roadColor_Circle_02)

roadColor_Circle_03 = drawCircle(roadColor, pt3, r3, (0, 0, 255), t3)
imageShow("roadColor_Circle_03", roadColor_Circle_03)

cv2.destroyAllWindows()
