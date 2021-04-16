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


def imageParameters(imagename, image):
    height, width = image.shape[0], image.shape[1]
    print("{}.shape is {}".format(imagename, image.shape))
    print("{}.shape[0] is height: {}".format(imagename, height))
    print("{}.shape[1] is width: {}".format(imagename, width))
    if len(image.shape) == 2:
        print("This is grayscale image.")
        print("{}.shape[2] is Not exist, So channel is 1".format(imagename))
        channel = 1
        print("height*width*channels is {}".format(height * width * channel))
    else:
        print("This is not grayscale image.")
        print("{}.shape[2] is channels: {}".format(imagename, image.shape[2]))
        channel = image.shape[2]
        print("height*width*channels is {}".format(height * width * channel))
    print("{}.size is {}".format(imagename, image.size))
    print("{}.dtype is {}".format(imagename, image.dtype))
    return height, width, channel


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageParameters("roadColor", roadColor)
imageShow("roadColor", roadColor)

roadGray = imageRead(openPath, cv2.IMREAD_GRAYSCALE)
imageParameters("roadGray", roadGray)
imageShow("roadGray", roadGray)

cv2.destroyAllWindows()
