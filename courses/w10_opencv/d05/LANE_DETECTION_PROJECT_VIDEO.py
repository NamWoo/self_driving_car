import cv2
import numpy as np


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


def meanPoint(x):
    sum1 = 0
    sum2 = 0
    for x1, x2 in x:
        sum1 += x1
        sum2 += x2
    sum1 = int(float(sum1)/float(len(x)))
    sum2 = int(float(sum2)/float(len(x)))
    return [sum1, sum2]

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
    lx = meanPoint(left_x)
    ly = meanPoint(left_y)
    rx = meanPoint(right_x)
    ry = meanPoint(right_y)
    min_y = int(height*0.6)
    max_y = height
    min_x_left = interpolate(lx, ly, min_y)
    max_x_left = interpolate(lx, ly, max_y)
    min_x_right = interpolate(rx, ry, min_y)
    max_x_right = interpolate(rx, ry, max_y)
    cv2.line(result, (min_x_left, min_y), (max_x_left, max_y), (0, 0, 255), 3)
    cv2.line(result, (min_x_right, min_y), (max_x_right, max_y), (0, 0, 255), 3)
    return result

def imagePerspectiveTransformation(image, src_pts, dst_pts, size=None, flags=cv2.INTER_LANCZOS4):
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
    M = cv2.getPerspectiveTransform(src_pts, dst_pts)
    return cv2.warpPerspective(image, M, dsize=size, flags=flags)
def Processing(image_list, ROI_list, IMSHOW):
    result_list = []
    for i in range(len(image_list)):
        inner_list = []
        for j in range(len(image_list[i])):
            inner_list.append(imageProcessing(image_list[i][j], ROI_list[i], IMSHOW))
        result_list.append(inner_list)
    return result_list


def interpolate_v2(slopes, y):
    x1 = slopes[1]
    y1 = slopes[2]
    x2 = slopes[3]
    y2 = slopes[4]
    if(y2-y1==0):
        return 0
    return int(float(y - y1) * float(x2-x1) / float(y2-y1) + x1)
    
def sort_by_slope(lines, height):
    slopes = []
    if lines is None:
        return slopes
    for i in range(len(lines)):
        for x1, y1, x2, y2 in lines[i]:
            if (x1 == x2):
                continue
            slope = (y2 - y1) / (x2 - x1)
            slopes.append([slope, x1, y1, x2, y2])

    slopes = medianPoint(slopes)
    x_down = interpolate_v2(slopes, height)
    x_top = interpolate_v2(slopes, 0)
    pt1 = (x_down, height)
    pt2 = (x_top, 0)
    return pt1, pt2
def imageMorphologyKernel(flag=cv2.MORPH_RECT, size=5):
    return cv2.getStructuringElement(flag, (size, size))
    
    
def imageMorphologyEx(image, op, kernel, iterations=1):
    return cv2.morphologyEx(image, op=op, kernel=kernel, iterations=iterations)
