#include "XSlider.h"
#include <QMouseEvent>
#include <QDebug>
void XSlider::mousePressEvent(QMouseEvent *e)
{
	qDebug() << e->pos().x();
	QSlider::mousePressEvent(e);
	//°Ù·Ö±È 0.32
	double p = (double)e->pos().x() / (double)width();
	int val = p*(maximum() - minimum()) + minimum();
	setValue(val);
}

XSlider::XSlider(QWidget *p):QSlider(p)
{
}


XSlider::~XSlider()
{
}
