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
#include "QDialogTest.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "xmessagebox.h"
#include "progreedialog.h"
#include "TestPro.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestPro tp;
	//���ؽ�������ʾ
	ProgreedDialog p;
	//���ź�
	QObject::connect(&tp, SIGNAL(SetPos(int)), &p, SLOT(SetPos(int)));
	//�����߳�
	tp.start();

	p.exec();
	


	


	qDebug() << XMessageBox::info(QStringLiteral("�����²������ʾ!"));
	//XMessageBox box;
	//box.exec();


	QDialogTest w;

	//QDialog d;
	//d.setWindowTitle("New Dialog");
	//�����з���ֵ
	//int re = d.exec();
	int re = w.exec();
	qDebug() << "re = " << re;
	qDebug() << "result() = " << w.result();
	switch (re)
	{
	case QDialog::Accepted:
		qDebug() << "Accepted";
		break;
	case QDialog::Rejected:
		qDebug() << "Rejected";
		break;
	default:
		qDebug() << re;
		break;
	}

	
	//w.show();



	return a.exec();
}
