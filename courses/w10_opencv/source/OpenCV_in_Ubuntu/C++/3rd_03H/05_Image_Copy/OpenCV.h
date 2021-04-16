#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

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
