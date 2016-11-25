#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include <BaslerCam.h>
#include <ImgView.h>

#include "ProccessingImage.h"

#include <QGraphicsView>
#include "QGraphicsProxyWidget"
#include "MyRectangle.h"
#include "edge.h"
#include "node.h"

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
private:
	BaslerCam Cam_Capture;

private: // data for processing
	cv::Mat back_ground_img;
	ProccessingImage *processing = new ProccessingImage();
	cv::Mat save_edge_img;
	cv::Mat save_origin_img;
	ImgView *main_image_view;
	QGraphicsScene * scence;
	MyRectangle *rectangle;
private: // node and eadge
	Node *centerNode;
	Node *node1;// = new Node();
	Node *node2;// = new Node();

private:// status of product
	cv::Mat pass_img;
	cv::Mat fail_img;
};

#endif // MAINWINDOW_H
