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


def imageFiltering(image, kernel, ddepth=-1):
    return cv2.filter2D(image, ddepth, kernel)


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

high_pass_kernel = 1. / 9. * np.array([[-1, -1, -1],
                                       [-1, 8, -1],
                                       [-1, -1, -1]], np.float32)

roadColor_high_pass_kernel = imageFiltering(roadColor, high_pass_kernel)
imageShow("roadColor_high_pass_kernel", roadColor_high_pass_kernel)

laplacian_kernel_01 = np.array([[0, -1, 0],
                                [-1, 5, -1],
                                [0, -1, 0]], np.float32)

roadColor_laplacian_kernel_01 = imageFiltering(roadColor, laplacian_kernel_01)
imageShow("roadColor_laplacian_kernel_01", roadColor_laplacian_kernel_01)

laplacian_kernel_02 = np.array([[1, -2, 1],
                                [-2, 5, -2],
                                [1, -2, 1]], np.float32)

roadColor_laplacian_kernel_02 = imageFiltering(roadColor, laplacian_kernel_02)
imageShow("roadColor_laplacian_kernel_02", roadColor_laplacian_kernel_02)

cv2.destroyAllWindows()
