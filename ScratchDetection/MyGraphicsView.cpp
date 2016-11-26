#include "MyGraphicsView.h"

#include "edge.h"
#include "node.h"

#include <math.h>

MyGraphicsView::MyGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
	scence = new QGraphicsScene(this);
	setScene(scence);

	//// adding image
	QPixmap ImagePixmap;
	ImagePixmap.load("background.bmp");
	/*scence->addPixmap(ImagePixmap);
	fitInView(scence->itemsBoundingRect(), Qt::KeepAspectRatio);*/
	setBackgroundBrush(ImagePixmap);

	scence->addItem(node1);
	scence->addItem(node2);
	scence->addItem(nodecenter);
	scence->addItem(new Edge(node1, nodecenter));
	scence->addItem(new Edge(nodecenter,node2));
	node1->setPos(50, 50);
	nodecenter->setPos(0, 50);
	node2->setPos(100, 100);
	// line
	scence->setSceneRect(0, 0, 1600, 1200);
	// turn off auto scroll bar
	// [4] install event filter

	// [4]
}

MyGraphicsView::~MyGraphicsView()
{
}

void MyGraphicsView::scaleView(qreal scaleFactor){
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	if (factor < 0.07 || factor > 100)
		return;

	scale(scaleFactor, scaleFactor);
}




void MyGraphicsView::shuffle()
{
	foreach(QGraphicsItem *item, scene()->items()) {
		if (qgraphicsitem_cast<Node *>(item))
			item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
	}
}

void MyGraphicsView::zoomIn()
{
	scaleView(qreal(1.2));
}

void MyGraphicsView::zoomOut()
{
	scaleView(1 / qreal(1.2));
}

