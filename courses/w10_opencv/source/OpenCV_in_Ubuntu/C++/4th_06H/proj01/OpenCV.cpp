#include "OpenCV.h"

using namespace std;
using namespace cv;

// /media/nw/NAMWOOOOO7/proj/OpenCV/Project_Images
// /media/nw/NAMWOOOOO7/proj/OpenCV/Project_Videos
string imagepath = "/home/nw/self_driving_car/courses/w10_opencv/source/OpenCV_in_Ubuntu/Data/Project_Images/";
string roadImage_01 = "ETS_C_01.jpg";
string roadImage_02 = "ETS_C_02.jpg";
string roadImage_03 = "ETS_H_01.jpg";
string roadImage_04 = "PC_C_01.jpg";
string roadImage_05 = "PC_C_02.jpg";
string roadImage_06 = "PC_F_01.jpg";
string roadImage_07 = "PC_F_02.jpg";
string roadImage_08 = "PC_H_01.jpg";
string roadImage_09 = "PC_H_02.jpg";
string roadImage_10 = "PC_T_01.jpg";
string roadImage_11 = "PC_T_02.jpg";
string videopath = "/home/nw/self_driving_car/courses/w10_opencv/source/OpenCV_in_Ubuntu/Data/Project_Videos/";
string roadVideo_01 = "ETS_C_01.mp4";
string roadVideo_02 = "ETS_H_01.mp4";
string roadVideo_03 = "PC_C_01.mp4";
string roadVideo_04 = "PC_C_02.mp4";
string roadVideo_05 = "PC_F_01.mp4";
string roadVideo_06 = "PC_H_01.mp4";
string roadVideo_07 = "PC_T_01.mp4";



// Mat imagesize_w(Mat &image) {
//     int width = image.cols;
//     return width;
// }

// Mat imagesize_w(Mat &image) {
//     int height = image.rows;
//     return height;
// }


Mat imageProcessing(Mat &image, vector<Point> pts) {
    Mat result;
    int width = image.cols;
	int height = image.rows;
    result = imageCopy(image);

    // printf("image size, width : %d, height : %d\n",width, height);
    //already optimized, it does not need 
    //split color
	// Scalar lower_white_hls(0, 200, 0);
	// Scalar upper_white_hls(179, 255, 255);
	// Scalar lower_yellow_hls(15, 30, 115);
	// Scalar upper_yellow_hls(35, 204, 255);
	
	// Mat output_white_hls, output_yellow_hls;
	// splitColor(result, output_white_hls, lower_white_hls, upper_white_hls, COLOR_BGR2HLS);
	// splitColor(result, output_yellow_hls, lower_yellow_hls, upper_yellow_hls, COLOR_BGR2HLS);
	// //Mat result = output_white_hls+output_yellow_hls;
	// result = output_white_hls+output_yellow_hls;
    // convertColor(result, result);
    //
    // histogramEqualize(result, result);

    //start
    convertColor(image, result);
    
    //morphology kernel
    Mat ELLIPSE;
    imageMorphologyKernel(ELLIPSE, MORPH_ELLIPSE, 3);

    //morphology ex
    imageMorphologyEx(result, result, MORPH_GRADIENT,ELLIPSE,1);

    //canny edge
    cannyEdge(result, result, 100, 200);

    //ROI
	Mat roadROI;
    // vector<Point> pts;
	polyROI(result, roadROI, pts);

    //Hough line
    vector<Vec4i> lines;
	imageHoughLinesP(roadROI, lines, 1.0, PI/180.0, 45);	
    convertColor(roadROI, roadROI, COLOR_GRAY2BGR);	
	drawHoughLinesP(roadROI, lines);	

    //merge
    convertColor(roadROI, roadROI);	

	imageThreshold(roadROI, roadROI, 1, 255, THRESH_BINARY);
    convertColor(roadROI, roadROI, COLOR_GRAY2BGR);	
	Mat temp;
    
    //all - black
	temp = image - roadROI;
    result = temp;
 
    //draw line
	Mat roadLines;
	vector<vector<Point> > points;  // gradient
	splitLines(lines, points);      //median y, 
	linefitting(result, result, points);

    return result;
}




