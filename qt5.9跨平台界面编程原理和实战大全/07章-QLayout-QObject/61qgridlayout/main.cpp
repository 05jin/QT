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
#include "qgridlayout.h"
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include <QPushButton>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget *win = new QWidget;
	QGridLayout *gl = new QGridLayout(win);
	QPushButton *but11 = new QPushButton("but11");
	gl->addWidget(but11, 0, 0);
	QPushButton *but12 = new QPushButton("but12");
	but12->setMinimumSize(100, 100);
	but12->setMaximumSize(500, 500);
	but12->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	gl->addWidget(but12, 0, 1);

	QPushButton *but13 = new QPushButton("but13");
	gl->addWidget(but13, 0, 2);
	QPushButton *but21 = new QPushButton("but21");
	gl->addWidget(but21, 1, 0);
	QPushButton *but23 = new QPushButton("but23");
	gl->addWidget(but23, 1, 2);

	//水平间距
	gl->setHorizontalSpacing(10);

	//垂直间距
	gl->setVerticalSpacing(10);


	win->show();

	///qgridlayout w;
	//w.show();
	return a.exec();
}
