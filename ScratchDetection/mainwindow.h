#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include <BaslerCam.h>
#include <ImgView.h>

#include "ProccessingImage.h"

#include <QGraphicsView>
#include "ReSizable_Rubber_Band.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
protected:
	bool eventFilter(QObject *obj, QEvent *event);
public slots:
	void on_actionOpen_Camera_triggered();
	void on_actionClose_Camera_triggered();
	void on_actionSingle_Shot_triggered();
	void on_actionContinuous_Shot_triggered();
	void on_actionStop_triggered();
	void on_actionPause_triggered();
	void on_actionBackGround_triggered();
	void on_actionSaving_Image_triggered();
	public slots:
	void on_btn_Get_Roi_Image_clicked();
private:
	BaslerCam Cam_Capture;

private: // data for processing
	cv::Mat back_ground_img;
	ProccessingImage *processing = new ProccessingImage();
	cv::Mat save_edge_img;
	cv::Mat save_origin_img;
	ImgView *main_image_view;
	ReSizable_Rubber_Band* rubber_band;
	bool move_rubberband=0;
private:// ROI
	cv::Mat roi_img;
	cv::Mat roi_img_out;
	cv::Mat roi_img_in;

private:// status of product
	cv::Mat pass_img;
	cv::Mat fail_img;
private:// Tab: Defection Character
	ImgView* _main_image_defect_1;
};

#endif // MAINWINDOW_H
