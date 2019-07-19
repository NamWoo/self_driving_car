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


def splitColor(image, lower, upper, flag=cv2.COLOR_BGR2HSV):
    converted = convertColor(image, flag)
    mask = rangeColor(converted, lower, upper)
    return cv2.bitwise_and(image, image, mask=mask)


def frameProcessing(frame):
    output = imageCopy(frame)
    return output


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Videos/"
roadVideo_01 = "solidYellowLeft.mp4"
roadVideo_02 = "solidWhiteRight.mp4"

openPath = path+roadVideo_01

cap = cv2.VideoCapture(openPath)
# Get frame per second information
fps = cap.get(cv2.CAP_PROP_FPS)
# Get width and height information
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
# Define the codec and create VideoWriter object
fourcc = int(cv2.VideoWriter_fourcc(*'DIVX'))
out = cv2.VideoWriter('output_splitcolor.avi', fourcc, fps, (width, height), True) # True is 3-channel Output, False is 1-channel Output

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
