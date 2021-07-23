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

#include "xlabel.h"
#include <QEvent>
#include<QMouseEvent>
#include <QDebug>
XLabel::XLabel(QWidget *parent)
	: QLabel(parent)
{
	this->setMouseTracking(true);
	menu.addAction(QStringLiteral("菜单1"));
	menu.addAction(QStringLiteral("菜单2"));
	menu.addAction(QStringLiteral("菜单3"));
}

XLabel::~XLabel()
{
}
bool XLabel::event(QEvent *ev)
{
	if (ev->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *me = static_cast<QMouseEvent*> (ev);
		////相对坐标
		qDebug() << "LocalPos " << me->x() << ":" << me->y();
		//程序坐标
		qDebug() << "windowPos " << me->windowPos().x() << ":" << me->windowPos().y();
		//屏幕坐标
		qDebug() << "screenPos " << me->screenPos().x() << ":" << me->screenPos().y();

		//本地坐标转全局（屏幕坐标）
		QPoint gpos = mapToGlobal(me->pos());
		qDebug() << "mapToGlobal " << gpos.x() << ":" << gpos.y();

		//获取鼠标的屏幕坐标
		qDebug() << "QCursor " << QCursor::pos().x() <<":"  << QCursor::pos().y();

		//鼠标按键事件
		if (me->buttons() & Qt::LeftButton)
		{
			qDebug() << "LeftButton";
			setCursor(Qt::ArrowCursor);
		}
		if (me->buttons() & Qt::RightButton)
		{
			qDebug() << "RightButton";
			//右键菜单
			menu.exec(gpos);

		}
		if (me->buttons() & Qt::MidButton)
		{
			qDebug() << "MidButton";
		}

		//左右键同时按下
		if ( (me->buttons() & Qt::LeftButton) && (me->buttons() & Qt::RightButton) )
		{
			qDebug() << "LeftButton&RightButton";
			//鼠标图标替换 -1 -1 热点中间
			QPixmap pix("cursor.png");
			QCursor cur = QCursor(pix, -1, -1);
			setCursor(cur);
		}
	}
	return QWidget::event(ev);
}