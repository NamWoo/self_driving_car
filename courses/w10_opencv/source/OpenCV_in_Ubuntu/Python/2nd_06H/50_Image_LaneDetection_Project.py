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
    
def imageMorphologyKernel(flag=cv2.MORPH_RECT, size=5):
    return cv2.getStructuringElement(flag, (size, size))
    
    
def imageMorphologyEx(image, op, kernel, iterations=1):
    return cv2.morphologyEx(image, op=op, kernel=kernel, iterations=iterations)
    

def imageProcessing(image):
    result = imageCopy(image)
    # height, width = result.shape[:2]

    # export road ROI 
    pt1 = (435, 333)
    pt2 = (546, 333)
    pt3 = (960, 540)
    pt4 = (0, 540)
    roi_corners = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)
    result = polyROI(result, roi_corners)
    imageShow("polyROI", result)

    # export road color 
    lo_wh_hls = np.array([0, 200, 0])
    up_wh_hls = np.array([179, 255, 255])
    lo_ye_hls = np.array([15, 30, 115])
    up_ye_hls = np.array([35, 204, 255])
    wh_hls = splitColor(result, lo_wh_hls, up_wh_hls, cv2.COLOR_BGR2HLS)
    ye_hls = splitColor(result, lo_ye_hls, up_ye_hls, cv2.COLOR_BGR2HLS)
    result = wh_hls + ye_hls
    imageShow("splitColor", result)

    # Grayscale or Canny Edge
    result = cannyEdge(result, 100, 200)    #150,200

    # delete noise
    MORPH_ELLIPSE = imageMorphologyKernel(cv2.MORPH_ELLIPSE, 5)
    result = imageMorphologyEx(result, cv2.MORPH_OPEN, MORPH_ELLIPSE)
    imageShow("delete noise", result)



    # Draw Line 
    result = houghLinesP(result, 1, np.pi/180, 50)
    lx, ly, rx, ry = splitLines(result)
    result = lineFitting(image, lx, ly, rx, ry)


    return result
    

path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

# roadColor_01 = imageRead(path + roadImage_01, cv2.IMREAD_COLOR)
# roadResult_01 = imageProcessing(roadColor_01)
# imageShow("roadColor_01", roadColor_01)
# imageShow("roadResult_01", roadResult_01)

# roadColor_02 = imageRead(path + roadImage_02, cv2.IMREAD_COLOR)
# roadResult_02 = imageProcessing(roadColor_02)
# imageShow("roadColor_02", roadColor_02)
# imageShow("roadResult_02", roadResult_02)

# roadColor_03 = imageRead(path + roadImage_03, cv2.IMREAD_COLOR)
# roadResult_03 = imageProcessing(roadColor_03)
# imageShow("roadColor_03", roadColor_03)
# imageShow("roadResult_03", roadResult_03)

# roadColor_04 = imageRead(path + roadImage_04, cv2.IMREAD_COLOR)
# roadResult_04 = imageProcessing(roadColor_04)
# imageShow("roadColor_04", roadColor_04)
# imageShow("roadResult_04", roadResult_04)

roadColor_05 = imageRead(path + roadImage_05, cv2.IMREAD_COLOR)
roadResult_05 = imageProcessing(roadColor_05)
imageShow("roadColor_05", roadColor_05)
imageShow("roadResult_05", roadResult_05)

# roadColor_06 = imageRead(path + roadImage_06, cv2.IMREAD_COLOR)
# roadResult_06 = imageProcessing(roadColor_06)
# imageShow("roadColor_06", roadColor_06)
# imageShow("roadResult_06", roadResult_06)

cv2.destroyAllWindows()
