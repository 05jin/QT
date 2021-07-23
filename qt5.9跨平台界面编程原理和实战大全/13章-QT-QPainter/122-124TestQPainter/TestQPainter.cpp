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

#include "TestQPainter.h"
#include <QPainter>

TestQPainter::TestQPainter(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}


void TestQPainter::paintEvent(QPaintEvent *ev)
{
	//设置绘制设备 （widget）
	QPainter p(this);
	//p.begin(this);

	//设置画笔颜色
	p.setPen(QColor(255, 0, 0, 150));

	//设置字体
	//p.setFont(QFont(QStringLiteral("黑体"), 30));
	QFont font = ui.fontComboBox->currentFont();
	font.setPixelSize(30);
	p.setFont(font);

	//绘制文本
	p.drawText(100, 100, QStringLiteral("测试的显示文字"));
	

	//绘制线
	//设置画笔样式
	QPen pen;
	//实线
	pen.setStyle(Qt::SolidLine);
	//线粗
	pen.setWidth(30);
	//线刷子
	pen.setBrush(Qt::red);

	//刷子为图片
	pen.setBrush(QBrush(QImage("test.jpg")));

	//结尾端样式
	pen.setCapStyle(Qt::RoundCap);

	//连接处样式
	pen.setJoinStyle(Qt::RoundJoin);

	p.setPen(pen);
	p.drawLine(QLine(0, 0, 300, 300));
	p.drawLine(QLine(300, 300, 600, 0));

	QVector<QLine> lines;
	lines.push_back(QLine(0, 0, 350, 350));
	lines.push_back(QLine(350, 350, 0, 450));
	lines.push_back(QLine(0, 450, 550, 550));
	p.drawLines(lines);
	p.end();
}