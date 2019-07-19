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


def imageMorphologyKernel(flag=cv2.MORPH_RECT, size=5):
    return cv2.getStructuringElement(flag, (size, size))
    
    
def imageMorphologyEx(image, op, kernel, iterations=1):
    return cv2.morphologyEx(image, op=op, kernel=kernel, iterations=iterations)
    
    
def splitColor(image, lower, upper, flag=None):
    MORPH_ELLIPSE = imageMorphologyKernel(cv2.MORPH_ELLIPSE, 3)
    converted = convertColor(image, flag)
    mask = rangeColor(converted, lower, upper)
    
    mask = imageMorphologyEx(mask, cv2.MORPH_CLOSE , MORPH_ELLIPSE, 2)
    return mask#cv2.bitwise_and(image, image, mask=mask)


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
        if(x2-x1 == 0):
            continue
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
    print(len(xx))
    if (len(xx)==0):
        return [0,0]
    return xx[(int)(len(xx)/2)]
    

def interpolate(list_x, list_y, y):
    x1 = list_x[0]
    x2 = list_x[1]
    y1 = list_y[0]
    y2 = list_y[1]
    if (y2 - y1 == 0):
        return -1
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
    
    
def openImages():
    path = "/home/opencv-mds/Project_Images/"
    
    Env_list = []
    ETS_C_list = []
    ETS_H_list = []
    PC_C_list = []
    PC_F_list = []
    PC_H_list = []
    PC_T_list = []
    
    ETS_C_01 = "ETS_C_01.jpg"
    ETS_C_02 = "ETS_C_02.jpg"
    ETS_C_list.append(imageRead(path+ETS_C_01))
    ETS_C_list.append(imageRead(path+ETS_C_02))
    
    ETS_H_01 = "ETS_H_01.jpg"
    ETS_H_list.append(imageRead(path+ETS_H_01))
    
    PC_C_01 = "PC_C_01.jpg"
    PC_C_02 = "PC_C_02.jpg"
    PC_C_list.append(imageRead(path+PC_C_01))
    PC_C_list.append(imageRead(path+PC_C_02))
    
    PC_F_01 = "PC_F_01.jpg"
    PC_F_02 = "PC_F_02.jpg"
    PC_F_list.append(imageRead(path+PC_F_01))
    PC_F_list.append(imageRead(path+PC_F_02))
    
    PC_H_01 = "PC_H_01.jpg"
    PC_H_02 = "PC_H_02.jpg"
    PC_H_list.append(imageRead(path+PC_H_01))
    PC_H_list.append(imageRead(path+PC_H_02))
    
    PC_T_01 = "PC_T_01.jpg"
    PC_T_02 = "PC_T_02.jpg"
    PC_T_list.append(imageRead(path+PC_T_01))
    PC_T_list.append(imageRead(path+PC_T_02))
        
    Env_list.append(ETS_C_list)
    Env_list.append(ETS_H_list)
    Env_list.append(PC_C_list)
    Env_list.append(PC_F_list)
    Env_list.append(PC_H_list)
    Env_list.append(PC_T_list)
    return Env_list
    

def showImageList(name, doubleImageList):
    for i in range(len(doubleImageList)):
        for j in range(len(doubleImageList[i])):
            imageShow("{}[{}][{}]".format(name,i,j), doubleImageList[i][j])
    return


def showImageListWithROI(doubleImageList, ROIs):
    for i in range(len(doubleImageList)):
        for j in range(len(doubleImageList[i])):
            imageShow("doubleImageList[{}][{}]".format(i,j), doubleImageList[i][j])
            imageShow("doubleImageListROIs[{}][{}]".format(i,j), \
            polyROI(doubleImageList[i][j], ROIs[i]))
    return


def ROI_definition():
    ROI_list = []
    # ROI for ETS_C_list
    pt1 = (600,330)
    pt2 = (710,330)
    pt3 = (800,404)
    pt4 = (540,404)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32))
   
    # ROI for ETS_H_list
    pt1 = (580,390)
    pt2 = (700,390)
    pt3 = (1280,720)
    pt4 = (80,720)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32))
   
    # ROI for PC_C_list
    pt1 = (370,320)
    pt2 = (455,320)
    pt3 = (600,370)
    pt4 = (255,370)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32))
   
    # ROI for PC_F_list
    pt1 = (330,300)
    pt2 = (500,300)
    pt3 = (800,370)
    pt4 = (800,450)
    pt5 = (0,450)
    pt6 = (0,370)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4, pt5, pt6]],\
     dtype=np.int32))
   
    # ROI for ETS_H_list
    pt1 = (200,300)
    pt2 = (620,300)
    pt3 = (800,370)
    pt4 = (800,450)
    pt5 = (0,450)
    pt6 = (0,370)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4, pt5, pt6]],\
     dtype=np.int32))
   
    # ROI for PC_T_list
    pt1 = (200,300)
    pt2 = (620,300)
    pt3 = (800,370)
    pt4 = (800,430)
    pt5 = (0,430)
    pt6 = (0,370)
    ROI_list.append(np.array([[pt1, pt2, pt3, pt4, pt5, pt6]],\
     dtype=np.int32))
    return ROI_list

    
def imageProcessing(image, roi):
    result = imageCopy(image)
    roi_corners = roi
    lower_white_hls = np.array([0, 143, 25])
    upper_white_hls = np.array([179, 255, 255])
    lower_yellow_hls = np.array([15, 30, 115])
    upper_yellow_hls = np.array([35, 204, 255])
    
    roadROI = polyROI(result, roi_corners)

    imageShow("image", image)
    imageShow("roadROI", roadROI)
    
    output_W_hls = splitColor(roadROI, lower_white_hls, upper_white_hls, cv2.COLOR_BGR2HLS)
    output_Y_hls = splitColor(roadROI, lower_yellow_hls, upper_yellow_hls, cv2.COLOR_BGR2HLS)
    output = output_W_hls+output_Y_hls
    imageShow("output_W_hls", output_W_hls)
    imageShow("output_Y_hls", output_Y_hls)
    imageShow("output", output)
    morph_kernel = imageMorphologyKernel(cv2.MORPH_RECT, size=5)
    output_morph = imageMorphologyEx(output, cv2.MORPH_GRADIENT, morph_kernel, 1)
    imageShow("output_morph", output_morph)
    roadEdge = cannyEdge(output_morph, 50, 100)    
    imageShow("roadEdge", roadEdge)
    houghLines_01 = houghLinesP(roadEdge, 1, np.pi/180, 1)
    print(houghLines_01)
    lx, ly, rx, ry = splitLines(houghLines_01)
    draw_houghLines_01 = lineFitting(image, lx, ly, rx, ry)
    imageShow("draw_houghLines_01", draw_houghLines_01)
        
    return draw_houghLines_01


def Processing(image_list, ROI_list):
    result_list = []
    for i in range(len(image_list)):
        inner_list = []
        for j in range(len(image_list[i])):
            inner_list.append(imageProcessing(image_list[i][j], ROI_list[i]))
        result_list.append(inner_list)
    return result_list
    
    
ROIs = ROI_definition()
Images = openImages()
#showImageListWithROI(Images, ROIs)
result_list = Processing(Images, ROIs)
showImageList("result_list", result_list)

cv2.destroyAllWindows()
