#include "OpenCV.h"

using namespace std;
using namespace cv;
vector<string> trackerTypes;
//"BOOSTING", "MIL", "KCF", "TLD", "MEDIANFLOW"
string trackerType = "MEDIANFLOW";
Ptr<Tracker> createTrackerByName(string trackerType) 
{
    Ptr<Tracker> tracker;
    if (trackerType ==  trackerTypes[0])
        tracker = TrackerBoosting::create();
    else if (trackerType == trackerTypes[1])
        tracker = TrackerMIL::create();
    else if (trackerType == trackerTypes[2])
        tracker = TrackerKCF::create();
    else if (trackerType == trackerTypes[3])
        tracker = TrackerTLD::create();
    else if (trackerType == trackerTypes[4])
        tracker = TrackerMedianFlow::create();
    else {
        cout << "Incorrect tracker name" << endl;
        cout << "Create BOOSTING" << endl;
        tracker = TrackerBoosting::create();
    }
    return tracker;
}

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

void frameProcessing(Mat &frame, Mat &result) {
    int width = frame.cols;
    int height = frame.rows;
    vector<Point> pts;
	pts.push_back(Point(int(width * 0.45), int(height * 0.6)));
	pts.push_back(Point(int(width * 0.55), int(height * 0.6)));
	pts.push_back(Point(int(width * 0.95), int(height * 1.0)));
	pts.push_back(Point(int(width * 0.05), int(height * 1.0)));
	polyROI(frame, result, pts);
	
    Scalar lower_white_hls(0, 200, 0);
	Scalar upper_white_hls(179, 255, 255);
	Scalar lower_yellow_hls(15, 30, 115);
	Scalar upper_yellow_hls(35, 200, 255);
	
	Mat output_white_hls, output_yellow_hls;
	splitColor(result, output_white_hls, lower_white_hls, upper_white_hls, COLOR_BGR2HLS);
	splitColor(result, output_yellow_hls, lower_yellow_hls, upper_yellow_hls, COLOR_BGR2HLS);
	result = output_white_hls+output_yellow_hls;
	convertColor(result, result);
	cannyEdge(result, result);
	
	vector<Vec4i> lines;
    imageHoughLinesP(result, lines, 1.0, PI/180.0, 10, 10);
	vector<vector<Point> > points;
	splitLines(lines, points);
	linefitting(frame, result, points);
    return;
}

int main(void) {
    trackerTypes.clear();
    trackerTypes.push_back("BOOSTING");
    trackerTypes.push_back("MIL");
    trackerTypes.push_back("KCF");
    trackerTypes.push_back("TLD");
    trackerTypes.push_back("MEDIANFLOW");
	string openPath = videopath + roadVideo_02;
	Video(openPath, "output_Multiple_Object.avi");
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
void getRandomColors(vector<Scalar>& colors, int numColors)
{
    RNG rng(0);
    for(int i=0; i < numColors; i++)
        colors.push_back(Scalar(rng.uniform(0,255), rng.uniform(0, 255), rng.uniform(0, 255))); 
}
void Video(string openPath, string savePath) {
    vector<Rect> bboxes;
        
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
    bool ok = cap.read(frame); 
    bool showCrosshair = true;
    bool fromCenter = false;
    cout << "\n==========================================================\n";
    cout << "OpenCV says press c to cancel objects selection process" << endl;
    cout << "It doesn't work. Press Escape to exit selection process" << endl;
    cout << "\n==========================================================\n";
    selectROIs("MultiTracker", frame, bboxes, showCrosshair, fromCenter);
 
    // quit if there are no objects to track
    if(bboxes.size() < 1)
        return;
 
    vector<Scalar> colors;  
    getRandomColors(colors, bboxes.size()); 
    Ptr<MultiTracker> multiTracker = cv::MultiTracker::create();
    for(int i=0; i < bboxes.size(); i++)
        multiTracker->add(createTrackerByName(trackerType), frame, Rect2d(bboxes[i]));  
    while (cap.read(frame)) {
        frameProcessing(frame, output);
        multiTracker->update(frame);
        for(unsigned i=0; i<multiTracker->getObjects().size(); i++) {
            rectangle(output, multiTracker->getObjects()[i], colors[i], 2, 1);
        }
 
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
        if (abs(slope) < 0.5 ) {
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
    int min_y = image.rows * 0.6;
    int max_y = image.rows;
    Point left_min, left_max, right_min, right_max;
    interpolate(lx, ly, min_y, left_min);
    interpolate(lx, ly, max_y, left_max);
    interpolate(rx, ry, min_y, right_min);
    interpolate(rx, ry, max_y, right_max);
    line(result, left_min, left_max, Scalar(0, 0, 255), 3);
    line(result, right_min, right_max, Scalar(0, 0, 255), 3);
    return;
}
