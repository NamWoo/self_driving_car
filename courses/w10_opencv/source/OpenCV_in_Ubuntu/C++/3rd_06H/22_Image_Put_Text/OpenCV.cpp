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
	string openPath = imagepath + roadImage_01;
	
	Mat roadColor = imageRead(openPath, IMREAD_COLOR);
	imageShow("roadColor", roadColor);
	
	Mat roadColor_Text_01, roadColor_Text_02;
	drawText(roadColor, roadColor_Text_01, "OpenCV Image Processing", Point(10, 50), FONT_HERSHEY_PLAIN, 2.5, Scalar(255, 0, 0), 3);
    drawCircle(roadColor_Text_01, roadColor_Text_01, Point(10, 50), 5, Scalar(0, 0, 255), -1);
	imageShow("roadColor_Text_01", roadColor_Text_01);
    
	drawText(roadColor, roadColor_Text_02 , "FONT_HERSHEY_SIMPLEX", Point(10, 50), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_PLAIN", Point(10, 100), FONT_HERSHEY_PLAIN, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_DUPLEX", Point(10, 150), FONT_HERSHEY_DUPLEX, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_COMPLEX", Point(10, 200), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_TRIPLEX", Point(10, 250), FONT_HERSHEY_TRIPLEX, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_COMPLEX_SMALL", Point(10, 300), FONT_HERSHEY_COMPLEX_SMALL, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_SCRIPT_SIMPLEX", Point(10, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, Scalar(255, 0, 0), 1);
	drawText(roadColor_Text_02, roadColor_Text_02 , "FONT_HERSHEY_SCRIPT_COMPLEX", Point(10, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1.0, Scalar(255, 0, 0), 1);
	imageShow("roadColor_Text_02", roadColor_Text_02);
	
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
Mat imageCopy(Mat &image) {
    Mat result;
    image.copyTo(result);
    return result;
}
void CutRectROI(Mat &image, Mat &result, Point pt1, Point pt2) {
    result = image(Rect(pt1, pt2));
    return;
}
void PasteRectROI(Mat &image, Mat &result, Point pt1, Point pt2) {
    Mat dstROI(result, Rect(pt1, pt2));
    image.copyTo(dstROI);
    return;
}
void polyROI(Mat &image, Mat &result, vector<Point> points) {
    result = Mat::zeros(image.rows, image.cols, image.type());
    vector<vector<Point> > fillContAll;
    fillContAll.push_back(points);
    fillPoly(result, fillContAll, Scalar(255, 255, 255));
    bitwise_and(result, image, result);
    return;
}
void splitImage(Mat &image, vector<Mat> &channels) {
    split(image, channels);
    return;
}
void mergeImage(vector<Mat> &channels, Mat &image) {
    merge(channels, image);
    return;
}
void mergeImage(Mat &ch1, Mat &ch2, Mat &ch3, Mat &image) {
    vector<Mat> channels;
	channels.push_back(ch1);
	channels.push_back(ch2);
	channels.push_back(ch3);
	mergeImage(channels, image);
	return;
}
void convertColor(Mat &image, Mat &result, int flag) {
    cvtColor(image, result, flag);
    return;
}
void rangeColor(Mat &image, Mat &result, Scalar &min, Scalar &max) {
    inRange(image, min, max, result);
    return;
}
void splitColor(Mat &image, Mat &result, Scalar &min, Scalar &max, int flag) {
    Mat mask;
    convertColor(image, mask, flag);
    rangeColor(mask, mask, min, max);
    bitwise_and(image, image, result, mask);
    return;
}
void drawLine(Mat &image, Mat &result, Point pt1, Point pt2, Scalar color, int thickness) {
    result = imageCopy(image);
    line(result, pt1, pt2, color, thickness);
    return;
}
void drawRect(Mat &image, Mat &result, Point pt1, Point pt2, Scalar color, int thickness) {
    result = imageCopy(image);
    rectangle(result, pt1, pt2, color, thickness);
    return;
}
void drawRect(Mat &image, Mat &result, Rect rect, Scalar color, int thickness) {
    result = imageCopy(image);
    rectangle(result, rect, color, thickness);
    return;
}
void drawCircle(Mat &image, Mat &result, Point center, int radius,  Scalar color, int thickness) {
    result = imageCopy(image);
    circle(result, center, radius, color, thickness);
    return;
}
void drawEllipse(Mat &image, Mat &result, Point center, Size axis, double angle, double startAngle, double endAngle, Scalar color, int thickness) {
    result = imageCopy(image);
    ellipse(result, center, axis, angle, startAngle, endAngle, color, thickness);
    return;
}
void drawPolygon(Mat &image, Mat &result, vector<Point> points, bool isClosed, Scalar color, int thickness) {
    result = imageCopy(image);
    const Point *pts = (const Point *)Mat(points).data;
    int npts = Mat(points).rows;
    polylines(result, &pts, &npts, 1, isClosed, color, thickness);
    return;
}

void drawText(Mat& image, Mat &result, const string& text, Point point, int font, double fontScale, Scalar color, int thickness) {
    result = imageCopy(image);
    putText(result, text, point, font, fontScale, color, thickness);
    return;
}
