#include "OpenCV.h"

using namespace std;
using namespace cv;

string imagepath = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/";
string roadImage_01 = "solidWhiteCurve.jpg";
string roadImage_02 = "Lenna.png";
string roadImage_03 = "solidYellowCurve.jpg";
string roadImage_04 = "solidYellowCurve2.jpg";
string roadImage_05 = "solidYellowLeft.jpg";
string roadImage_06 = "whiteCarLaneSwitch.jpg";

string videopath = "/home/nw/Desktop/OpenCV_in_Ubuntu/Data/Lane_Detection_Videos/";
string roadVideo_01 = "solidYellowLeft.mp4";
string roadVideo_02 = "solidWhiteRight.mp4";

int main(void) {
	string openPath = imagepath + roadImage_02;
	
	Mat roadColor = imageRead(openPath, IMREAD_COLOR);
	imageShow("roadColor", roadColor);
	
	int x = 230, y = 250;       //x 230~260, y 250~280,
	int pxvalue_b = getPixel(roadColor, x, y, 0);
	int pxvalue_g = getPixel(roadColor, x, y, 1);
	int pxvalue_r = getPixel(roadColor, x, y, 2);
	printf("Pixel value in %d, %d: b=%d, g=%d, r=%d\n", x, y, pxvalue_b, pxvalue_g, pxvalue_r);
	
	int i, j;
	// for ( i = x ; i < x+30 ; i++) {
	//     for ( j = y ; j < y+30 ; j++) {
	//         setPixel(roadColor, i, j, int((i-100)*1.7), 0);
	//         setPixel(roadColor, i, j, 0, 1);
	//         setPixel(roadColor, i, j, 0, 2);
	//     }
	// }
	// imageShow("roadColor", roadColor);
	
	for ( i = x ; i < x+30 ; i++) {
	    for ( j = y ; j < y+30 ; j++) {
	        setPixel(roadColor, i, j, 0, 0);
	        setPixel(roadColor, i, j, 0, 1); //int((i-100)*1.2)
	        setPixel(roadColor, i, j, 0, 2);
	    }
	}
	imageShow("roadColor", roadColor);
	
	for ( i = 0 ; i < roadColor.cols ; i++) {
	    setPixel(roadColor, i, y, 0, 0);
	    setPixel(roadColor, i, y, 0, 1);
	    setPixel(roadColor, i, y, 0, 2);
	}
	imageShow("roadColor", roadColor);
	
	for ( j = 0 ; j < roadColor.rows ; j++) {
	    setPixel(roadColor, x, j, 0, 0);
	    setPixel(roadColor, x, j, 0, 1);
	    setPixel(roadColor, x, j, 0, 2);
	}
	imageShow("roadColor", roadColor);
	
	
	pxvalue_b = getPixel(roadColor, x, y, 0);
	pxvalue_g = getPixel(roadColor, x, y, 1);
	pxvalue_r = getPixel(roadColor, x, y, 2);
	printf("Pixel value in %d, %d: b=%d, g=%d, r=%d\n", x, y, pxvalue_b, pxvalue_g, pxvalue_r);
	
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
void Video(string openPath, string savePath) {
    VideoCapture cap(openPath);
    if(!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return;
    }
    int fps = cap.get(CAP_PROP_FPS);
    VideoWriter out;
    if (!savePath.empty()) {
        int width = int(cap.get(CAP_PROP_FRAME_WIDTH));
        int height = int(cap.get(CAP_PROP_FRAME_HEIGHT));
        VideoWriter out(savePath.c_str(), CV_FOURCC('D','I','V','X'), fps, Size(width, height));
    }
    namedWindow("Input", WINDOW_GUI_EXPANDED);
    namedWindow("Output", WINDOW_GUI_EXPANDED);
    Mat frame, output;
    while (cap.isOpened()) {
        cap >> frame;
        if (frame.empty())
            break;
        frameProcessing(frame, output);
        if (!savePath.empty())
            out.write(output);
        imshow("Input", frame);
        imshow("Output", output);
        char c = (char)waitKey(int(1000.0/fps));
        if (c==27)
            break;
    }
    cap.release();
    if (!savePath.empty())
        out.release();
    destroyAllWindows();
}
void frameProcessing(Mat &frame, Mat &result) {
    cvtColor(frame, result, COLOR_RGB2GRAY);
    return;
}
vector<int> imageParameters(string imagename,Mat &image) {
    vector<int> Result;
    Size size = image.size();
    int width = image.cols;
    int height = image.rows;
    cout << imagename << ".size() is " << size<< endl;
    cout << imagename << ".rows is height: " << height<< endl;
    cout << imagename << ".cols is width: " << width<< endl;
    int channels = image.channels();
    if( channels == 1)
        cout << "This is grayscale image." << endl;
    else
        cout << "This is not grayscale image." << endl;
    cout << "height*width*channels is " << height*width*channels << endl;
    cout << imagename << ".type() is " << image.type()<< endl;
    Result.push_back(height);
    Result.push_back(width);
    Result.push_back(channels);
    return Result;
}
int getPixel(Mat &image, int x, int y, int c) {
    if( image.type() == CV_8UC1) {
        uchar* pointer = image.ptr<uchar>(y);
        return pointer[x];
    }
    else if( image.type() == CV_8UC3) {
        uchar* pointer = image.ptr<uchar>(y);
        return pointer[x*3+c];
    }
}
void setPixel(Mat &image, int x, int y, int value, int c) {
    if( image.type() == CV_8UC1) {
        uchar* pointer = image.ptr<uchar>(y);
        pointer[x] = value;
        return;
    }
    else if( image.type() == CV_8UC3) {
        uchar* pointer = image.ptr<uchar>(y);
        pointer[x*3+c]= value;
        return;;
    }
}
