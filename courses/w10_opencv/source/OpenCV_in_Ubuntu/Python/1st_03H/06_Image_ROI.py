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


def CutRectROI(image, x1, y1, x2, y2):
    return image[y1:y2, x1:x2]


def PasteRectROI(image, x1, y1, x2, y2, dst):
    dst[y1:y2, x1:x2]=image
    return dst
    
    
def polyROI(image, points):
    if len(image.shape) == 2:
        channels = 1
    else:
        channels = image.shape[2]
    mask = np.zeros_like(image)
    ignore_mask_color = (255,) * channels
    cv2.fillPoly(mask, points, ignore_mask_color)
    return cv2.bitwise_and(image, mask)


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

height, width = roadColor.shape[:2]
roi_x1 = 0
roi_y1 = int(height*0.5)
roi_x2 = width
roi_y2 = height
roi_road = CutRectROI(roadColor, roi_x1, roi_y1, roi_x2, roi_y2)
imageShow("roi_road", roi_road)

roadColor2 = np.copy(roadColor)
roi_new_x1 = 0
roi_new_y1 = 0
roi_new_x2 = roi_road.shape[1]
roi_new_y2 = roi_road.shape[0]
roadColor2 = PasteRectROI(roi_road, roi_new_x1, roi_new_y1, roi_new_x2, roi_new_y2, roadColor2)
imageShow("roadColor2", roadColor2)

roi_corners_01 = np.array([[(0, height), (width / 2, height / 2), (width, height)]], dtype=np.int32)
roadColor_polyROI_01 = polyROI(roadColor, roi_corners_01)
imageShow("roadColor_polyROI_01", roadColor_polyROI_01)

pt1 = (width*0.4, height*0.6)
pt2 = (width*0.6, height*0.6)
pt3 = (width, height*1.0)
pt4 = (0, height*1.0)
roi_corners_02 = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)
roadColor_polyROI_02 = polyROI(roadColor, roi_corners_02)
imageShow("roadColor_polyROI_02", roadColor_polyROI_02)

cv2.destroyAllWindows()


