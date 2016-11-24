#include "ProccessingImage.h"


ProccessingImage::ProccessingImage()
{
}


ProccessingImage::~ProccessingImage()
{
}


void ProccessingImage::SobelEdgeMethod(cv::Mat &input_img, cv::Mat &out_img){

	cv::Mat src_gray;
	if(input_img.channels() == 3) cv::cvtColor(input_img ,src_gray, CV_BGR2GRAY);
	else input_img.copyTo( src_gray);
	cv::GaussianBlur(src_gray , src_gray, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
	/// Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	Sobel(src_gray, grad_x, CV_16S, 1, 0, 3, 1, 0, cv::BORDER_REPLICATE);
	convertScaleAbs(grad_x, abs_grad_x);
	/// Gradient Y
	//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	Sobel(src_gray, grad_y, CV_16S,  0, 1, 3,1 , 1, cv::BORDER_REPLICATE);
	convertScaleAbs(grad_y, abs_grad_y);

	/// Total Gradient (approximate)
	cv::Mat sobell_img;
	addWeighted(abs_grad_x, 1, abs_grad_y, 1, 0, out_img);
	/// apply Gabor fillter

	/*cv::Mat kernell = cv::getGaborKernel(cv::Size(9, 9), 5, 45, 8, CV_PI / 4, 0, CV_32F);
	cv::Mat gabor_img;
	cv::filter2D(src_gray, gabor_img, CV_32F, kernell);
	gabor_img.copyTo(out_img);*/
	// release memory
	src_gray.release();
	grad_x.release();
	grad_y.release();
	abs_grad_x.release();
	abs_grad_y.release();
}

void ProccessingImage::SetUpThreshold(cv::Mat &input_img, cv::Mat &out_img, const int value){
	cv::Mat src_img;
	if (input_img.channels() == 3) cv::cvtColor(input_img, src_img, CV_BGR2GRAY);
	else input_img.copyTo(src_img);

	out_img = src_img.clone();

	for (int i = 0; i != src_img.rows; i++){
		uchar *Mi = src_img.ptr<uchar>(i);
		uchar *Mo = out_img.ptr<uchar>(i);

		for (int j = 0; j != src_img.cols; j++){
			if (Mi[j] >= value) Mo[j] = 255;
			else Mo[j] = 0;
		}
	}

}


void ProccessingImage::HoughLineDrawing(cv::Mat &input_img, cv::Mat &out_img, const int value){
	std::vector<cv::Vec4i> lines;
	out_img = cv::Mat(input_img.rows, input_img.cols, CV_8UC3);
	cv::HoughLinesP(input_img, lines, 1, CV_PI / 180, value, 0, 0);
	for (size_t i = 0; i < lines.size(); i++)
	{
		cv::Vec4i l = lines[i];
		line(out_img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 3, CV_AA);
	}
}

void ProccessingImage::CannyDrawing(cv::Mat &input_img, cv::Mat &out_img, const int thresh1, const int thresh2){
	cv::Mat src_img;
	if (input_img.channels() == 3) cv::cvtColor(input_img, src_img, CV_BGR2GRAY);
	else input_img.copyTo(src_img);

	cv::Canny(src_img,out_img, thresh1, thresh2, 3);
}

/*
Input: Gray image
*/
void ProccessingImage::FindContourCircle(cv::Mat &input_img, cv::Mat &out_img){
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierachy;
	 input_img.copyTo(out_img);
	
	 cv::Mat gauss_blur,canny_blur;
	 cv::GaussianBlur(input_img, gauss_blur, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
	 SobelEdgeMethod(gauss_blur, canny_blur);
	 cv::imwrite("cannyblue.bmp", canny_blur);
	 cv::imwrite("gausianblur.bmp", gauss_blur);

	 cv::findContours(input_img, contours, hierachy, cv::RETR_TREE, CV_CHAIN_APPROX_SIMPLE,cv::Point(0,0));

	cv::RotatedRect max_temp;
	cv::RotatedRect min_temp;
	double max_length = 0;
	double min_lenght = 0;
	bool max_flag = 0;
	bool min_flag = 0;
	cv::Point2f center;
	float radius;

	for (unsigned int i1 = 0; i1 != contours.size(); i1++){
		int i2 = hierachy[i1][2];
		if ( contours[i1].size() < 200 ) continue;
		double P1 = arcLength(contours[i1], true);
        cv::RotatedRect temp = cv::fitEllipse(contours[i1]);
		if (P1 >= max_length){
			max_length = P1;
			max_temp = temp;
			max_flag = 1;
		}
		else if (P1 >= min_lenght){
			min_lenght = P1;
			min_temp = temp;
			min_flag = 1;
			minEnclosingCircle(contours[i1], center, radius);
		}
		std::cout << "arcLenth " << P1 << std::endl;
		
	}
	if (max_flag && min_flag){
		/*ellipse(out_img, max_temp, cv::Scalar(255, 255, 255),5, 8);*/
		ellipse(out_img, min_temp, cv::Scalar(255, 255, 255), 5, 8);
		//circle(out_img, cv::Point(center.x, center.y), radius, cv::Scalar(255, 255, 255), 5);
		for (int i = 0; i != 20; i++){
			min_temp.size.height = min_temp.size.height + 10;
			min_temp.size.width = min_temp.size.width + 10;
			ellipse(out_img, min_temp, cv::Scalar(255, 255, 255), 1, 8);
		}
		
	}
	
}

void ProccessingImage::SubTract2Image(cv::Mat &input_img, cv::Mat &back_ground, cv::Mat &out_img, const int thresh){
	out_img = input_img.clone();

	for (int i = 0; i != input_img.rows; i++){
		uchar *Mi1 = input_img.ptr<uchar>(i);
		uchar *Mi2 = back_ground.ptr<uchar>(i);
		uchar *Mo = out_img.ptr<uchar>(i);

		for (int j = 0; j != input_img.cols; j++){

			int value = Mi1[j] - Mi2[j];


			if (value > thresh) Mo[j] = Mi1[j];
			/*else if (value < -thresh) Mo[j] = Mi2[j];*/
			else Mo[j] = 0;
		}
	}
}

