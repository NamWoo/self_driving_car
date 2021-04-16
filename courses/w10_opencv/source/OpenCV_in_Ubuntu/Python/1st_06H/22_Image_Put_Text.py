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
    

def drawText(image, text, point=(10, 10), font=cv2.FONT_HERSHEY_PLAIN, fontScale=2.0, color=(255,255,255), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.putText(result, text, point, font, fontScale, color, thickness, lineType)


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

roadColor_Text_01 = drawText(roadColor, "OpenCV Image Processing", (10, 50), cv2.FONT_HERSHEY_PLAIN, 2.5, (255, 0, 0), 3)
roadColor_Text_01 = drawCircle(roadColor_Text_01, (10, 50), 5, (0, 0, 255), -1)
imageShow("roadColor_Text_01", roadColor_Text_01)


roadColor_Text_02 = drawText(roadColor, "cv2.FONT_HERSHEY_SIMPLEX", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_PLAIN", (10, 100), cv2.FONT_HERSHEY_PLAIN, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_DUPLEX", (10, 150), cv2.FONT_HERSHEY_DUPLEX, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_COMPLEX", (10, 200), cv2.FONT_HERSHEY_COMPLEX, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_TRIPLEX", (10, 250), cv2.FONT_HERSHEY_TRIPLEX, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_COMPLEX_SMALL", (10, 300), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_SCRIPT_SIMPLEX", (10, 350), cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, (255, 0, 0), 1)
roadColor_Text_02 = drawText(roadColor_Text_02, "cv2.FONT_HERSHEY_SCRIPT_COMPLEX", (10, 400), cv2.FONT_HERSHEY_SCRIPT_COMPLEX, 1.0, (255, 0, 0), 1)
imageShow("roadColor_Text_02", roadColor_Text_02)

cv2.destroyAllWindows()
