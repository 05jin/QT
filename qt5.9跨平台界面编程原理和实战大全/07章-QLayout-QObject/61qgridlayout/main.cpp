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
#include "qgridlayout.h"
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include <QPushButton>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget *win = new QWidget;
	QGridLayout *gl = new QGridLayout(win);
	QPushButton *but11 = new QPushButton("but11");
	gl->addWidget(but11, 0, 0);
	QPushButton *but12 = new QPushButton("but12");
	but12->setMinimumSize(100, 100);
	but12->setMaximumSize(500, 500);
	but12->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	gl->addWidget(but12, 0, 1);

	QPushButton *but13 = new QPushButton("but13");
	gl->addWidget(but13, 0, 2);
	QPushButton *but21 = new QPushButton("but21");
	gl->addWidget(but21, 1, 0);
	QPushButton *but23 = new QPushButton("but23");
	gl->addWidget(but23, 1, 2);

	//ˮƽ���
	gl->setHorizontalSpacing(10);

	//��ֱ���
	gl->setVerticalSpacing(10);


	win->show();

	///qgridlayout w;
	//w.show();
	return a.exec();
}
