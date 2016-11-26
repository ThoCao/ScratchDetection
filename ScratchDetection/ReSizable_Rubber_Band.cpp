#include "ReSizable_Rubber_Band.h"

ReSizable_Rubber_Band::ReSizable_Rubber_Band(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::SubWindow);
	QGridLayout* layout = new QGridLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  QSizeGrip* top_left     = new QSizeGrip(this);
  QSizeGrip* top_right    = new QSizeGrip(this);
  QSizeGrip* bottom_right = new QSizeGrip(this);
  QSizeGrip* bottom_left  = new QSizeGrip(this);
  QSizeGrip* base_left    = new QSizeGrip(this);
  QSizeGrip* base_right   = new QSizeGrip(this);

  

  QSizeGrip* base_top = new QSizeGrip(this);
  QSizeGrip* base_bottom = new QSizeGrip(this);

  layout->addWidget(top_left, 0,0,0,0, Qt::AlignTop  | Qt::AlignLeft );
  layout->addWidget(top_right, 0,0,1,0, Qt::AlignTop | Qt::AlignRight);
  layout->addWidget(base_left, 1, 0, 1, 1, Qt::AlignTop | Qt::AlignLeft);
  layout->addWidget(base_right,0,1,1,1, Qt::AlignBottom | Qt::AlignRight);

  layout->addWidget(base_bottom, 1, 1, 1, 1, Qt::AlignBottom | Qt::AlignLeft);
  layout->addWidget(base_top, 0, 1, 1, 1, Qt::AlignTop | Qt::AlignLeft);
  layout->addWidget(bottom_right, 1, 1,1,1, Qt::AlignBottom | Qt::AlignRight);
  layout->addWidget(bottom_left, 1, 0,1,1, Qt::AlignBottom | Qt::AlignLeft);
  rubberband = new QRubberBand(QRubberBand::Rectangle, this);
  rubberband->move(0, 0);
  rubberband->show();
  show();

  installEventFilter(this);
}

ReSizable_Rubber_Band::~ReSizable_Rubber_Band()
{
}

void ReSizable_Rubber_Band::resizeEvent(QResizeEvent *)
{
	rubberband->resize(size());
}
