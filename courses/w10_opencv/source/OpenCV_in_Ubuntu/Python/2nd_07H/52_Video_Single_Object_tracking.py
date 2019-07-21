import cv2
import numpy as np
tracker_types = ['BOOSTING', 'MIL', 'KCF', 'TLD', 'MEDIANFLOW']
tracker_type = tracker_types[3]

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


def frameProcessing(frame):
    result = imageCopy(frame)
    height, width = result.shape[:2]
    pt1 = (width*0.45, height*0.6)
    pt2 = (width*0.55, height*0.6)
    pt3 = (width*0.95, height*1.0)
    pt4 = (width*0.05, height*1.0)
    roi_corners = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)
    result = polyROI(result, roi_corners)

    lower_white_hls = np.array([0, 200, 0])
    upper_white_hls = np.array([179, 255, 255])
    lower_yellow_hls = np.array([15, 30, 115])
    upper_yellow_hls = np.array([35, 200, 255])
    W_hls = splitColor(result, lower_white_hls, upper_white_hls, cv2.COLOR_BGR2HLS)
    Y_hls = splitColor(result, lower_yellow_hls, upper_yellow_hls, cv2.COLOR_BGR2HLS)
    result = W_hls+Y_hls
    result = cannyEdge(result, 100, 200)
    result = houghLinesP(result, 1, np.pi/180, 10, 10)
    lx, ly, rx, ry = splitLines(result)
    result = lineFitting(frame, lx, ly, rx, ry)
    return result

path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Videos/"
roadVideo_01 = "solidYellowLeft.mp4"
roadVideo_02 = "solidWhiteRight.mp4"

openPath = path+roadVideo_02

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
out = cv2.VideoWriter('output_Single_Object_Tracker.avi', fourcc, fps, (width, height), True)

if tracker_type == 'BOOSTING':
    tracker = cv2.TrackerBoosting_create()
if tracker_type == 'MIL':
    tracker = cv2.TrackerMIL_create()
if tracker_type == 'KCF':
    tracker = cv2.TrackerKCF_create()
if tracker_type == 'TLD':
    tracker = cv2.TrackerTLD_create()
if tracker_type == 'MEDIANFLOW':
    tracker = cv2.TrackerMedianFlow_create()
    
cv2.namedWindow("Input", cv2.WINDOW_GUI_EXPANDED)
cv2.namedWindow("Output", cv2.WINDOW_GUI_EXPANDED)
ret, frame = cap.read()
if(ret):
    bbox = cv2.selectROI(frame, False)
    ok = tracker.init(frame, bbox)

while cap.isOpened():
    # Capture frame-by-frame
    ret, frame = cap.read()
    if ret:
        # Our operations on the frame come here
        ret, bbox = tracker.update(frame)
        
        output = frameProcessing(frame)
        if ret:
            # Tracking success
            p1 = (int(bbox[0]), int(bbox[1]))
            p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
            cv2.rectangle(output, p1, p2, (255,0,0), 2, 1)
        else :
            # Tracking failure
            cv2.putText(output, "Tracking failure detected", (100,80), cv2.FONT_HERSHEY_SIMPLEX, 0.75,(0,0,255),2)
        # Display tracker type on frame
        cv2.putText(output, tracker_type + " Tracker", (100,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50),2);
     
        # Display FPS on frame
        cv2.putText(output, "FPS : " + str(int(fps)), (100,50), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50), 2);
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
