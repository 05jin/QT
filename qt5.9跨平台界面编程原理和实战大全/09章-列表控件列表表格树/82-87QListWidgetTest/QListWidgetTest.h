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

#include <QtWidgets/QWidget>
#include "ui_QListWidgetTest.h"

class QListWidgetTest : public QWidget
{
	Q_OBJECT

public:
	QListWidgetTest(QWidget *parent = Q_NULLPTR);
public slots:
	void Click();
	void Sort();

	//当前选择变化
	void CurChange(QListWidgetItem *cur, QListWidgetItem *pre);
	void CurChange(int row);
	void CurChange(const QString &txt);
	//激活 左键双击
	void ItemAct(QListWidgetItem *item);
	//内容改变 焦点移开，回车确认
	void ItemChange(QListWidgetItem *item);

	//鼠标事件
	void ItemClick(QListWidgetItem *item);
	void ItemDoubleClick(QListWidgetItem *item);
	//ui.listWidget->setMouseTracking(true);
	void ItemEntered(QListWidgetItem *item); 
	void ItemPressed(QListWidgetItem *item);

private:
	Ui::QListWidgetTestClass ui;
};
