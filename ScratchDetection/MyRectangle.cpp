#include "MyRectangle.h"



MyRectangle::MyRectangle()
{
	Pressed = false;
	setFlags(ItemIsSelectable);
	setFlag(ItemIsMovable);
	setFlag(ItemIsFocusable);
	setFlag(ItemSendsGeometryChanges);
}


MyRectangle::~MyRectangle()
{
}

QRectF MyRectangle::boundingRect() const {
	return QRectF(0, 0, 100, 100);
}

void MyRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QRectF rec = boundingRect();
	QBrush brush(Qt::blue);

	if (Pressed) {
		brush.setColor(Qt::red);
	}
	else {
		brush.setColor(Qt::green);
	}

	painter->fillRect(rec, brush);
	painter->drawRect(rec);
}

void MyRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	Pressed = true;
	update();
	QGraphicsItem::mousePressEvent(event);
}
void MyRectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	Pressed = false;
	update();

	QGraphicsItem::mouseReleaseEvent(event);
}
