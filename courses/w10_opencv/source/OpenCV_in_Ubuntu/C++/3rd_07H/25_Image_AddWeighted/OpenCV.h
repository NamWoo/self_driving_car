#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat imageRead(string openPath, int flag = IMREAD_UNCHANGED);
void imageShow(string imageName, Mat &image, int flag = WINDOW_GUI_EXPANDED);
void imageWrite(string imageName, Mat &image);
void Video(string openPath, string savePath=string());
void frameProcessing(Mat &frame, Mat &result);
vector<int> imageParameters(string imagename,Mat &image);
int getPixel(Mat &image, int x, int y, int c = 0);
void setPixel(Mat &image, int x, int y, int value, int c = 0);
Mat imageCopy(Mat &image);
void CutRectROI(Mat &image, Mat &result, Point pt1, Point pt2);
void PasteRectROI(Mat &image, Mat &result, Point pt1, Point pt2);
void polyROI(Mat &image, Mat &result, vector<Point> points);
void splitImage(Mat &image, vector<Mat> &channels);
void mergeImage(vector<Mat> &channels, Mat &image);
void mergeImage(Mat &ch1, Mat &ch2, Mat &ch3, Mat &image);
void convertColor(Mat &image, Mat &result, int flag=COLOR_BGR2GRAY);
void rangeColor(Mat &image, Mat &result, Scalar &min, Scalar &max);
void splitColor(Mat &image, Mat &result, Scalar &min, Scalar &max, int flag=COLOR_BGR2GRAY);
void drawLine(Mat &image, Mat &result, Point pt1, Point pt2, Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawRect(Mat &image, Mat &result, Point pt1, Point pt2, Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawRect(Mat &image, Mat &result, Rect rect, Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawCircle(Mat &image, Mat &result, Point center, int radius,  Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawEllipse(Mat &image, Mat &result, Point center, Size axis, double angle, double startAngle, double endAngle, Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawPolygon(Mat &image, Mat &result, vector<Point> points, bool isClosed, Scalar color = Scalar(255, 0, 0), int thickness = 5);
void drawText(Mat& image, Mat &result, const string& text, Point point = Point(10, 10), int font = FONT_HERSHEY_PLAIN, double fontScale = 2.0, Scalar color = Scalar(255, 255, 255), int thickness = 5);
void addImage(Mat &image1, Mat &image2, Mat &result); 
void addWeightedImage(Mat &image1, Mat &image2, Mat &result, double w1, double w2 = -1);
