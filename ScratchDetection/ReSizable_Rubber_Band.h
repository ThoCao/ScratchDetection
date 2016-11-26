#pragma once

#include <QWidget>
#include <QRubberBand>
#include <QHboxLayout>
#include <QGridLayout>
#include <QSizeGrip>
#include <iostream>

class ReSizable_Rubber_Band : public QWidget
{
	Q_OBJECT
public:
	ReSizable_Rubber_Band(QWidget *parent =0);
	~ReSizable_Rubber_Band();

private:
	QRubberBand * rubberband;
	void resizeEvent(QResizeEvent *);
};
