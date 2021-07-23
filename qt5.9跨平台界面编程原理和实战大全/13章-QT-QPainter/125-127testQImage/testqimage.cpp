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
#include "testqimage.h"
#include <QPainter>
testQImage::testQImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	img = QImage(1280, 720, QImage::Format_RGBA8888);
	//������ɫ
	img.fill(QColor(255, 0, 0, 200));
	//����������ɫ
	uchar *data = img.bits();
	//�ٶ��Ѷ���,������ͳ���
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