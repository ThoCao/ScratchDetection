#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.actionSingle_Shot->setDisabled(1);
	ui.actionClose_Camera->setDisabled(1);
	ui.actionContinuous_Shot->setDisabled(1);
	ui.actionStop->setDisabled(1);
	ui.actionPause->setDisabled(1);
	ui.actionBackGround->setDisabled(1);

	back_ground_img = cv::imread("background.bmp",0);
	

	// load status of product
	pass_img = cv::imread("pass_status.jpg", 1);
	fail_img = cv::imread("Failed.png", 1);
	ui.lbMainImage_4->setImage(fail_img);
}

MainWindow::~MainWindow()
{
	delete processing;
}
void MainWindow::on_actionOpen_Camera_triggered(){
	if (Cam_Capture.OpenCam()){
		std::cout << "Connection Successful. " << std::endl;
		
		ui.actionOpen_Camera->setDisabled(1);

		ui.actionClose_Camera->setEnabled(1);
		ui.actionContinuous_Shot->setEnabled(1);
		ui.actionSingle_Shot->setEnabled(1);
		ui.actionBackGround->setEnabled(1);
	}
	else{
		std::cout << "Error occured." << std::endl;
	}
}
void MainWindow::on_actionClose_Camera_triggered(){
	if (Cam_Capture.CloseCam()){

		ui.actionOpen_Camera->setEnabled(1);

		ui.actionSingle_Shot->setDisabled(1);
		ui.actionClose_Camera->setDisabled(1);
		ui.actionContinuous_Shot->setDisabled(1);
		ui.actionPause->setDisabled(1);
		ui.actionStop->setDisabled(1);
		ui.actionBackGround->setDisabled(1);
	}
	else{
		std::cout << "Error occured." << std::endl;
		std::cout << "Can't Close Camera" << std::endl;
	}
}

void MainWindow::on_actionSingle_Shot_triggered(){

	cv::Mat image;
	bool found = Cam_Capture.ReceiveImage(image);
	
	ui.lbMainImage->setImage(image);
	
	image.release();
}
void MainWindow::on_actionContinuous_Shot_triggered(){
	ui.actionStop->setDisabled(0);
	ui.actionPause->setDisabled(0);
}
void MainWindow::on_actionStop_triggered(){

}
void MainWindow::on_actionPause_triggered(){

}

void MainWindow::on_actionBackGround_triggered(){
	bool found = Cam_Capture.ReceiveImage(back_ground_img);
	if(found) ui.statusBar->showMessage("Get back ground data successfull");
	else return;
	cv::imwrite("background.bmp", back_ground_img);
	ui.lbMainImage->setImage(back_ground_img);
}
void MainWindow::on_actionSaving_Image_triggered(){
	if (!save_edge_img.empty()) cv::imwrite("edgedetection.bmp", save_edge_img);
	if (!save_origin_img.empty()) cv::imwrite("original.bmp", save_origin_img);
}