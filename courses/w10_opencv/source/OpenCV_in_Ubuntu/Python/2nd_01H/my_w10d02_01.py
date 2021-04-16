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


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


# def computeHist(image, mask=None):
#     bins = np.arange(256).reshape(256, 1)
#     if len(image.shape) == 2:
#         h = np.zeros((300, 256, 1))
#         hist_item = cv2.calcHist([image], [0], None, [256], [0, 255])
#         cv2.normalize(hist_item, hist_item, 0, 255, cv2.NORM_MINMAX)
#         hist = np.int32(np.around(hist_item))
#         pts = np.column_stack((bins, hist))
#         cv2.polylines(h, [pts], False, 255)
#     else:
#         h = np.zeros((300, 256, 3))
#         color = [(255, 0, 0), (0, 255, 0), (0, 0, 255)]
#         for ch, col in enumerate(color):
#             hist_item = cv2.calcHist([image], [ch], None, [256], [0, 255])
#             cv2.normalize(hist_item, hist_item, 0, 255, cv2.NORM_MINMAX)
#             hist = np.int32(np.around(hist_item))
#             pts = np.column_stack((bins, hist))
#             cv2.polylines(h, [pts], False, col)
#     return np.flipud(h)


def splitImage(image):
    return cv2.split(image)


def mergeImage(channel1, channel2, channel3):
    return cv2.merge((channel1, channel2, channel3))


def equalizeHist(image):
    if len(image.shape) == 2:
        return cv2.equalizeHist(image)
    else:
        ch1, ch2, ch3 = splitImage(image)
        ch1_eq = equalizeHist(ch1)
        ch2_eq = equalizeHist(ch2)
        ch3_eq = equalizeHist(ch3)
        return mergeImage(ch1_eq, ch2_eq, ch3_eq)


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/"
roadImage_01 = "Lenna.png"
openPath = path + roadImage_01

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
# roadColorHist = computeHist(roadColor)
# roadBGR_Equalize = equalizeHist(roadColor)
# roadColorHist_Equalize = computeHist(roadBGR_Equalize)

roadHLS = convertColor(roadColor, cv2.COLOR_BGR2HLS)
h, l, s = splitImage(roadHLS)
l_eq = equalizeHist(l)
s_eq = equalizeHist(s)
# roadHSVE = mergeImage(h, l, v_eq)
roadHLESE = mergeImage(h, l_eq, s_eq)
roadHSVE_BGR = convertColor(roadHLESE, cv2.COLOR_HLS2BGR)
# roadHSEVE_BGR = convertColor(roadHSEVE, cv2.COLOR_HSV2BGR)
imageShow("roadColor", roadColor)
imageShow("roadHSVE_BGR", roadHLESE)
imageShow("roadHSEVE_BGR", roadHSVE_BGR)     

out.write(roadHSVE_BGR)
out.release()



cv2.destroyAllWindows()
