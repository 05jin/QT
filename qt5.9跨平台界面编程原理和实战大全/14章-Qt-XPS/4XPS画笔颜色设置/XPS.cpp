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
#include "XPS.h"
#include <QColorDialog>
XPS::XPS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//打开图片
	connect(ui.openaction, SIGNAL(triggered()), ui.image, SLOT(Open()));
	col = QColor(200, 0, 0, 255);
}
void XPS::SetPen()
{
	ui.image->SetPen(ui.penSize->value(), col);
}
void XPS::SetColor()
{
	col = QColorDialog::getColor(Qt::red, this);
	QString sty = QString("background-color:rgba(%1,%2,%3,%4)")
		.arg(col.red()).arg(col.green()).arg(col.blue()).arg(col.alpha());
	ui.colorButton->setStyleSheet(sty);
	SetPen();
}