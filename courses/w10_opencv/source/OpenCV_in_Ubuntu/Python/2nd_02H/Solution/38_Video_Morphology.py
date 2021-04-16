import cv2
import numpy as np


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def imageThreshold(image, thresh=128, maxval=255, type=cv2.THRESH_BINARY):
    _, res = cv2.threshold(image, thresh=thresh, maxval=maxval, type=type)
    return res


def imageDilation(image, kernel, iterations):
    return cv2.dilate(image, kernel=kernel, iterations=iterations)


def imageErosion(image, kernel, iterations):
    return cv2.erode(image, kernel=kernel, iterations=iterations)


def imageMorphologyKernel(flag=cv2.MORPH_RECT, size=5):
    return cv2.getStructuringElement(flag, (size, size))
    
    
def imageMorphologyEx(image, op, kernel, iterations=1):
    return cv2.morphologyEx(image, op=op, kernel=kernel, iterations=iterations)


def frameProcessing(frame):
    result = np.copy(frame)
    kernel = imageMorphologyKernel(cv2.MORPH_CROSS, 3)
    result = imageMorphologyEx(result, cv2.MORPH_GRADIENT, kernel)
    result = convertColor(result, cv2.COLOR_BGR2GRAY)
    result = imageThreshold(result, 30, 255, cv2.THRESH_BINARY)
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
out = cv2.VideoWriter('output_morphology.avi', fourcc, fps, (width, height), True)

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
