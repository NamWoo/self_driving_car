#include "OpenCV.h"

using namespace std;
using namespace cv;

string imagepath = "../../../Data/Lane_Detection_Images/";
string roadImage_01 = "solidWhiteCurve.jpg";
string roadImage_02 = "solidWhiteRight.jpg";
string roadImage_03 = "solidYellowCurve.jpg";
string roadImage_04 = "solidYellowCurve2.jpg";
string roadImage_05 = "solidYellowLeft.jpg";
string roadImage_06 = "whiteCarLaneSwitch.jpg";

string videopath = "../../../Data/Lane_Detection_Videos/";
string roadVideo_01 = "solidYellowLeft.mp4";
string roadVideo_02 = "solidWhiteRight.mp4";

int main(void) {
	string openPath = imagepath + roadImage_02;
    
    Mat roadColor = imageRead(openPath, IMREAD_COLOR);
    Mat roadGray = imageRead(openPath, IMREAD_GRAYSCALE);
    Mat roadOrigin = imageRead(openPath, IMREAD_UNCHANGED);
    imageWrite(path+"roadGray.jpg", roadGray);

	imageShow("roadColor, WINDOW_NORMAL", roadColor, WINDOW_NORMAL);
    imageShow("roadColor, WINDOW_AUTOSIZE", roadColor, WINDOW_AUTOSIZE);
    imageShow("roadColor, WINDOW_FREERATIO", roadColor, WINDOW_FREERATIO);
    imageShow("roadColor, WINDOW_GUI_NORMAL", roadColor, WINDOW_GUI_NORMAL);
    imageShow("roadColor, WINDOW_GUI_EXPANDED", roadColor, WINDOW_GUI_EXPANDED);

    imageShow("roadGray, WINDOW_NORMAL", roadGray, WINDOW_NORMAL);
    imageShow("roadGray, WINDOW_AUTOSIZE", roadGray, WINDOW_AUTOSIZE);
    imageShow("roadGray, WINDOW_FREERATIO", roadGray, WINDOW_FREERATIO);
    imageShow("roadGray, WINDOW_GUI_NORMAL", roadGray, WINDOW_GUI_NORMAL);
    imageShow("roadGray, WINDOW_GUI_EXPANDED", roadGray, WINDOW_GUI_EXPANDED);

    imageShow("roadOrigin, WINDOW_NORMAL", roadOrigin, WINDOW_NORMAL);
    imageShow("roadOrigin, WINDOW_AUTOSIZE", roadOrigin, WINDOW_AUTOSIZE);
    imageShow("roadOrigin, WINDOW_FREERATIO", roadOrigin, WINDOW_FREERATIO);
    imageShow("roadOrigin, WINDOW_GUI_NORMAL", roadOrigin, WINDOW_GUI_NORMAL);
    imageShow("roadOrigin, WINDOW_GUI_EXPANDED", roadOrigin, WINDOW_GUI_EXPANDED);

	destroyAllWindows();

	return 0;
}

Mat imageRead(string openPath, int flag) {
	Mat image = imread(openPath, flag);
	if(image.empty()) {
		cout<<"Image Not Opened"<<endl;
		cout<<"Program Abort"<<endl;
		exit(1);
	}
	else {
		cout<<"Image Opened"<<endl;
		return image;
	}
}
void imageShow(string imageName, Mat &image, int flag) {
	namedWindow(imageName, flag);
    imshow(imageName, image);
	waitKey();
	return;
}
void imageWrite(string imageName, Mat &image) {
    imwrite(imageName, image);
    return;
}
