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

openPath = path+roadImage_01

# roadColor = imageRead(openPath, cv2.IMREAD_COLOR)

# flag = cv2.IMREAD_UNCHANGED

a = cv2.imread(openPath, cv2.IMREAD_UNCHANGED)
cv2.namedWindow("roadColor", cv2.WINDOW_GUI_EXPANDED)
cv2.imshow("roadColor", a)
cv2.waitKey()



# roadGray = imageRead(openPath, cv2.IMREAD_GRAYSCALE)
# roadOrigin = imageRead(openPath, cv2.IMREAD_UNCHANGED)
# imageWrite(path+"roadGray.jpg", roadGray)

# imageShow("roadColor, cv2.WINDOW_NORMAL", roadColor, cv2.WINDOW_NORMAL)
# imageShow("roadColor, cv2.WINDOW_AUTOSIZE", roadColor, cv2.WINDOW_AUTOSIZE)
# imageShow("roadColor, cv2.WINDOW_FREERATIO", roadColor, cv2.WINDOW_FREERATIO)
# imageShow("roadColor, cv2.WINDOW_GUI_NORMAL", roadColor, cv2.WINDOW_GUI_NORMAL)
# imageShow("roadColor, cv2.WINDOW_GUI_EXPANDED", roadColor, cv2.WINDOW_GUI_EXPANDED)

cv2.destroyAllWindows()
