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
#include "qlabeltest.h"
#include <QMovie>
QLabelTest::QLabelTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QString str = QStringLiteral("���Ե�����\n001xcj");
	//ui.label->setText(str);
	///�ֶ�����QLabel ����gif����
	QLabel *lab2 = new QLabel(this);
	lab2->setGeometry(0, 0, 200, 200);
	lab2->setStyleSheet("background-color:rgb(161, 220, 247);");
	QMovie *mov = new QMovie("test.gif");
	lab2->setMovie(mov);
	lab2->show();
	mov->start();
}
