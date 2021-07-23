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
#include "testqimage.h"
#include <QPainter>
testQImage::testQImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	img = QImage(1280, 720, QImage::Format_RGBA8888);
	//填入颜色
	img.fill(QColor(255, 0, 0, 200));
	//遍历设置颜色
	uchar *data = img.bits();
	//假定已对齐,不对齐就出错
	for (int i = 0; i < img.width(); i++)
	{
		for (int j = 0; j < img.height()/2 ; j++)
		{ 
			data[j*img.width() * 4 + i * 4] = 0;// R
			data[j*img.width() * 4 + i * 4+1] = 255;// G
			data[j*img.width() * 4 + i * 4+1] = 0;// B
			data[j*img.width() * 4 + i * 4+1] = 255;// A
		}
	}

	for (int i = img.width()/2; i < img.width(); i++)
	{
		for (int j = 0; j < img.height(); j++)
		{
			img.setPixelColor(i, j, QColor(0, 0, 0, 255));
		}
	}
}
void testQImage::paintEvent(QPaintEvent *ev)
{
	QPainter p(this);
	if (!img.isNull())
		p.drawImage(0,0,img);
}