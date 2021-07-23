/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               �������Ĳܿ����˴��������Ϊѧϰ�ο�                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Contact       : xiacaojun@qq.com
**        ����   : http://blog.csdn.net/jiedichina
**		��Ƶ�γ� : http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961
**                 http://edu.51cto.com/lecturer/12016059.html
**                 http://study.163.com/u/xiacaojun
**                 https://jiedi.ke.qq.com/
**   ����γ̺�����롶QT5��ƽ̨�����̡�452758022 QQȺ������Ⱥ����ѯ�γ����������Դ��
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
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
	//��ͼ�� �û�ѡ��ͼƬ
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("��ͼƬ"),"",
QStringLiteral("֧�ָ�ʽ(*.png *.jpg *.bmp)") );
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
		QStringLiteral("�����ļ�"), ""
		, QStringLiteral("֧�ָ�ʽ(*.png *.jpg *.bmp)"));
	if (filename.isNull())return;
	if (!out.save(filename))return;
}

void XImage::paintEvent(QPaintEvent *ev)
{
	QPainter p(this);

	//��ʾͼƬ
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

//��Ƥ��
void XImage::SetEraser(int size)
{
	pen.setWidth(size);
	//��ԭͼ�����ʣ�ʵ�ָֻ�
	pen.setBrush(QBrush(src));
}


void XImage::mouseMoveEvent(QMouseEvent *ev)
{
	//���Ƶ�ԭͼ��
	if (out.isNull())return;
	QPainter p(&out);
	//���������
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(pen);
	if (mpos.isNull()) mpos = ev->pos();
	p.drawLine(QLine(mpos, ev->pos()));
	mpos = ev->pos();
	update();
}