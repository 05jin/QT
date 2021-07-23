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
#include "ximage.h"
#include <QPainter>
#include <QFileDialog>
#include <QMouseEvent>
XImage::XImage(QWidget *parent)
	: QWidget(parent)
{
}

XImage::~XImage()
{
}
void XImage::Open()
{
	//打开图像 用户选择图片
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("打开图片"),"",
QStringLiteral("支持格式(*.png *.jpg *.bmp)") );
	if (filename.isEmpty())return;
	if (!src.load(filename))return;
	resize(src.size());
	mpos = QPoint();
	out = src.copy();
	
}
void XImage::Save()
{
	if (out.isNull())return;
	QString filename = QFileDialog::getSaveFileName(this,
		QStringLiteral("保存文件"), ""
		, QStringLiteral("支持格式(*.png *.jpg *.bmp)"));
	if (filename.isNull())return;
	if (!out.save(filename))return;
}

void XImage::paintEvent(QPaintEvent *ev)
{
	QPainter p(this);

	//显示图片
	if (!out.isNull())
		p.drawImage(0, 0, out);
}
void XImage::SetPen(int size, QColor col)
{
	pen.setWidth(size);
	pen.setBrush(col);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
}

//橡皮擦
void XImage::SetEraser(int size)
{
	pen.setWidth(size);
	//用原图做画笔，实现恢复
	pen.setBrush(QBrush(src));
}


void XImage::mouseMoveEvent(QMouseEvent *ev)
{
	//绘制到原图中
	if (out.isNull())return;
	QPainter p(&out);
	//开启抗锯齿
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(pen);
	if (mpos.isNull()) mpos = ev->pos();
	p.drawLine(QLine(mpos, ev->pos()));
	mpos = ev->pos();
	update();
}