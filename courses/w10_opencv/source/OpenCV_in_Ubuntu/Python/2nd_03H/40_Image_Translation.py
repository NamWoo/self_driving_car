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


def imageTranslation(image, size=None, dx=0.0, dy=0.0, flags=cv2.INTER_LINEAR):
    M = np.float32([[1, 0, dx], [0, 1, dy]])
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
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

dx, dy = 100, 200
size = (width+dx, height+dy)
roadColor_Translation_01 = imageTranslation(roadColor, size=size, dx=dx, dy=dy)
roadColor_Translation_02 = imageTranslation(roadColor_Translation_01, size=(width, height), dx=dx, dy=dy, flags=cv2.WARP_INVERSE_MAP)
roadColor_Translation_03 = imageTranslation(roadColor_Translation_01, size=(width, height), dx=-dx, dy=-dy)

imageShow("roadColor", roadColor)
imageShow("roadColor_Translation_01", roadColor_Translation_01)
imageShow("roadColor_Translation_02", roadColor_Translation_02)
imageShow("roadColor_Translation_03", roadColor_Translation_03)

cv2.destroyAllWindows()
