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

#include <QWidget>
#include "ui_MenuWidget.h"
#include <QDebug>
#include <QMenu>
class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = Q_NULLPTR);
	~MenuWidget();
public slots:
	void Hover()
	{
		qDebug() << "Hover";
	}
	void Action1()
	{
		qDebug() << "Action1";
	}
	void Action1(bool isc)
	{
		qDebug() << "Action1 = " <<isc;
	}
	void Action(QAction* act)
	{
		qDebug() << "Action "<<act->text();
	}
	void Hovered(QAction* act)
	{
		//动态菜单
		if (act->text() == QStringLiteral("菜单3"))
		{
			qDebug() << "Hovered " << act->text();
			act->menu()->clear();
			act->menu()->addAction(QStringLiteral("菜单3.1"));
			act->menu()->addAction(QStringLiteral("菜单3.2"));
			act->menu()->addAction(QStringLiteral("菜单3.3"));
		}
		
	}

	void Click()
	{
		//鼠标位置显示菜单
		m1->exec(QCursor::pos());
	}
private:
	QMenu *m1 = NULL;
	Ui::MenuWidget ui;
};
