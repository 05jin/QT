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
	update();
}
void XImage::paintEvent(QPaintEvent *ev)
{
	QPainter p(this);

	//��ʾԭͼ
	if (!src.isNull())
		p.drawImage(0, 0, src);
}