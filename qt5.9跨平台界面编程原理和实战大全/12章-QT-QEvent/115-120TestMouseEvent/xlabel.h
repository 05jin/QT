/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：夏曹俊，此代码可用作为学习参考                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Contact       : xiacaojun@qq.com
**        博客   : http://blog.csdn.net/jiedichina
**		视频课程 : http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961
**                 http://edu.51cto.com/lecturer/12016059.html
**                 http://study.163.com/u/xiacaojun
**                 https://jiedi.ke.qq.com/
**   购买课程后请加入《QT5跨平台界面编程》452758022 QQ群，可在群中咨询课程问题和下载源码
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
** Creation date : 2017-11-8
**
*******************************************************************************/

#pragma once

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include<QMenu>
class XLabel : public QLabel
{
	Q_OBJECT

public:
	QMenu menu;
	XLabel(QWidget *parent);
	~XLabel();
	bool event(QEvent *ev);
	virtual void enterEvent(QEvent *event)	{		qDebug() << "enterEvent";	}	virtual void leaveEvent(QEvent *event)	{		qDebug() << "leaveEvent";	}	virtual void mouseDoubleClickEvent(QMouseEvent *event)	{		qDebug() << "mouseDoubleClickEvent "<<event->pos().x()<<":" << event->pos().y();	}	virtual void mouseMoveEvent(QMouseEvent *event)	{		qDebug() << "mouseMoveEvent " << event->pos().x() << ":" << event->pos().y();	}	virtual void mousePressEvent(QMouseEvent *event)	{		qDebug() << "mousePressEvent " << event->pos().x() << ":" << event->pos().y();	}	virtual void mouseReleaseEvent(QMouseEvent *event)	{		qDebug() << "mouseReleaseEvent " << event->pos().x() << ":" << event->pos().y();	}
};
