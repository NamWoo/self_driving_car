#include <iostream>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;
void _EqualizeHist(InputArray _src, OutputArray _dst);
void _ClipEqualizeHist(InputArray _src, OutputArray _dst, float ClipLimit = 0.8f);
int main(void)
{
	
	Mat RGB = imread("test6.jpg");
	//Mat RGB = imread("test9.jpg");
	Mat HSV, RGBr;
	Mat HSV_V, HSV_SV, HSV_HSV, HSV_CV_2, HSV_CV_1;
	Mat HSV_V_RGB, HSV_SV_RGB, HSV_HSV_RGB, HSV_CV_RGB_2, HSV_CV_RGB_1;

	vector<Mat> BGRs;
	split(RGB, BGRs);
	vector<Mat> BGRsR;
	split(RGB, BGRsR);

	_EqualizeHist(BGRs[0], BGRsR[0]);
	_EqualizeHist(BGRs[1], BGRsR[1]);
	_EqualizeHist(BGRs[2], BGRsR[2]);
	merge(BGRsR, RGBr);



	cvtColor(RGB, HSV, CV_BGR2HSV);
	vector<Mat> HSVs;
	split(HSV, HSVs);

	vector<Mat> HSVsR;
	split(HSV, HSVsR);
	_EqualizeHist(HSVs[2], HSVsR[2]);
	merge(HSVsR, HSV_V);
	_EqualizeHist(HSVs[1], HSVsR[1]);
	merge(HSVsR, HSV_SV);
	_EqualizeHist(HSVs[0], HSVsR[0]);
	merge(HSVsR, HSV_HSV);

	vector<Mat> HSVs2;
	split(HSV, HSVs2);
	vector<Mat> HSVsCR_2;
	split(HSV, HSVsCR_2);
	_ClipEqualizeHist(HSVs2[2], HSVsCR_2[2], 0.3);
	merge(HSVsCR_2, HSV_CV_2);

	vector<Mat> HSVs1;
	split(HSV, HSVs1);
	vector<Mat> HSVsCR_1;
	split(HSV, HSVsCR_1);
	_ClipEqualizeHist(HSVs1[2], HSVsCR_1[2], 0.6);
	merge(HSVsCR_1, HSV_CV_1);

	Mat YCrCb;
	cvtColor(RGB, YCrCb, CV_BGR2YCrCb);
	vector<Mat> YCrCbChannel;
	split(YCrCb, YCrCbChannel);
	_ClipEqualizeHist(YCrCbChannel[0], YCrCbChannel[0], 0);
	Mat YCrCbR;
	merge(YCrCbChannel, YCrCb);
	cvtColor(YCrCb, YCrCbR, CV_YCrCb2BGR);

	cvtColor(HSV_CV_1, HSV_CV_RGB_1, CV_HSV2BGR);
	cvtColor(HSV_CV_2, HSV_CV_RGB_2, CV_HSV2BGR);
	cvtColor(HSV_V, HSV_V_RGB, CV_HSV2BGR);
	cvtColor(HSV_SV, HSV_SV_RGB, CV_HSV2BGR);
	cvtColor(HSV_HSV, HSV_HSV_RGB, CV_HSV2BGR);
	//imshow("RGB_H.E.", RGBr);
	//imshow("HSV_CV_RGB_1", HSV_CV_RGB_1);
	//imshow("HSV_CV_RGB_2", HSV_CV_RGB_2);
	//imshow("HSV_V", HSV_V_RGB);
	//imshow("YCrCb_Y", YCrCbR);
	//imshow("HSV_SV", HSV_SV_RGB);
	//imshow("HSV_HSV", HSV_HSV_RGB);
	//imshow("Input", RGB);
	waitKey();
	imwrite("RGBr.jpg", RGBr);
	imwrite("HSV_CV_RGB_1.jpg", HSV_CV_RGB_1);
	imwrite("HSV_CV_RGB_2.jpg", HSV_CV_RGB_2);
	imwrite("HSV_V_RGB.jpg", HSV_V_RGB);
	imwrite("HSV_SV_RGB.jpg", HSV_SV_RGB);
	imwrite("HSV_HSV_RGB.jpg", HSV_HSV_RGB);
	imwrite("YCrCb.jpg", YCrCbR);
}
void _ClipEqualizeHist(InputArray _src, OutputArray _dst, float ClipLimit)
{
	Mat src = _src.getMat();
	if (src.type() != CV_8UC1)
	{
		cout << "Wrong Input!" << endl;
		return;
	}
	_dst.create(src.size(), src.type());
	Mat dst = _dst.getMat();

	int i;
	float histogram_pdf[256] = { 0.0f };
	float histogram_cdf[256] = { 0.0f };

	uchar *ptrsrc = src.ptr<uchar>(0);
	for (i = 0; i < src.rows*src.cols; i++)
	{
		histogram_pdf[ptrsrc[i]]+=1.0f; //넘버링
	}
	float hmax = 0;
	for (i = 0; i < 256; i++)
	{
		if (hmax <= histogram_pdf[i])
			hmax = histogram_pdf[i];
	}
	float ClipLimiter = hmax * (1.0f - ClipLimit);
	float gap = 0.0f;
	for (i = 0; i < 256; i++)
	{
		if (histogram_pdf[i] > ClipLimiter)
		{
			gap += histogram_pdf[i] - ClipLimiter;
			histogram_pdf[i] = ClipLimiter;
		}
	}
	for (i = 0; i < 256; i++)
	{
		histogram_pdf[i] += gap / 256.0f;
	}
	float NormFactor = 255.0 / (src.rows * src.cols);

	histogram_cdf[0] = histogram_pdf[0] *NormFactor;
	for (i = 1; i < 256; i++)
	{
		histogram_cdf[i] = histogram_pdf[i] *NormFactor;
		histogram_cdf[i] = histogram_cdf[i - 1] + histogram_cdf[i];
	}
	uchar *ptrdst = dst.ptr<uchar>(0);
	for (int i = 0; i < src.rows*src.cols; i++)
	{
		ptrdst[i] = (uchar)(histogram_cdf[ptrsrc[i]] + 0.5);
	}


}

void _EqualizeHist(InputArray _src, OutputArray _dst)
{
	Mat src = _src.getMat();
	if (src.type() != CV_8UC1)
	{
		cout << "Wrong Input!" << endl;
		return;
	}
	_dst.create(src.size(), src.type());
	Mat dst = _dst.getMat();

	int i;
	float histogram_pdf[256] = { 0 };
	float histogram_cdf[256] = { 0 };

	uchar *ptrsrc = src.ptr<uchar>(0);
	for (i = 0; i < src.rows*src.cols; i++)
	{
		histogram_pdf[ptrsrc[i]]++; //넘버링
	}

	float NormFactor = 255.0 / (src.rows * src.cols);

	histogram_cdf[0] = histogram_pdf[0] * NormFactor;
	for (i = 1; i < 256; i++)
	{
		histogram_cdf[i] = histogram_pdf[i] * NormFactor;
		histogram_cdf[i] = histogram_cdf[i - 1] + histogram_cdf[i];
	}
	uchar *ptrdst = dst.ptr<uchar>(0);
	for (int i = 0; i < src.rows*src.cols; i++)
	{
		ptrdst[i] = (uchar)(histogram_cdf[ptrsrc[i]] + 0.5);
	
	}
}