import cv2
import numpy as np


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
    
    
def imagePerspectiveTransformation(image, src_pts, dst_pts, size=None, flags=cv2.INTER_LANCZOS4):
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
    M = cv2.getPerspectiveTransform(src_pts, dst_pts)
    return cv2.warpPerspective(image, M, dsize=size, flags=flags)


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


def frameProcessing(frame):
    result = imageCopy(frame)
    result = convertColor(result, cv2.COLOR_BGR2GRAY)
    result = cannyEdge(result, 100, 200)
    
    height, width = result.shape[:2]
    src_pt1 = [int(width*0.45), int(height*0.65)]
    src_pt2 = [int(width*0.55), int(height*0.65)]
    src_pt3 = [width, height]
    src_pt4 = [0, height]
    dst_pt1 = [int(width*0.1), 0]
    dst_pt2 = [int(width*0.9), 0]
    dst_pt3 = [int(width*0.9), height]
    dst_pt4 = [int(width*0.1), height]

    src_pts = np.float32([src_pt1, src_pt2, src_pt3, src_pt4])  
    dst_pts = np.float32([dst_pt1, dst_pt2, dst_pt3, dst_pt4])
    
    result = imagePerspectiveTransformation(result, src_pts, dst_pts)
    result = houghLinesP(result, 1, np.pi/180, 40)
    emtpy = np.zeros((height, width), np.uint8)
    result = drawHoughLinesP(emtpy, result)
    result = imagePerspectiveTransformation(result, src_pts, dst_pts, flags=cv2.WARP_INVERSE_MAP)
    result = addWeightedImage(result, 100, frame, 100)
    return result

path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Videos/"
roadVideo_01 = "solidYellowLeft.mp4"
roadVideo_02 = "solidWhiteRight.mp4"

openPath = path+roadVideo_01

cap = cv2.VideoCapture(0)

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
out = cv2.VideoWriter('output_Line_Perspective.avi', fourcc, fps, (width, height), True)

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
