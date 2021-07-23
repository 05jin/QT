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
#include "ui_qtablewidgettest.h"

class QTableWidgetTest : public QWidget
{
	Q_OBJECT

public:
	QTableWidgetTest(QWidget *parent = Q_NULLPTR);
public slots:
	void Del();
	//鼠标悬停，不支持设置的widget
	void ItemEntered(QTableWidgetItem *item);
	void CellEntered(int row, int column);

	//单机鼠标左键
	void Click(int, int);

	//双击鼠标左键或者右键
	void Double(int, int);

	//元素修改
	void Change(int, int);

	//顶部标题点击
	void SectionClicked(int col);
private:
	Ui::QTableWidgetTestClass ui;
};
