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

#include "testmouseevent.h"
#include <QEvent>
#include<QMouseEvent>
#include <QDebug>
TestMouseEvent::TestMouseEvent(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
bool TestMouseEvent::event(QEvent *ev)
{
	if (ev->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *me = static_cast<QMouseEvent*> (ev);
		////�������
		//qDebug() << "MouseButtonPress " << me->x() << ":" << me->y();
		////��������
		//qDebug() << "windowPos " << me->windowPos().x() << ":" << me->windowPos().y();
		////��Ļ����
		//qDebug() << "screenPos " << me->screenPos().x() << ":" << me->screenPos().y();
	}
	return QWidget::event(ev);
}