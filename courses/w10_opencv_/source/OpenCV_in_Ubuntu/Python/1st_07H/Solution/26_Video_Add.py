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


def addImage(image1, image2):
    return cv2.add(image1, image2)


def addWeightedImage(image1, w1, imagw2, w2=None):
    if w2 is None:
        return cv2.addWeighted(image1, float(w1) * 0.01, imagw2, float(100 - w1) * 0.01, 0)
    else:
        return cv2.addWeighted(image1, w1 * 0.01, imagw2, w2 * 0.01, 0)


def frameProcessing(frame):
    result = imageCopy(frame)
    pt1 = (width * 0.35, height * 0.65)
    pt2 = (width * 0.65, height * 0.65)
    pt3 = (width, height)
    pt4 = (0, height)
    roi = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)
    result = polyROI(result, roi)

    lower_white = np.array([0, 200, 0])
    upper_white = np.array([179, 255, 255])
    lower_yellow = np.array([15, 30, 115])
    upper_yellow = np.array([35, 204, 255])

    W_hls = splitColor(result, lower_white, upper_white, cv2.COLOR_BGR2HLS)
    Y_hls = splitColor(result, lower_yellow, upper_yellow, cv2.COLOR_BGR2HLS)
    result = addImage(W_hls,Y_hls)

    result2 = np.copy(frame)
    pt1 = (width * 0.35, height * 0.65)
    pt2 = (width * 0.65, height * 0.65)
    pt3 = (width, height)
    pt4 = (width, 0)
    pt5 = (0, 0)
    pt6 = (0, height)
    roi = np.array([[pt1, pt2, pt3, pt4, pt5, pt6]], dtype=np.int32)
    result2 = polyROI(result2, roi)
    result = addWeightedImage(result, 100, result2, 100)
    return result

path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Videos/"
roadVideo_01 = "solidYellowLeft.mp4"
roadVideo_02 = "solidWhiteRight.mp4"

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
out = cv2.VideoWriter('output_addWeighted.avi', fourcc, fps, (width, height), True)

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
