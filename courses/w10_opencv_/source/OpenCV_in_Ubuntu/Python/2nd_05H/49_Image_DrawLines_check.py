import cv2
import math
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
    

def imageCopy(src):
    return np.copy(src)


def polyROI(image, points):
    if len(image.shape) == 2:
        channels = 1
    else:
        channels = image.shape[2]
    mask = np.zeros_like(image)
    ignore_mask_color = (255,) * channels
    cv2.fillPoly(mask, points, ignore_mask_color)
    return cv2.bitwise_and(image, mask)


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def cannyEdge(image, threshold1=100, threshold2=200):
    return cv2.Canny(image, threshold1, threshold2)


def addWeightedImage(image1, w1, imagw2, w2=None):
    if w2 is None:
        return cv2.addWeighted(image1, float(w1) * 0.01, imagw2, float(100 - w1) * 0.01, 0)
    else:
        return cv2.addWeighted(image1, w1 * 0.01, imagw2, w2 * 0.01, 0)


def houghLinesP(image, rho=1.0, theta=np.pi/180, threshold=100, minLineLength=10, maxLineGap=100):
    return cv2.HoughLinesP(image, rho, theta, threshold, minLineLength=minLineLength, maxLineGap=maxLineGap)


def drawHoughLinesP(image, lines):
    result = imageCopy(image)
    if len(image.shape) == 2:
        result = convertColor(image, cv2.COLOR_GRAY2BGR)
    for i in range(len(lines)):
        for x1, y1, x2, y2 in lines[i]:
            cv2.line(result, (x1, y1), (x2, y2), (0, 0, 255), 3)
    return result


def splitLines(lines):
    left_x = []
    left_y = []
    right_x = []
    right_y = []
    for line in lines:
        x1 = line[0,0]
        y1 = line[0,1]
        x2 = line[0,2]
        y2 = line[0,3]
        slope = (float)(y2-y1)/(float)(x2-x1)
        if abs(slope) < 0.5:
            continue
        if slope <= 0:
            left_x.append([x1, x2])
            left_y.append([y1, y2])
        else:
            right_x.append([x1, x2])
            right_y.append([y1, y2])
    return left_x, left_y, right_x, right_y


def medianPoint(x):
    xx = sorted(x)
    return xx[(int)(len(xx)/2)]
    

def interpolate(list_x, list_y, y):
    x1 = list_x[0]
    x2 = list_x[1]
    y1 = list_y[0]
    y2 = list_y[1]
    return int(float(y - y1) * float(x2-x1) / float(y2-y1) + x1)

    
def lineFitting(image, left_x, left_y, right_x, right_y):
    result = imageCopy(image)
    height = image.shape[0]
    lx = medianPoint(left_x)
    ly = medianPoint(left_y)
    rx = medianPoint(right_x)
    ry = medianPoint(right_y)
    min_y = int(height*0.6)
    max_y = height
    min_x_left = interpolate(lx, ly, min_y)
    max_x_left = interpolate(lx, ly, max_y)
    min_x_right = interpolate(rx, ry, min_y)
    max_x_right = interpolate(rx, ry, max_y)
    cv2.line(result, (min_x_left, min_y), (max_x_left, max_y), (0, 0, 255), 3)
    cv2.line(result, (min_x_right, min_y), (max_x_right, max_y), (0, 0, 255), 3)
    return result
    

def imageProcessing(image):
    result = imageCopy(image)

    roadGray = convertColor(result, cv2.COLOR_BGR2GRAY)
    roadEdge = cannyEdge(roadGray, 100, 200)

    height, width = result.shape[:2]

    pt1 = (width*0.45, height*0.65)
    pt2 = (width*0.55, height*0.65)
    pt3 = (width, height*1.0)
    pt4 = (0, height*1.0)
    roi_corners = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)

    roadROI = polyROI(roadEdge, roi_corners)
    houghLines_01 = houghLinesP(roadROI, 1, np.pi/180, 40)
    # draw_houghLines_01 = drawHoughLinesP(result, houghLines_01)

    lx, ly, rx, ry = splitLines(houghLines_01)
    draw_houghLines_01 = lineFitting(result, lx, ly, rx, ry)


    # imageShow("roadEdge", roadEdge)
    # imageShow("roadROI", roadROI)
    # imageShow("draw_houghLines_01", draw_houghLines_01)




    return draw_houghLines_01
    

path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

roadColor_01 = imageRead(path + roadImage_01, cv2.IMREAD_COLOR)
roadResult_01 = imageProcessing(roadColor_01)
# imageShow("roadColor_01", roadColor_01)
imageShow("roadResult_01", roadResult_01)

roadColor_02 = imageRead(path + roadImage_02, cv2.IMREAD_COLOR)
roadResult_02 = imageProcessing(roadColor_02)
# imageShow("roadColor_02", roadColor_02)
imageShow("roadResult_02", roadResult_02)

roadColor_03 = imageRead(path + roadImage_03, cv2.IMREAD_COLOR)
roadResult_03 = imageProcessing(roadColor_03)
# imageShow("roadColor_03", roadColor_03)
imageShow("roadResult_03", roadResult_03)

roadColor_04 = imageRead(path + roadImage_04, cv2.IMREAD_COLOR)
roadResult_04 = imageProcessing(roadColor_04)
# imageShow("roadColor_04", roadColor_04)
imageShow("roadResult_04", roadResult_04)

roadColor_05 = imageRead(path + roadImage_05, cv2.IMREAD_COLOR)
roadResult_05 = imageProcessing(roadColor_05)
# imageShow("roadColor_05", roadColor_05)
imageShow("roadResult_05", roadResult_05)

roadColor_06 = imageRead(path + roadImage_06, cv2.IMREAD_COLOR)
roadResult_06 = imageProcessing(roadColor_06)
# imageShow("roadColor_06", roadColor_06)
imageShow("roadResult_06", roadResult_06)

cv2.destroyAllWindows()
