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
    
    
def addImage(image1, image2):
    return cv2.add(image1, image2)


def imageFiltering(image, kernel, ddepth=-1):
    return cv2.filter2D(image, ddepth, kernel)
    

def imageEdgePrewitt(image):
    kernel_x = np.array([[-1, 0, 1],
                         [-1, 0, 1],
                         [-1, 0, 1]], np.float32)
    kernel_y = np.array([[-1, -1, -1],
                         [0, 0, 0],
                         [1, 1, 1]], np.float32)
    img_dx = imageFiltering(image, kernel_x)
    img_dy = imageFiltering(image, kernel_y)
    return img_dx + img_dy


def imageEdgeSobel(image):
    img_dx = cv2.Sobel(image, -1, 1, 0, ksize=3)
    img_dy = cv2.Sobel(image, -1, 0, 1, ksize=3)
    return img_dx + img_dy


def imageEdgeScharr(image):
    img_dx = cv2.Scharr(image, -1, 1, 0)
    img_dy = cv2.Scharr(image, -1, 0, 1)
    return img_dx + img_dy


def imageEdgeLaplacianCV(image):
    return cv2.Laplacian(image, -1)


def imageEdgeLaplacianFilter2D(image):
    kernel = np.array([[-1, -1, -1],
                       [-1, 8, -1],
                       [-1, -1, -1]], np.float32)
    return imageFiltering(image, kernel)


def imageEdgeLoG(image):
    kernel = np.array([[0, 0, -1, 0, 0],
                       [0, -1, -2, -1, 0],
                       [-1, -2, 16, -2, -1],
                       [0, -1, -2, -1, 0],
                       [0, 0, -1, 0, 0]], np.float32)
    return imageFiltering(image, kernel)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path+roadImage_03

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
imageShow("roadColor", roadColor)

roadColor_Prewitt = imageEdgePrewitt(roadColor)
imageShow("roadColor_Prewitt", roadColor_Prewitt)

roadColor_Sobel = imageEdgeSobel(roadColor)
imageShow("roadColor_Sobel", roadColor_Sobel)

roadColor_Scharr = imageEdgeScharr(roadColor)
imageShow("roadColor_Scharr", roadColor_Scharr)

roadColor_LaplacianCV = imageEdgeLaplacianCV(roadColor)
imageShow("roadColor_LaplacianCV", roadColor_LaplacianCV)

roadColor_LaplacianFilter = imageEdgeLaplacianFilter2D(roadColor)
imageShow("roadColor_LaplacianFilter", roadColor_LaplacianFilter)

roadColor_LoG = imageEdgeLoG(roadColor)
imageShow("roadColor_LoG", roadColor_LoG)

cv2.destroyAllWindows()
