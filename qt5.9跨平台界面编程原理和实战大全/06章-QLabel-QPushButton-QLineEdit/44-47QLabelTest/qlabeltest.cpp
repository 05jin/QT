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
#include "qlabeltest.h"
#include <QMovie>
QLabelTest::QLabelTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QString str = QStringLiteral("测试的中文\n001xcj");
	//ui.label->setText(str);
	///手动创建QLabel 播放gif动画
	QLabel *lab2 = new QLabel(this);
	lab2->setGeometry(0, 0, 200, 200);
	lab2->setStyleSheet("background-color:rgb(161, 220, 247);");
	QMovie *mov = new QMovie("test.gif");
	lab2->setMovie(mov);
	lab2->show();
	mov->start();
}
