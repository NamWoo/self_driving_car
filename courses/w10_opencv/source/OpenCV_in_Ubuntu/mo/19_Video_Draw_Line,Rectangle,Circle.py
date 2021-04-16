import cv2
import numpy as np


def imageCopy(src):
    return np.copy(src)


def drawLine(image, point1, point2, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.line(result, point1, point2, color, thickness, lineType)


def drawRect(image, point1, point2, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.rectangle(result, point1, point2, color, thickness, lineType)


def drawCircle(image, center, radius, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.circle(result, center, radius, color, thickness, lineType)

def drawEllipse(image, center, axis, angle, startAngle, endAngle, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.ellipse(result, center, axis, angle, startAngle, endAngle, color, thickness, lineType)


def drawPolygon(image, pts, isClosed, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    pts = pts.reshape((-1, 1, 2))
    return cv2.polylines(result, [pts], isClosed, color, thickness, lineType)

def frameProcessing(frame):
    result = imageCopy(frame)
    height = result.shape[0]
    width = result.shape[1]

    #line
    pt1 = (430,310)
    pt2 = (530,310)
    pt3 = (940,540)
    pt4 = (20,540)
    pts = np.vstack((pt1, pt2, pt3, pt4)).astype(np.int32)
    result = drawPolygon(result, pts, True, (255, 0, 0))

    #triangle
    pt1 = (int(width/2), int(height/2))
    pt2 = (0, height)
    pt3 = (width, height)
    pts = np.vstack((pt1, pt2, pt3)).astype(np.int32)
    result = drawPolygon(result, pts, True, (0, 255, 0))

    #line
    #pt1 = (0,0)
    #pt2 = (width,0)
    #pt3 = (0,height)
    #pt4 = (width,height)
    pt1 = (0,0)
    pt2 = (0,height)
    pt3 = (width,height)
    pt4 = (width,0)
    pts = np.vstack((pt1, pt2, pt3, pt4)).astype(np.int32)
    result = drawPolygon(result, pts, True, (0, 0, 0))

    #circle
    result = drawEllipse(result, (int(width*0.5), int(height*0.5)), (30, 30), 0, 0, 360, (255,255,255),-1)
    return result


path = "../../Data/Lane_Detection_Videos/"
roadVideo_01 = "solidYellowLeft.mp4"
roadVideo_02 = "solidWhiteRight.mp4"

openPath = path+roadVideo_01

cap = cv2.VideoCapture(openPath)

# Get frame per second information
fps = cap.get(cv2.CAP_PROP_FPS)
print("Frames per second using video.get(cv2.CAP_PROP_FPS) : {0}".format(fps))
# Get width and height information
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
# Define the codec and create VideoWriter object
fourcc = int(cv2.VideoWriter_fourcc(*'DIVX'))
out = cv2.VideoWriter('output_draw.avi', fourcc, fps, (width, height), True)  # 3-channel Output

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
