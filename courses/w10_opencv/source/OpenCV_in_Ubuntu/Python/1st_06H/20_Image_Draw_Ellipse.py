import cv2
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


def imageCopy(src):
    return np.copy(src)
    
    
def drawEllipse(image, center, axis, angle, startAngle, endAngle, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.ellipse(result, center, axis, angle, startAngle, endAngle, color, thickness, lineType)


def nothing(x):
    pass


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
backup = np.copy(roadColor)

height = roadColor.shape[0]
width = roadColor.shape[1]

cv2.namedWindow('image', cv2.WINDOW_GUI_EXPANDED)

cv2.createTrackbar('Center_x', 'image', 0, width, nothing)
cv2.createTrackbar('Center_y', 'image', 0, height, nothing)
cv2.createTrackbar('axes_x', 'image', 0, width, nothing)
cv2.createTrackbar('axes_y', 'image', 0, height, nothing)
cv2.createTrackbar('R', 'image', 0, 255, nothing)
cv2.createTrackbar('G', 'image', 0, 255, nothing)
cv2.createTrackbar('B', 'image', 0, 255, nothing)
cv2.createTrackbar('angle', 'image', 0, 360, nothing)
cv2.createTrackbar('startAngle', 'image', 0, 360, nothing)
cv2.createTrackbar('endAngle', 'image', 0, 360, nothing)
cv2.createTrackbar('Thickness', 'image', 0, 255, nothing)

switch = '0:OFF\n1:On'
cv2.createTrackbar(switch, 'image', 1, 1, nothing)

while True:
    cv2.imshow('image', roadColor)

    if cv2.waitKey(1) & 0xFF == 27:
        break
    x = cv2.getTrackbarPos('Center_x', 'image')
    y = cv2.getTrackbarPos('Center_y', 'image')
    axes_x = cv2.getTrackbarPos('axes_x', 'image')
    axes_y = cv2.getTrackbarPos('axes_y', 'image')
    r = cv2.getTrackbarPos('R', 'image')
    g = cv2.getTrackbarPos('G', 'image')
    b = cv2.getTrackbarPos('B', 'image')
    angle = cv2.getTrackbarPos('angle', 'image')
    startAngle = cv2.getTrackbarPos('startAngle', 'image')
    endAngle = cv2.getTrackbarPos('endAngle', 'image')
    thickness = cv2.getTrackbarPos('Thickness', 'image')
    thickness = thickness-1
    sw = cv2.getTrackbarPos(switch, 'image')

    if sw == 0:
        roadColor = backup
    else:
        roadColor = backup
        roadColor = drawEllipse(roadColor, (x, y), (axes_x, axes_y), angle, startAngle, endAngle, (b, g, r), thickness)

cv2.destroyAllWindows()
