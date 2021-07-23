#pragma once
#include <QSlider>
class XSlider :public QSlider
{
public:
	XSlider(QWidget *p = NULL);
	~XSlider();
	virtual void mousePressEvent(QMouseEvent *e);
};

