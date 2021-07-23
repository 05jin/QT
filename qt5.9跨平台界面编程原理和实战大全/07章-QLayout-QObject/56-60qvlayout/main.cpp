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
#include <QtCore/QCoreApplication>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget *win = new QWidget;
	win->resize(400, 400);
	
	//��ֱ����  ���캯���д���widget
	//QVBoxLayout *lay = new QVBoxLayout();

	//ˮƽ����
	QHBoxLayout *lay = new QHBoxLayout();
	win->setLayout(lay);

	QPushButton *but1 = new QPushButton("button1");
	lay->addWidget(but1);
	but1->resize(200, 200);

	//ˮƽ ��ֱ fixedʹ���Ƽ���С
	but1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	//�������ţ���Сֵ���Ƽ�ֵ
	but1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	//�����Ƽ���С����������
	but1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	but1->setMinimumSize(100, 50);
	but1->setMaximumSize(500, 100);


	QPushButton *but2 = new QPushButton("button2");
	lay->addWidget(but2);

	QPushButton *but3 = new QPushButton("button3");
	lay->addWidget(but3);
	
	//�߿����
	lay->setContentsMargins(0, 0, 0, 0);

	//Ԫ�ؼ��
	lay->setSpacing(0);

	win->show();

	qDebug() << but1->sizeHint().width() << ":" << but1->sizeHint().height();
	
	qDebug() << but1->width() << ":" << but1->height();

	return a.exec();
}
