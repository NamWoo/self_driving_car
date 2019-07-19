import cv2


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


def splitImageByCV(image):
    return cv2.split(image)


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageShow("roadColor", roadColor)
b, g, r = splitImageByCV(roadColor)
imageShow("b", b)
imageShow("g", g)
imageShow("r", r)

roadHSV = convertColor(roadColor, cv2.COLOR_BGR2HSV)
imageShow("roadHSV", roadHSV)
h, s, v = splitImageByCV(roadHSV)
imageShow("h", h)
imageShow("s", s)
imageShow("v", v)

roadHLS = convertColor(roadColor, cv2.COLOR_BGR2HLS)
imageShow("roadHLS", roadHLS)
h2, l2, s2 = splitImageByCV(roadHLS)
imageShow("h2", h2)
imageShow("l2", l2)
imageShow("s2", s2)

roadGray = convertColor(roadColor, cv2.COLOR_BGR2GRAY)
imageShow("roadGray", roadGray)

cv2.destroyAllWindows()
