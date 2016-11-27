#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), main_image_view(new ImgView),_main_image_defect_1(new ImgView)
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
	ui.lbMainImage_4->setImageScaled(fail_img);
	// config scroll image view
	ui.ScrollArea_Image_View->setWidget(main_image_view);
	main_image_view->installEventFilter(this);
	//main_image_view->setMouseTracking(true);
	//
	// [2]
	rubber_band = new ReSizable_Rubber_Band(main_image_view);
	InitializeRubberBandRoi();
	// [2]
	// [6] Tab: Defection Character
	ui.scrollArea->setWidget(_main_image_defect_1);
	cv::Mat load_roi = cv::imread("roi_img_out.bmp", 0);
	_main_image_defect_1->setImage(load_roi);
	// [6]
}

MainWindow::~MainWindow()
{
	delete processing;
	//[2] Rubber Band Roi
	SaveRubberBandRoi();
	//[2] Rubber Band Roi
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
bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
    if(event->type() == QEvent::MouseMove){
		if (obj == main_image_view) {
			const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
			ui.statusBar->showMessage("(" + QString::number(me_ptr->x()) + ":" + QString::number(me_ptr->y())+")");
			if (move_rubberband) {
			
				rubber_band->move(me_ptr->pos().x()- rubber_band->rect().width()/2,me_ptr->pos().y()- rubber_band->rect().height()/2);
			}
		}
		return 0;
	}
	if (obj == main_image_view) {
		if (event->type() == QEvent::MouseButtonPress) {
			const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
			//std::cout << "clicking " << std::endl;
			// [1] rubberband move
			if (rubber_band->geometry().contains(me_ptr->pos())) {
				move_rubberband = true;
				std::cout << "rubber selected" << std::endl;
			}
			// [1]
		}
		else if (event->type() == QEvent::MouseButtonRelease) {
			move_rubberband = false;
		}
		return 0;
	}
	else return QMainWindow::eventFilter(obj, event);
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
	// copy to roi_img
	image.copyTo(roi_img);
	
	main_image_view->setImage(image);

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
	main_image_view->setImage(back_ground_img);
}
void MainWindow::on_actionSaving_Image_triggered(){
	if (!save_edge_img.empty()) cv::imwrite("edgedetection.bmp", save_edge_img);
	if (!save_origin_img.empty()) cv::imwrite("original.bmp", save_origin_img);
}

void MainWindow::InitializeRubberBandRoi()
{
	// Load
	//[2] Rubber Band Roi
	cv::FileStorage rubber(_rubber_name_file, cv::FileStorage::READ);
	rubber["rubber_intital_pos_x"] >> _rubber_intital_pos.x;
	rubber["rubber_intital_pos_y"] >> _rubber_intital_pos.y;
	rubber["rubberwidth"]          >> _rubber_width;
	rubber["rubberheight"]         >> _rubber_height;
	rubber.release();
	//[2] Rubber Band Roi
	// Write
	rubber_band->resize(_rubber_width, _rubber_height);
	rubber_band->move(_rubber_intital_pos.x, _rubber_intital_pos.y);
}

void MainWindow::SaveRubberBandRoi()
{
	//[2] Rubber Band Roi
	_rubber_intital_pos = cv::Point(rubber_band->pos().x(), rubber_band->pos().y());
	_rubber_width = rubber_band->width();
	_rubber_height = rubber_band->height();
	cv::FileStorage rubber(_rubber_name_file, cv::FileStorage::WRITE);
	rubber << "rubber_intital_pos_x" << _rubber_intital_pos.x;
	rubber << "rubber_intital_pos_y" << _rubber_intital_pos.y;
	rubber << "rubberwidth"          << _rubber_width;
	rubber << "rubberheight"         << _rubber_height;
	rubber.release();
	//[2] Rubber Band Roi
}

void MainWindow::on_btn_Get_Roi_Image_clicked() {
	if (!roi_img.empty()) {
		QRectF rec = rubber_band->contentsRect();
		cv::Rect roi(rubber_band->pos().x(), rubber_band->pos().y(), rec.width(), rec.height());
		roi_img_out = roi_img(roi);
		cv::imshow("roi", roi_img_out);
		cv::imwrite("roi_img_out.bmp", roi_img_out);
		cv::waitKey(10);
		// set to tab defection
		_main_image_defect_1->setImage(roi_img_out);
	}
}