void frameProcessing(Mat &frame, Mat &result, vector<Point> pts) {
    result = imageCopy(frame);
    int width = result.cols;
	int height = result.rows;





    //already optimized, it does not need 
    /* split color
	Scalar lower_white_hls(0, 200, 0);
	Scalar upper_white_hls(179, 255, 255);
	Scalar lower_yellow_hls(15, 30, 115);
	Scalar upper_yellow_hls(35, 204, 255);
	
	Mat output_white_hls, output_yellow_hls;
	splitColor(result, output_white_hls, lower_white_hls, upper_white_hls, COLOR_BGR2HLS);
	splitColor(result, output_yellow_hls, lower_yellow_hls, upper_yellow_hls, COLOR_BGR2HLS);
	//Mat result = output_white_hls+output_yellow_hls;
	result = output_white_hls+output_yellow_hls;
    convertColor(result, result);
    */

//start
    convertColor(result, result);
    
    //morphology kernel
    Mat ELLIPSE;
    imageMorphologyKernel(ELLIPSE, MORPH_ELLIPSE, 3);

    //morphology ex
    imageMorphologyEx(result, result, MORPH_GRADIENT,ELLIPSE,1);

    //canny edge
    cannyEdge(result, result, 100, 200);

    //ROI
	Mat roadROI;
    // vector<Point> pts;
	polyROI(result, roadROI, pts);

    //Hough line
    vector<Vec4i> lines;
	imageHoughLinesP(roadROI, lines, 1.0, PI/180.0, 45);	
    convertColor(roadROI, roadROI, COLOR_GRAY2BGR);	
	drawHoughLinesP(roadROI, lines);	

    //merge
    convertColor(roadROI, roadROI);	

	imageThreshold(roadROI, roadROI, 1, 255, THRESH_BINARY);
    convertColor(roadROI, roadROI, COLOR_GRAY2BGR);	
	Mat temp;
    
    //all - black
	temp = frame - roadROI;
    result = temp;
 
    //draw line
	Mat roadLines;
	vector<vector<Point> > points;  //gradient
	splitLines(lines, points);      //median y, 
	linefitting(result, result, points);

    return;
}


// void ready01(Mat &image) {
// (Mat &image, Mat &result, vector<vector<Point> > &points

//     return 0;
// }

