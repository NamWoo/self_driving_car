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
    

def imageCopy(src):
    return np.copy(src)


def polyROI(image, points):
    if len(image.shape) == 2:
        channels = 1
    else:
        channels = image.shape[2]
    mask = np.zeros_like(image)
    ignore_mask_color = (255,) * channels
    cv2.fillPoly(mask, points, ignore_mask_color)
    return cv2.bitwise_and(image, mask)


def imagePerspectiveTransformation(image, src_pts, dst_pts, size=None, flags=cv2.INTER_LANCZOS4):
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
    M = cv2.getPerspectiveTransform(src_pts, dst_pts)
    return cv2.warpPerspective(image, M, dsize=size, flags=flags)


def convertColor(image, flag=None):
    if flag is None:
        return image
    else:
        return cv2.cvtColor(image, flag)


def cannyEdge(image, threshold1=100, threshold2=200):
    return cv2.Canny(image, threshold1, threshold2)


def addWeightedImage(image1, w1, imagw2, w2=None):
    if w2 is None:
        return cv2.addWeighted(image1, float(w1) * 0.01, imagw2, float(100 - w1) * 0.01, 0)
    else:
        return cv2.addWeighted(image1, w1 * 0.01, imagw2, w2 * 0.01, 0)


def houghLines(image, rho=1, theta=np.pi/180, threshold=100):
    return cv2.HoughLines(image, rho, theta, threshold)


def drawHoughLines(image, lines):
    result = imageCopy(image)
    if len(image.shape) == 2:
        result = convertColor(image, cv2.COLOR_GRAY2BGR)
    for i in range(len(lines)):
        for rho, theta in lines[i]:
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a * rho
            y0 = b * rho
            x1 = int(x0 + 1000 * (-b))
            y1 = int(y0 + 1000 * (a))
            x2 = int(x0 - 1000 * (-b))
            y2 = int(y0 - 1000 * (a))
            cv2.line(result, (x1, y1), (x2, y2), (0, 0, 255), 3)
    return result


path = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Images/"
roadImage_01 = "solidWhiteCurve.jpg"
roadImage_02 = "solidWhiteRight.jpg"
roadImage_03 = "solidYellowCurve.jpg"
roadImage_04 = "solidYellowCurve2.jpg"
roadImage_05 = "solidYellowLeft.jpg"
roadImage_06 = "whiteCarLaneSwitch.jpg"

openPath = path + roadImage_03

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
roadGray = convertColor(roadColor, cv2.COLOR_BGR2GRAY)
roadEdge = cannyEdge(roadGray, 100, 200)
height, width = roadColor.shape[:2]

pt1 = (width*0.45, height*0.65)
pt2 = (width*0.55, height*0.65)
pt3 = (width, height*1.0)
pt4 = (0, height*1.0)
roi_corners = np.array([[pt1, pt2, pt3, pt4]], dtype=np.int32)

roadROI = polyROI(roadEdge, roi_corners)
houghLines_01 = houghLines(roadROI, 1, np.pi/180, 40)
draw_houghLines_01 = drawHoughLines(roadColor, houghLines_01)

imageShow("roadEdge", roadEdge)
imageShow("roadROI", roadROI)
imageShow("draw_houghLines_01", draw_houghLines_01)

cv2.destroyAllWindows()

src_pt1 = [int(width*0.45), int(height*0.65)]
src_pt2 = [int(width*0.55), int(height*0.65)]
src_pt3 = [width, height]
src_pt4 = [0, height]
dst_pt1 = [int(width*0.1), 0]
dst_pt2 = [int(width*0.9), 0]
dst_pt3 = [int(width*0.9), height]
dst_pt4 = [int(width*0.1), height]

src_pts = np.float32([src_pt1, src_pt2, src_pt3, src_pt4])
dst_pts = np.float32([dst_pt1, dst_pt2, dst_pt3, dst_pt4])

roadAffine_01 = imagePerspectiveTransformation(roadEdge, src_pts, dst_pts)
houghLines_02 = houghLines(roadAffine_01, 1, np.pi/180, 250)
road = np.zeros((height, width), np.uint8)
draw_houghLines_02 = drawHoughLines(road, houghLines_02)
roadAffine_03 = imagePerspectiveTransformation(draw_houghLines_02, src_pts, dst_pts, flags=cv2.WARP_INVERSE_MAP)
roadResult = addWeightedImage(roadAffine_03, 100, roadColor, 100)

imageShow("roadEdge", roadEdge)
imageShow("roadAffine_01", roadAffine_01)
imageShow("draw_houghLines_02", draw_houghLines_02)
imageShow("roadAffine_03", roadAffine_03)
imageShow("roadResult", roadResult)

cv2.destroyAllWindows()
