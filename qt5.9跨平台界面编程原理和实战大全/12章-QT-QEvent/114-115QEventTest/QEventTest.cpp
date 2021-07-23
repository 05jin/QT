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
#include "QEventTest.h"
#include <QDebug>
#include<QEvent>
#include <QKeyEvent>
QEventTest::QEventTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setMouseTracking(true);
}
bool QEventTest::event(QEvent *ev)
{
	if (ev->type() == QEvent::KeyPress)
	{
		QKeyEvent *ke = static_cast<QKeyEvent*>(ev);
		if (ke->key() == 'A')
		{
			//�Զ������¼���������
			if (!ke->isAutoRepeat())
				qDebug() << "aaaaaaaaaaaaaaaaaaa";
			return true;
		}
	}
	return QWidget::event(ev);
}
void QEventTest::keyPressEvent(QKeyEvent *ev)
{
	//�Զ������¼���������
	if (ev->isAutoRepeat()) return;
	if (ev->key() == Qt::Key_F1) 
	{
		qDebug() << "Key_F1";
	}
	
	qDebug() << "keyPressEvent = " << ev->key();
}

//�����ɿ�
void QEventTest::keyReleaseEvent(QKeyEvent *ev)
{
	//�Զ������¼���������
	if (ev->isAutoRepeat()) return;
	qDebug() << "keyReleaseEvent = " << ev->key();
}