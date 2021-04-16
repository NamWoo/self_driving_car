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


def imageWrite(imagename, image):
    cv2.imwrite(imagename, image)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
roadGray = imageRead(openPath, cv2.IMREAD_GRAYSCALE)
roadOrigin = imageRead(openPath, cv2.IMREAD_UNCHANGED)
imageWrite(path+"roadGray.jpg", roadGray)

imageShow("roadColor, cv2.WINDOW_NORMAL", roadColor, cv2.WINDOW_NORMAL)
imageShow("roadColor, cv2.WINDOW_AUTOSIZE", roadColor, cv2.WINDOW_AUTOSIZE)
imageShow("roadColor, cv2.WINDOW_FREERATIO", roadColor, cv2.WINDOW_FREERATIO)
imageShow("roadColor, cv2.WINDOW_GUI_NORMAL", roadColor, cv2.WINDOW_GUI_NORMAL)
imageShow("roadColor, cv2.WINDOW_GUI_EXPANDED", roadColor, cv2.WINDOW_GUI_EXPANDED)

# imageShow("roadGray, cv2.WINDOW_NORMAL", roadGray, cv2.WINDOW_NORMAL)
# imageShow("roadGray, cv2.WINDOW_AUTOSIZE", roadGray, cv2.WINDOW_AUTOSIZE)
# imageShow("roadGray, cv2.WINDOW_FREERATIO", roadGray, cv2.WINDOW_FREERATIO)
# imageShow("roadGray, cv2.WINDOW_GUI_NORMAL", roadGray, cv2.WINDOW_GUI_NORMAL)
# imageShow("roadGray, cv2.WINDOW_GUI_EXPANDED", roadGray, cv2.WINDOW_GUI_EXPANDED)

# imageShow("roadOrigin, cv2.WINDOW_NORMAL", roadOrigin, cv2.WINDOW_NORMAL)
# imageShow("roadOrigin, cv2.WINDOW_AUTOSIZE", roadOrigin, cv2.WINDOW_AUTOSIZE)
# imageShow("roadOrigin, cv2.WINDOW_FREERATIO", roadOrigin, cv2.WINDOW_FREERATIO)
# imageShow("roadOrigin, cv2.WINDOW_GUI_NORMAL", roadOrigin, cv2.WINDOW_GUI_NORMAL)
# imageShow("roadOrigin, cv2.WINDOW_GUI_EXPANDED", roadOrigin, cv2.WINDOW_GUI_EXPANDED)

cv2.destroyAllWindows()
