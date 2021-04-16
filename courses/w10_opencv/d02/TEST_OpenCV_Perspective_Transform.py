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
    
    
def drawCircle(image, center, radius, color=(255, 0, 0), thickness=5, lineType=cv2.LINE_AA):
    result = imageCopy(image)
    return cv2.circle(result, center, radius, color, thickness, lineType)


def imagePerspectiveTransformation(image, src_pts, dst_pts, size=None, flags=cv2.INTER_LANCZOS4):
    if size is None:
        rows, cols = image.shape[:2]
        size = (cols, rows)
    M = cv2.getPerspectiveTransform(src_pts, dst_pts)
    return cv2.warpPerspective(image, M, dsize=size, flags=flags)
    


path = "../../Data/Lane_Detection_Images/test.png"
openPath = path

roadColor = imageRead(openPath, cv2.IMREAD_COLOR)
height, width = roadColor.shape[:2]

src_pt1 = [886,444]
src_pt2 = [908,444]
src_pt3 = [908,456]
src_pt4 = [886,456]

dst_pt1 = [int(width*0.4), int(height *0.4)]
dst_pt2 = [int(width*0.6), int(height *0.4)]
dst_pt3 = [int(width*0.6), int(height *0.6)]
dst_pt4 = [int(width*0.4), int(height *0.6)]

src_pts = np.float32([src_pt1, src_pt2, src_pt3, src_pt4])
dst_pts = np.float32([dst_pt1, dst_pt2, dst_pt3, dst_pt4])

roadPoint = drawCircle(roadColor, tuple(src_pt1), 1, (255, 0, 0), -1)
roadPoint = drawCircle(roadPoint, tuple(src_pt2), 1, (0, 255, 0), -1)
roadPoint = drawCircle(roadPoint, tuple(src_pt3), 1, (0, 0, 255), -1)
roadPoint = drawCircle(roadPoint, tuple(src_pt4), 1, (255, 255, 0), -1)

roadAffine_01 = imagePerspectiveTransformation(roadPoint, src_pts, dst_pts)
roadAffine_02 = imagePerspectiveTransformation(roadAffine_01, src_pts, dst_pts, flags=cv2.WARP_INVERSE_MAP)
roadAffine_03 = imagePerspectiveTransformation(roadAffine_01, dst_pts, src_pts)

imageShow("roadColor", roadColor)
imageShow("roadPoint", roadPoint)
imageShow("roadAffine_01", roadAffine_01)
imageShow("roadAffine_02", roadAffine_02)
imageShow("roadAffine_03", roadAffine_03)

cv2.destroyAllWindows()
