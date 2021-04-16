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


def computeHist(image, mask=None):
    bins = np.arange(256).reshape(256,1)
    if len(image.shape)==2:
        h = np.zeros((300,256,1))
        hist_item = cv2.calcHist([image],[0],None,[256],[0,255]) 
        cv2.normalize(hist_item,hist_item,0,255,cv2.NORM_MINMAX) 
        hist=np.int32(np.around(hist_item)) 
        pts = np.column_stack((bins,hist)) 
        cv2.polylines(h,[pts],False, 255)
    else:
        h = np.zeros((300,256,3))
        color = [ (255,0,0),(0,255,0),(0,0,255) ] 
        for ch, col in enumerate(color): 
            hist_item = cv2.calcHist([image],[ch],None,[256],[0,255]) 
            cv2.normalize(hist_item,hist_item,0,255,cv2.NORM_MINMAX) 
            hist=np.int32(np.around(hist_item)) 
            pts = np.column_stack((bins,hist)) 
            cv2.polylines(h,[pts],False,col)
    return np.flipud(h)
            
    

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

roadColorHist = computeHist(roadColor)
imageShow("roadColorHist", roadColorHist)

roadGray = convertColor(roadColor, cv2.COLOR_BGR2GRAY)
imageShow("roadGray", roadGray)

roadGrayHist = computeHist(roadGray)
imageShow("roadGrayHist", roadGrayHist)


