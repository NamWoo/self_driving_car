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


def imageShow(imagename, image, flag=cv2.WINDOW_GUI_EXPANDED):
    cv2.namedWindow(imagename, flag)
    cv2.imshow(imagename, image)
    cv2.waitKey()


def imageThreshold(image, thresh=128, maxval=255, type=cv2.THRESH_BINARY):
    _, res = cv2.threshold(image, thresh=thresh, maxval=maxval, type=type)
    return res


def imageDilation(image, kernel, iterations):
    return cv2.dilate(image, kernel=kernel, iterations=iterations)


def imageErosion(image, kernel, iterations):
    return cv2.erode(image, kernel=kernel, iterations=iterations)
    

def imageMorphologicalGradient(image):
    kernel = np.ones((3, 3), np.uint8)
    dilation = imageDilation(image, kernel, 1)
    erosion = imageErosion(image, kernel, 1)
    return dilation-erosion


def imageOpening(image, kernel, iterations):
    erosion = imageErosion(image, kernel, 1)
    return imageDilation(erosion, kernel, 1)
    

def imageClosing(image, kernel, iterations):
    dilation = imageDilation(image, kernel, 1)
    return imageErosion(dilation, kernel, 1)
    


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path + roadImage_03

roadGray = imageRead(openPath, cv2.IMREAD_GRAYSCALE)
roadGray_Threshold = imageThreshold(roadGray, 128, 255, cv2.THRESH_BINARY)
kernel = np.array([[1, 1, 1],
                   [1, 1, 1],
                   [1, 1, 1]], np.uint8)
roadGray_Dilation = imageDilation(roadGray_Threshold, kernel, 1)
roadGray_Erosion = imageErosion(roadGray_Threshold, kernel, 1)
roadGray_Opening = imageOpening(roadGray_Threshold, kernel, 1)
roadGray_Closing = imageClosing(roadGray_Threshold, kernel, 1)
roadGray_Gradient = imageMorphologicalGradient(roadGray_Threshold)

imageShow("roadGray", roadGray)
imageShow("roadGray_Threshold", roadGray_Threshold)
imageShow("roadGray_Dilation", roadGray_Dilation)
imageShow("roadGray_Erosion", roadGray_Erosion)
imageShow("roadGray_Opening", roadGray_Opening)
imageShow("roadGray_Closing", roadGray_Closing)
imageShow("roadGray_Gradient", roadGray_Gradient)

cv2.destroyAllWindows()
