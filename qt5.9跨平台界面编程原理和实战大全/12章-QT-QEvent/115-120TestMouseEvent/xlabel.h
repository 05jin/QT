/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               �������Ĳܿ����˴��������Ϊѧϰ�ο�                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Contact       : xiacaojun@qq.com
**        ����   : http://blog.csdn.net/jiedichina
**		��Ƶ�γ� : http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961
**                 http://edu.51cto.com/lecturer/12016059.html
**                 http://study.163.com/u/xiacaojun
**                 https://jiedi.ke.qq.com/
**   ����γ̺�����롶QT5��ƽ̨�����̡�452758022 QQȺ������Ⱥ����ѯ�γ����������Դ��
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
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
