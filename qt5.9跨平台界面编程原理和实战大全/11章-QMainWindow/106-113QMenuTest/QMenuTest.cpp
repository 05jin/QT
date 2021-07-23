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
#include "QMenuTest.h"

QMenuTest::QMenuTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//�˵���
	this->menuBar()->addAction("TestMenu1");

	//״̬��
	this->statusBar()->showMessage("status Bar");

	//������
	ui.mainToolBar->addAction(QStringLiteral("��ťһ"));

	ui.mainToolBar->addAction(QIcon("test.jpg"),QStringLiteral("��ť��"));

	//�ļ���ʾ��ͼ������
	ui.mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//����������
	this->addToolBarBreak();

	//Ĭ�϶�������
	QToolBar *t2 = this->addToolBar("tool2");
	t2->addAction(QStringLiteral("����"));
	

	//���
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("���"));
		this->addToolBar(Qt::LeftToolBarArea, t);
	}

	//�Ҳ�
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("�Ҳ�"));
		this->addToolBar(Qt::RightToolBarArea, t);
	}

	//�ײ�
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("�ײ�"));
		this->addToolBar(Qt::BottomToolBarArea, t);
	}

}
