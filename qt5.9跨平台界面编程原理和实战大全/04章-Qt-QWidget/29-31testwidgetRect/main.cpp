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
#include "testwidgetrect.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <QThread>
#include <QObject>
#include "XThread.h"
using namespace std;
//class XThread :public QThread
//{
//public:
//	QWidget *w = NULL;
//	void run()
//	{
//		//for (int x = 0;x < 1000;x++)
//		{
//			//w->move(0, 0);
//		}
//	}
//};
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testwidgetRect w;
	w.show();
	
	QRect re = w.geometry();
	//w.setGeometry(0, 0, 800, 600);
	XThread xt;

	w.resize(1000, 500);
	QObject::connect(&xt, SIGNAL(Move(int, int)), &w, SLOT(move(int, int)));

	//xt.w = &w;
	xt.start();
	return a.exec();
}
