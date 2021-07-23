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
		////相对坐标
		//qDebug() << "MouseButtonPress " << me->x() << ":" << me->y();
		////程序坐标
		//qDebug() << "windowPos " << me->windowPos().x() << ":" << me->windowPos().y();
		////屏幕坐标
		//qDebug() << "screenPos " << me->screenPos().x() << ":" << me->screenPos().y();
	}
	return QWidget::event(ev);
}