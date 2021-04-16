#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(void)
{
    cv::Mat image = cv::imread("../..Data/Lenna.png");
    cv::namedWindow("image",cv::WINDOW_NORMAL);
    cv::imshow("image",image);
    return 0;
}