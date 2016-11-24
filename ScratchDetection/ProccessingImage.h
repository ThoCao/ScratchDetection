#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

class ProccessingImage
{
public:
	ProccessingImage();
	~ProccessingImage();
public:
	void SobelEdgeMethod(cv::Mat &input_img,cv::Mat &out_img);
	void SetUpThreshold(cv::Mat &input_img, cv::Mat &out_img, const int value);
	void HoughLineDrawing(cv::Mat &input_img, cv::Mat &out_img, const int value);
	void CannyDrawing(cv::Mat &input_img, cv::Mat &out_img, const int thresh1, const int thresh2);
	void FindContourCircle(cv::Mat &input_img, cv::Mat &out_img);
	void SubTract2Image(cv::Mat &input_img, cv::Mat &back_ground, cv::Mat &out_img,const int thresh);
	
};

