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
			//自动连按事件，不处理
			if (!ke->isAutoRepeat())
				qDebug() << "aaaaaaaaaaaaaaaaaaa";
			return true;
		}
	}
	return QWidget::event(ev);
}
void QEventTest::keyPressEvent(QKeyEvent *ev)
{
	//自动连按事件，不处理
	if (ev->isAutoRepeat()) return;
	if (ev->key() == Qt::Key_F1) 
	{
		qDebug() << "Key_F1";
	}
	
	qDebug() << "keyPressEvent = " << ev->key();
}

//键盘松开
void QEventTest::keyReleaseEvent(QKeyEvent *ev)
{
	//自动连按事件，不处理
	if (ev->isAutoRepeat()) return;
	qDebug() << "keyReleaseEvent = " << ev->key();
}