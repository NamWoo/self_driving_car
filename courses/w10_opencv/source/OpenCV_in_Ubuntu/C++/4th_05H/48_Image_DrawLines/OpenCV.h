#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#define PI 3.1415926
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
void imageThreshold(Mat &image, Mat &result, double thresh=128, double maxval = 255, int type = THRESH_BINARY);
void imageBlur(Mat &image, Mat &result, int ksize=2.0);
void imageGaussianBlur(Mat &image, Mat &result, int ksize=2.0, double sigmaX=2.0, double sigmaY=0.0);
void imageMedianBlur(Mat &image, Mat &result, int ksize=2.0);
void imageBilateralFilter(Mat &image, Mat &result, int ksize=2.0, double sigmaColor=2.0, double sigmaSpace=2.0);
void imageFiltering(Mat &image, Mat &result, Mat &kernel, int ddepth = -1);
void imageEdgePrewitt(Mat &image, Mat &result);
void imageEdgeSobel(Mat &image, Mat &result);
void imageEdgeScharr(Mat &image, Mat &result);
void imageEdgeLaplacianCV(Mat &image, Mat &result);
void imageEdgeLaplacianFilter2D(Mat &image, Mat &result);
void imageEdgeLoG(Mat &image, Mat &result);
void cannyEdge(Mat &image, Mat &result, double threshold1=100, double threshold2=200);
void computeHist(Mat &image, Mat &result);
void histogramEqualize(Mat &image, Mat &result);
void imageDilation(Mat &image, Mat &result, Mat &kernel, int iterations = 1);
void imageErosion(Mat &image, Mat &result, Mat &kernel, int iterations = 1);
void imageMorphologicalGradient(Mat &image, Mat &result);
void imageOpening(Mat &image, Mat &result, Mat &kernel, int iterations = 1);
void imageClosing(Mat &image, Mat &result, Mat &kernel, int iterations = 1);
void imageMorphologyKernel(Mat &result, int shape = MORPH_RECT, int size = 5);
void imageMorphologyEx(Mat &image, Mat &result, int op, Mat &kernel, int iterations = 1);
void imageResize(Mat &image, Mat &result, Size dsize, double fx=0.0, double fy=0.0, int interpolation = INTER_LINEAR);
void imageTranslation(Mat &image, Mat &result, Size size, double dx=0.0, double dy=0.0, int interpolation = INTER_LINEAR);
void imageRotation(Mat &image, Mat &result, Point center, double angle = 0.0, double scale = 1.0, Size size = Size(), int interpolation = INTER_LINEAR);
void imageAffineTransformation(Mat &image, Mat &result, vector<Point> src_pts, vector<Point> dst_pts, Size size, int  interpolation = INTER_LINEAR);
void imagePerspectiveTransformation(Mat &image, Mat &result, vector<Point> src_pts, vector<Point> dst_pts, Size size, int  interpolation = INTER_LINEAR);
void imageHoughLines(Mat &image, vector<Vec2f> &lines, double rho = 1.0, double theta = PI/180.0, int threshold = 100);
void drawHoughLines(Mat &result, vector<Vec2f> &lines, double theta1 = 70.*PI/180., double theta2 = 110.*PI/180., Scalar color = Scalar(0, 0, 255), int thickness = 5);
void imageHoughLinesP(Mat &image, vector<Vec4i> &lines, double rho = 1.0, double theta = PI/180.0, int threshold = 100, double minLineLength = 10.0, double maxLineGap = 100.0);
void drawHoughLinesP(Mat &result, vector<Vec4i> &lines, Scalar color = Scalar(0, 0, 255), int thickness = 5);
void splitLines(vector<Vec4i> &lines, vector<vector<Point> > &points);
bool comp(Point a, Point b);
void medianPoint(vector<Point> &points, Point &point);
void meanPoint(vector<Point> &points, Point &point);
void interpolate(Point &pt1, Point &pt2, Point &pt);
void linefitting(Mat &image, Mat &result, vector<vector<Point> > &points);
