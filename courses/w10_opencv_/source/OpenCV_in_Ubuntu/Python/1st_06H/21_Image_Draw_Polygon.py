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


def drawPolygon(image, pts, isClosed, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    pts = pts.reshape((-1, 1, 2))
    return cv2.polylines(result, [pts], isClosed, color, thickness, lineType)


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

pt1 = (0, height)
pt2 = (int(width *0.5), int(height *0.5))
pt3 = (width, height)

pts = np.vstack((pt1, pt2, pt3)).astype(np.int32)
roadColor_Poly_01 = drawPolygon(roadColor, pts, True, (255, 0, 0))
imageShow("roadColor_Poly_01", roadColor_Poly_01)
roadColor_Line_01 = drawLine(roadColor, pt1, pt2, (255, 0, 0))
roadColor_Line_01 = drawLine(roadColor_Line_01, pt2, pt3, (255, 0, 0))
roadColor_Line_01 = drawLine(roadColor_Line_01, pt3, pt1, (255, 0, 0))
imageShow("roadColor_Line_01", roadColor_Line_01)

pt1 = (int(width*0.4), int(height*0.6))
pt2 = (int(width*0.6), int(height*0.6))
pt3 = (width, height)
pt4 = (0, height)

pts = np.vstack((pt1, pt2, pt3, pt4)).astype(np.int32)
roadColor_Poly_02 = drawPolygon(roadColor, pts, False, (255, 0, 0))
imageShow("roadColor_Poly_02", roadColor_Poly_02)
roadColor_Line_02 = drawLine(roadColor, pt1, pt2, (255, 0, 0))
roadColor_Line_02 = drawLine(roadColor_Line_02, pt2, pt3, (255, 0, 0))
roadColor_Line_02 = drawLine(roadColor_Line_02, pt3, pt4, (255, 0, 0))
roadColor_Line_02 = drawLine(roadColor_Line_02, pt4, pt1, (255, 0, 0))
imageShow("roadColor_Line_02", roadColor_Line_02)

cv2.destroyAllWindows()
