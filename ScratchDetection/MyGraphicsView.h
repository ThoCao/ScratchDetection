#pragma once

#include <QGraphicsView>
#include "edge.h"
#include "node.h"
#include <math.h>



class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphicsView(QWidget *parent = 0);
	~MyGraphicsView();

protected:
	void scaleView(qreal scaleFactor);
private: // node and eadge
		
		Node *centerNode;
		Node *node1      = new Node(0);
		Node *node2      = new Node(0);
		Node *nodecenter = new Node(0);
public:
	QGraphicsScene * scence;

public slots:
		void shuffle();
		void zoomIn();
		void zoomOut();
		
};