def drawPolygon(image, pts, isClosed, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    pts = pts.reshape((-1, 1, 2))
    return cv2.polylines(result, [pts], isClosed, color, thickness, lineType)
    
def frameProcessing(image):
    result = imageCopy(image)
    height, width = result.shape[:2]
    pt1 = (600,340)
    pt2 = (710,340)
    pt3 = (800,404)
    pt4 = (540,404)
    roi = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)
    
    lower_white_hls = np.array([0, 143, 25])
    upper_white_hls = np.array([179, 255, 255])
    lower_yellow_hls = np.array([15, 30, 115])
    upper_yellow_hls = np.array([35, 204, 255])
    
    HLS = convertColor(result, cv2.COLOR_BGR2HLS)
    W_HLS = rangeColor(HLS, lower_white_hls, upper_white_hls)
    Y_HLS = rangeColor(HLS, lower_yellow_hls, upper_yellow_hls)
    WY_HLS = W_HLS + Y_HLS
    MORPH_ELLIPSE = imageMorphologyKernel(cv2.MORPH_ELLIPSE, 7)
    output = imageMorphologyEx(WY_HLS, cv2.MORPH_CLOSE , MORPH_ELLIPSE, 1)
    
    src_pt1 = [roi[0][0][0], roi[0][0][1]]
    src_pt2 = [roi[0][1][0], roi[0][1][1]]
    src_pt3 = [roi[0][2][0], roi[0][2][1]]
    src_pt4 = [roi[0][3][0], roi[0][3][1]]
    dst_pt1 = [int(width*0.1), 0]
    dst_pt2 = [int(width*0.9), 0]
    dst_pt3 = [int(width*0.9), height]
    dst_pt4 = [int(width*0.1), height]
    src_pts = np.float32([src_pt1, src_pt2, src_pt3, src_pt4])
    dst_pts = np.float32([dst_pt1, dst_pt2, dst_pt3, dst_pt4])
    result = cannyEdge(output, 100, 200)
    
    roadAffine_01 = imagePerspectiveTransformation(result, src_pts, dst_pts)
    left_u = (0,0)
    left_d = (0,height)
    center_u = (int(width*0.5),0)
    center_d = (int(width*0.5),height)
    right_u= (width, 0)
    right_d= (width, height)
    roi_l = np.array([[left_u, center_u, center_d, left_d]], dtype=np.int32)
    roi_r = np.array([[center_u, right_u, right_d, center_d]], dtype=np.int32)
    
    ROI_RIGHT = polyROI(roadAffine_01, roi_r)
    ROI_LEFT = polyROI(roadAffine_01, roi_l)
    
    lines_left = houghLinesP(ROI_LEFT, 1, np.pi/180, 150, 75, 5)
    lines_right = houghLinesP(ROI_RIGHT, 1, np.pi/180, 150, 75, 5)
    pt1_r, pt2_r = sort_by_slope(lines_left, height)
    pt1_l, pt2_l = sort_by_slope(lines_right, height)
    

    empty = np.zeros((height, width), np.uint8)
    BGR = convertColor(empty, cv2.COLOR_GRAY2BGR)

    draw_houghLines_02 = cv2.line(BGR, pt1_r, pt2_r, (255, 0, 0), 10)
    draw_houghLines_02 = cv2.line(draw_houghLines_02, pt1_l, pt2_l, (0, 0, 255), 10)

    points = np.array([[pt1_r, pt1_l, pt2_l, pt2_r ]], dtype=np.int32)
    cv2.fillPoly(draw_houghLines_02, points, (0, 255, 0))
    
    roadAffine_03 = imagePerspectiveTransformation(draw_houghLines_02, src_pts, dst_pts, flags=cv2.WARP_INVERSE_MAP)
    result = addWeightedImage(roadAffine_03, 100, image, 100)
    
    
    return result

path = "./"
roadVideo_01 = "ETS_C_01.mp4"
#roadVideo_02 = "solidWhiteRight.mp4"

openPath = path+roadVideo_01

cap = cv2.VideoCapture(openPath)

# Get frame per second information
fps = cap.get(cv2.CAP_PROP_FPS)
print("Frames per second using video.get(cv2.CAP_PROP_FPS) : {0}".format(fps))
# Get width and height information
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
print(width)
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(height)
# Define the codec and create VideoWriter object
fourcc = int(cv2.VideoWriter_fourcc(*'DIVX'))
print(fourcc)
out = cv2.VideoWriter('output_LaneDetection_Project.avi', fourcc, fps, (width, height), True)

cv2.namedWindow("Input", cv2.WINDOW_GUI_EXPANDED)
cv2.namedWindow("Output", cv2.WINDOW_GUI_EXPANDED)

while cap.isOpened():
    # Capture frame-by-frame
    ret, frame = cap.read()

    if ret:
        # Our operations on the frame come here
        output = frameProcessing(frame)
        # Write frame-by-frame
        out.write(output)
        # Display the resulting frame
        cv2.imshow("Input", frame)
        cv2.imshow("Output", output)

    else:
        break

    # waitKey(int(1000.0/fps)) for matching fps of video
    if cv2.waitKey(int(1000.0/fps)) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
out.release()

cv2.destroyAllWindows()
