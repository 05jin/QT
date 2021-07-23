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
#include "QSliderTest.h"
#include <QDebug>
QSliderTest::QSliderTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

//�϶�������
void QSliderTest::Move(int v)
{
	qDebug() << "Move " << v;
}
//������϶���ֱ������
void QSliderTest::Change(int v)
{
	qDebug() << "Change " << v;
}

//�������
void QSliderTest::Press()
{
	qDebug() << "Press " << ui.horizontalSlider->value();
}
void QSliderTest::Rel()
{
	qDebug() << "Rel " << ui.horizontalSlider->value();
}
void QSliderTest::Click()
{
	int v = ui.horizontalSlider->value() + 10;
	ui.horizontalSlider->setValue(v);
}