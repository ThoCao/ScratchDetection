#pragma once
#include <QPainter>
#include <QGraphicsItem>

class MyRectangle : public QGraphicsItem
{
public:
	MyRectangle();
	~MyRectangle();

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

	bool Pressed;

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

};