int main(void) {
	// string openPath = videopath + roadVideo_01;
	// Video(openPath, "output_LaneDetection_Project.avi");


    Mat roadColor_01 = imageRead(imagepath + roadImage_01, IMREAD_COLOR);
	Mat roadColor_02 = imageRead(imagepath + roadImage_02, IMREAD_COLOR);
	// Mat roadColor_03 = imageRead(imagepath + roadImage_03, IMREAD_COLOR);
	Mat roadColor_04 = imageRead(imagepath + roadImage_04, IMREAD_COLOR);
	Mat roadColor_05 = imageRead(imagepath + roadImage_05, IMREAD_COLOR);
	Mat roadColor_06 = imageRead(imagepath + roadImage_06, IMREAD_COLOR);
    Mat roadColor_07 = imageRead(imagepath + roadImage_07, IMREAD_COLOR);
    Mat roadColor_08 = imageRead(imagepath + roadImage_08, IMREAD_COLOR);
    Mat roadColor_09 = imageRead(imagepath + roadImage_09, IMREAD_COLOR);
    Mat roadColor_10 = imageRead(imagepath + roadImage_10, IMREAD_COLOR);
    Mat roadColor_11 = imageRead(imagepath + roadImage_11, IMREAD_COLOR);

    vector<Point> pts;
    pts.push_back(Point(597,336));
    pts.push_back(Point(705,336));
    pts.push_back(Point(798,409));
    pts.push_back(Point(735,409));
    pts.push_back(Point(650,336));
    pts.push_back(Point(600,409));
    pts.push_back(Point(519,409));

    vector<Point> pts2;
    pts2.push_back(Point(617,336));
    pts2.push_back(Point(687,336));
    pts2.push_back(Point(798,409));
    pts2.push_back(Point(735,409));
    pts2.push_back(Point(650,336));
    pts2.push_back(Point(600,409));
    pts2.push_back(Point(519,409));

    // vector<Point> pts3;
    // pts3.push_back(Point(int(width * 0.35), int(height * 0.65)));
    // pts3.push_back(Point(int(width * 0.65), int(height * 0.65)));
    // pts3.push_back(Point(width, height));    //right conner
    // pts3.push_back(Point(int(width*0.7), height));
    // pts3.push_back(Point(int(width*0.55), int(height*0.65)));
    // pts3.push_back(Point(int(width*0.45), int(height*0.65)));
    // pts3.push_back(Point(int(width*0.3), height));
    // pts3.push_back(Point(0, height));        //left conner

    vector<Point> pts4;
    pts4.push_back(Point(350,326));
    pts4.push_back(Point(485,326));
    pts4.push_back(Point(613,367));
    pts4.push_back(Point(492,367));
    pts4.push_back(Point(420,326));
    pts4.push_back(Point(335,367));
    pts4.push_back(Point(262,367));

    vector<Point> pts5;
    pts5.push_back(Point(350,326));
    pts5.push_back(Point(485,326));
    pts5.push_back(Point(613,367));
    pts5.push_back(Point(492,367));
    pts5.push_back(Point(420,326));
    pts5.push_back(Point(335,367));
    pts5.push_back(Point(262,367));

    vector<Point> pts6;
    pts6.push_back(Point(307,302));
    pts6.push_back(Point(517,302));
    pts6.push_back(Point(785,369));
    pts6.push_back(Point(642,369));
    pts6.push_back(Point(405,302));
    pts6.push_back(Point(222,369));
    pts6.push_back(Point(79,369));

    vector<Point> pts7;
    pts7.push_back(Point(307,302));
    pts7.push_back(Point(517,302));
    pts7.push_back(Point(785,369));
    pts7.push_back(Point(642,369));
    pts7.push_back(Point(405,302));
    pts7.push_back(Point(222,369));
    pts7.push_back(Point(79,369));

    vector<Point> pts8;
    pts8.push_back(Point(350,254));
    pts8.push_back(Point(500,254));
    pts8.push_back(Point(792,357));
    pts8.push_back(Point(627,357));
    pts8.push_back(Point(425,254));
    pts8.push_back(Point(233,357));
    pts8.push_back(Point(56,357));

    vector<Point> pts9;
    pts9.push_back(Point(350,254));
    pts9.push_back(Point(500,254));
    pts9.push_back(Point(792,357));
    pts9.push_back(Point(627,357));
    pts9.push_back(Point(425,254));
    pts9.push_back(Point(233,357));
    pts9.push_back(Point(56,357));

    vector<Point> pts10;
    pts10.push_back(Point(278,285));
    pts10.push_back(Point(465,285));
    pts10.push_back(Point(782,415));
    pts10.push_back(Point(606,415));
    pts10.push_back(Point(374,285));
    pts10.push_back(Point(190,415));
    pts10.push_back(Point(32,415));

    vector<Point> pts11;
    pts11.push_back(Point(278,285));
    pts11.push_back(Point(465,285));
    pts11.push_back(Point(782,415));
    pts11.push_back(Point(606,415));
    pts11.push_back(Point(374,285));
    pts11.push_back(Point(190,415));
    pts11.push_back(Point(32,415));

	Mat roadResult_01 = imageProcessing(roadColor_01, pts);
    imageShow("roadColor_01", roadColor_01);
    imageShow("roadResult_01", roadResult_01);
    
	Mat roadResult_02 = imageProcessing(roadColor_02, pts2);
    imageShow("roadColor_02", roadColor_02);
    imageShow("roadResult_02", roadResult_02);
    
	// Mat roadResult_03 = imageProcessing(roadColor_03, pts3);
    // imageShow("roadColor_03", roadColor_03);
    // imageShow("roadResult_03", roadResult_03);
    
	Mat roadResult_04 = imageProcessing(roadColor_04, pts4);
    imageShow("roadColor_04", roadColor_04);
    imageShow("roadResult_04", roadResult_04);
    
	Mat roadResult_05 = imageProcessing(roadColor_05, pts5);
    imageShow("roadColor_05", roadColor_05);
    imageShow("roadResult_05", roadResult_05);
    
	Mat roadResult_06 = imageProcessing(roadColor_06, pts6);
    imageShow("roadColor_06", roadColor_06);
    imageShow("roadResult_06", roadResult_06);
	
	Mat roadResult_07 = imageProcessing(roadColor_07, pts7);
    imageShow("roadColor_07", roadColor_07);
    imageShow("roadResult_07", roadResult_07);

    Mat roadResult_08 = imageProcessing(roadColor_08, pts8);
    imageShow("roadColor_08", roadColor_08);
    imageShow("roadResult_08", roadResult_08);

    Mat roadResult_09 = imageProcessing(roadColor_09, pts9);
    imageShow("roadColor_09", roadColor_09);
    imageShow("roadResult_09", roadResult_09);

    Mat roadResult_10 = imageProcessing(roadColor_10, pts10);
    imageShow("roadColor_10", roadColor_10);
    imageShow("roadResult_10", roadResult_10);

    Mat roadResult_11 = imageProcessing(roadColor_11, pts11);
    imageShow("roadColor_11", roadColor_11);
    imageShow("roadResult_11", roadResult_11);

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
    vector<Point> pts;

    while (cap.isOpened()) {
        cap >> frame;
        if (frame.empty())
            break;
        frameProcessing(frame, output, pts);
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
void addImage(Mat &image1, Mat &image2, Mat &result) {
    add(image1, image2, result);
}
void addWeightedImage(Mat &image1, Mat &image2, Mat &result, double w1, double w2) {
    result = imageCopy(image1);
    if( w2 == -1) {
        addWeighted(image1, w1*0.01, image2, (100.0-w1)*0.01,0, result);
    }
    else {
        addWeighted(image1, w1*0.01, image2, w2*0.01, 0, result);
    }
    return;
}
void imageThreshold(Mat &image, Mat &result, double thresh, double maxval, int type) {
    threshold(image, result, thresh, maxval, type);
    return;
}
void imageBlur(Mat &image, Mat &result, int ksize) {
    Size kernelSize(ksize*2-1, ksize*2-1);
    blur(image, result, kernelSize);
    return;
}
void imageGaussianBlur(Mat &image, Mat &result, int ksize, double sigmaX, double sigmaY) {
    Size kernelSize(ksize*2-1, ksize*2-1);
    GaussianBlur(image, result, kernelSize, sigmaX, sigmaY);
    return;
}
void imageMedianBlur(Mat &image, Mat &result, int ksize) {
    medianBlur(image, result, ksize*2-1);
    return;
}
void imageBilateralFilter(Mat &image, Mat &result, int ksize, double sigmaColor, double sigmaSpace) {
    bilateralFilter(image, result, ksize*2-1, sigmaColor, sigmaSpace);
    return;
}
void imageFiltering(Mat &image, Mat &result, Mat &kernel, int ddepth) {
    filter2D(image, result, ddepth, kernel);
    return;
}
void imageEdgePrewitt(Mat &image, Mat &result) {
    float kernel_x[] = {-1, 0, 1,
                        -1, 0, 1,
                        -1, 0, 1};
	Mat kernelx(3, 3, CV_32F,kernel_x);
	float kernel_y[] = {-1, -1, -1,
	                    0, 0, 0,
	                    1, 1, 1};
	Mat kernely(3, 3, CV_32F,kernel_y);
	Mat dx, dy;
	imageFiltering(image, dx, kernelx);
	imageFiltering(image, dy, kernely);
	result = dx+dy;
	return;
}
void imageEdgeSobel(Mat &image, Mat &result) {
    Mat dx, dy;
    Sobel(image, dx, -1, 1, 0, 3);
    Sobel(image, dy, -1, 0, 1, 3);
	result = dx+dy;
	return;
}
void imageEdgeScharr(Mat &image, Mat &result) {
    Mat dx, dy;
    Scharr(image, dx, -1, 1, 0);
    Scharr(image, dy, -1, 0, 1);
	result = dx+dy;
	return;
}
void imageEdgeLaplacianCV(Mat &image, Mat &result) {
    Laplacian(image, result, -1, 1);
	return;
}
void imageEdgeLaplacianFilter2D(Mat &image, Mat &result) {
    float kernel_[] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
	Mat kernel(3, 3, CV_32F,kernel_);
	imageFiltering(image, result, kernel);
	return;
}
void imageEdgeLoG(Mat &image, Mat &result) {
    float kernel_[] = {0, 0, -1, 0, 0, 0, -1, -2, -1, 0, -1, -2, 16, -2, -1, 0, -1, -2, -1, 0, 0, 0, -1, 0, 0};
	Mat kernel(5, 5, CV_32F,kernel_);
	imageFiltering(image, result, kernel);
	return;
}
void cannyEdge(Mat &image, Mat &result, double threshold1, double threshold2) {
    Canny(image, result, threshold1, threshold2);
    return;
}
void computeHist(Mat &image, Mat &result) {
    Mat histogram;
    if( image.channels() == 1) {
        int histSize = 256;
	    float range[] = { 0, 256 };
	    const float* histRange = { range };
	    calcHist(&image, 1, 0, Mat(), histogram, 1, &histSize, &histRange);
	    int hist_w = 256; 
	    int hist_h = 300;
	    int bin_w = cvRound((double)hist_w / (double)histSize);
	    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	    for (int i = 1; i < histSize; i++) {
		    line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(histogram.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(histogram.at<float>(i))), 255, 2, 8, 0);
	    }
	    result = imageCopy(histImage);
	    return;
	}
    else {
        vector<Mat> channels;
        splitImage(image, channels);
        int i;
        for ( i=0 ; i < 3 ; i++)
            computeHist(channels[i], channels[i]);
        mergeImage(channels, result);
        return;
    }
}
void histogramEqualize(Mat &image, Mat &result) {
    if( image.channels() == 1) {
        equalizeHist(image, result);
	    return;
	}
    else {
        vector<Mat> channels;
        splitImage(image, channels);
        int i;
        for ( i=0 ; i < 3 ; i++)
            histogramEqualize(channels[i], channels[i]);
        mergeImage(channels, result);
        return;
    }
}
void imageDilation(Mat &image, Mat &result, Mat &kernel, int iterations) {
    dilate(image, result, kernel, Point(), iterations);
    return;
}
void imageErosion(Mat &image, Mat &result, Mat &kernel, int iterations) {
    erode(image, result, kernel, Point(), iterations);
    return;
}
void imageMorphologicalGradient(Mat &image, Mat &result) {
    float kernel_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	Mat kernel(3, 3, CV_32F,kernel_);
    Mat dilation, erosion;
    imageDilation(image, dilation, kernel);
    imageErosion(image, erosion, kernel);
    result = dilation-erosion;
    return;
}
void imageOpening(Mat &image, Mat &result, Mat &kernel, int iterations) {
    imageErosion(image, result, kernel, iterations);
    imageDilation(result, result, kernel, iterations);
    return;
}
void imageClosing(Mat &image, Mat &result, Mat &kernel, int iterations) {
    imageDilation(image, result, kernel, iterations);
    imageErosion(result, result, kernel, iterations);
    return;
}
void imageMorphologyKernel(Mat &result, int shape, int size) {
    result = getStructuringElement(shape, Size(size, size));
    return;
}
void imageMorphologyEx(Mat &image, Mat &result, int op, Mat &kernel, int iterations) {
    morphologyEx(image, result, op, kernel, Point(), iterations);
    return;
}
void imageResize(Mat &image, Mat &result, Size dsize, double fx, double fy, int interpolation) {
    resize(image, result, dsize, fx, fy, interpolation);
    return;
}
void imageTranslation(Mat &image, Mat &result, Size size, double dx, double dy, int interpolation) {
    Mat M = (Mat_<float>(2,3) << 1, 0, dx, 0, 1, dy);
    warpAffine(image, result, M, size, interpolation);
    return;
}
void imageRotation(Mat &image, Mat &result, Point center, double angle, double scale, Size size, int interpolation) {
    Mat M = getRotationMatrix2D(center, angle, scale);
    warpAffine(image, result, M, size, interpolation);
    return;
}
void imageAffineTransformation(Mat &image, Mat &result, vector<Point> src_pts, vector<Point> dst_pts, Size size, int  interpolation) {
    Point2f srcTri[3], dstTri[3];
    int i;
    for ( i=0 ; i<3; i++) {
        srcTri[i] = src_pts[i];
        dstTri[i] = dst_pts[i];
    }
    Mat M = getAffineTransform(srcTri, dstTri);
    warpAffine(image, result, M, size, interpolation);
    return;
}
void imagePerspectiveTransformation(Mat &image, Mat &result, vector<Point> src_pts, vector<Point> dst_pts, Size size, int  interpolation) {
    Point2f srcTri[4], dstTri[4];
    int i;
    for ( i=0 ; i<4; i++) {
        srcTri[i] = src_pts[i];
        dstTri[i] = dst_pts[i];
    }
    Mat M = getPerspectiveTransform(srcTri, dstTri);
    warpPerspective(image, result, M, size, interpolation);
    return;
}
void imageHoughLines(Mat &image, vector<Vec2f> &lines, double rho, double theta, int threshold) {
    HoughLines(image, lines, rho, theta, threshold);
    return;
}
void drawHoughLines(Mat &result, vector<Vec2f> &lines, double theta1, double theta2, Scalar color, int thickness) {
    std::vector<cv::Vec2f>::const_iterator it= lines.begin();
    while (it!=lines.end()) {
        float rho = (*it)[0];
        float theta = (*it)[1];
        if (theta < theta1 || theta > theta2) {
            Point pt1(rho/cos(theta), 0); 
            Point pt2((rho-result.rows*sin(theta))/cos(theta), result.rows);
            line(result, pt1, pt2, color, thickness);
        }
	    ++it;
	}
	return;
}
void imageHoughLinesP(Mat &image, vector<Vec4i> &lines, double rho, double theta, int threshold, double minLineLength, double maxLineGap) {
    lines.clear();
    HoughLinesP(image,lines,rho,theta,threshold, minLineLength, maxLineGap);
    return;
}
void drawHoughLinesP(Mat &result, vector<Vec4i> &lines, Scalar color, int thickness) {
 	vector<Vec4i>::const_iterator it= lines.begin();
    while (it!=lines.end()) {
        Point pt1((*it)[0],(*it)[1]);
        Point pt2((*it)[2],(*it)[3]);
        line( result, pt1, pt2, color, thickness);
        ++it;
    }
  	return;
}
void splitLines(vector<Vec4i> &lines, vector<vector<Point> > &points) {
    vector<Point> left_x, left_y, right_x, right_y;
    int i;
    for( i = 0 ; i < lines.size() ; i++ ){
        Vec4i l = lines[i];
        int x1, y1, x2, y2;
        x1 = l[0];
        y1 = l[1];
        x2 = l[2];
        y2 = l[3];
        double slope = (double)(y2-y1)/(double)(x2-x1);
        if (abs(slope) < 0 ) {    //0.5
            continue;
        }
        if ( slope <= 0 ) {
            left_x.push_back(Point(x1, x2));
            left_y.push_back(Point(y1, y2));
        }
        else {
            right_x.push_back(Point(x1, x2));
            right_y.push_back(Point(y1, y2));
        }
    }
    points.clear();
    points.push_back(left_x);
    points.push_back(left_y);
    points.push_back(right_x);
    points.push_back(right_y);
    return;
}
bool comp(Point a, Point b) {
    return (a.x>b.x);
}
void medianPoint(vector<Point> &points, Point &point) {
    size_t size = points.size();
    sort(points.begin(), points.end(), comp);
    point = points[(int)(size/2)];
    return;
}
void meanPoint(vector<Point> &points, Point &point) {
    int sum1 = 0;
    int sum2 = 0;
    int temp = 0;
    for (temp = 0 ; temp < points.size();temp++) {
        sum1 += points[temp].x;
        sum2 += points[temp].y;
    }
    int p_1 = (double)sum1/(double)temp;
    int p_2 = (double)sum2/(double)temp;
    point = Point(p_1, p_2);
    return;
}
void interpolate(Point &pt1, Point &pt2, int y, Point &pt) {
    int x1 = pt1.x;
    int x2 = pt1.y;
    int y1 = pt2.x;
    int y2 = pt2.y;
    int x = float(y - y1) * float(x2-x1) / float(y2-y1) + x1;
    pt.x = x;
    pt.y = y;
    return;
}
void linefitting(Mat &image, Mat &result, vector<vector<Point> > &points) {
    result = imageCopy(image);
    Point lx, ly, rx, ry;
    meanPoint(points[0], lx);
    meanPoint(points[1], ly);
    meanPoint(points[2], rx);
    meanPoint(points[3], ry);
    int min_y = image.rows * 0.5;
    int max_y = image.rows;
    Point left_min, left_max, right_min, right_max;
    interpolate(lx, ly, min_y, left_min);
    interpolate(lx, ly, max_y, left_max);
    interpolate(rx, ry, min_y, right_min);
    interpolate(rx, ry, max_y, right_max);
    //my    
    // printf("lx, ly, rx, ry = %d, %d, %d, %d //", left_min.x, left_min.y, right_min.x, right_min.y);
    // line(result, Point(int((right_min.x + left_min.x)*0.5), min_y), Point(int((right_max.x + left_max.x)*0.5), max_y), Scalar(255, 0, 0), 50);
    //
    line(result, left_min, left_max, Scalar(0, 0, 255), 3);
    line(result, right_min, right_max, Scalar(0, 0, 255), 3);
    
    vector<Point> center_points;
	center_points.push_back(Point(left_min));
	center_points.push_back(Point(left_max));
	center_points.push_back(Point(right_max));
    center_points.push_back(Point(right_min));

    // 
    // printf("left_min, left_max, right_min, right_max = %d, %d, %d, %d\n", );
    // drawPolygon(result, result, center_points, true, Scalar(0, 255, 0), -1);
    // vector<vector<Point> > fillContAll;
    // vector<vector<Point> > center_points;
        //

    // //  
    Mat result_pre = Mat::zeros(result.size(), result.type());
    vector<vector<Point> > fillContAll;
    fillContAll.push_back(center_points);
    //result_pre = imageCopy(result);
    fillPoly(result_pre, fillContAll, Scalar(0,255,0));
    // addWeightedImage(result, result_pre, result, 100, 50);
    addWeighted(result, 1, result_pre, 0.7, 0, result, 0);



    return;
}


