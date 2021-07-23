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
#include <QtCore/QCoreApplication>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget *win = new QWidget;
	win->resize(400, 400);
	
	//垂直布局  构造函数中传递widget
	//QVBoxLayout *lay = new QVBoxLayout();

	//水平布局
	QHBoxLayout *lay = new QHBoxLayout();
	win->setLayout(lay);

	QPushButton *but1 = new QPushButton("button1");
	lay->addWidget(but1);
	but1->resize(200, 200);

	//水平 垂直 fixed使用推荐大小
	but1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	//尽量缩放，最小值是推荐值
	but1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	//忽略推荐大小，尽量缩放
	but1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	but1->setMinimumSize(100, 50);
	but1->setMaximumSize(500, 100);


	QPushButton *but2 = new QPushButton("button2");
	lay->addWidget(but2);

	QPushButton *but3 = new QPushButton("button3");
	lay->addWidget(but3);
	
	//边框距离
	lay->setContentsMargins(0, 0, 0, 0);

	//元素间距
	lay->setSpacing(0);

	win->show();

	qDebug() << but1->sizeHint().width() << ":" << but1->sizeHint().height();
	
	qDebug() << but1->width() << ":" << but1->height();

	return a.exec();
}
