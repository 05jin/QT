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
#include "MenuWidget.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//����˵���
	QMenuBar *m = new QMenuBar(this);

	////��̬�˵� ����QMenu�����ӽڵ㣨�ӽڵ���ӽڵ㣩����
	connect(m, SIGNAL(hovered(QAction*)), this, SLOT(Hovered(QAction*)));

	m->resize(width(), m->height());
	//һ���˵�
	m1 = m->addMenu(QStringLiteral("�˵�1"));

	//����QMenu�����ӽڵ㣨�ӽڵ���ӽڵ㣩����
	connect(m1, SIGNAL(triggered(QAction*)), this, SLOT(Action(QAction*)));

	//�����˵�
	QAction *a1= m1->addAction(QStringLiteral("�����˵�1.1"));
	a1->setIcon(QIcon("test.jpg"));
	//QAction �����ź�
	connect(a1, SIGNAL(triggered()), this, SLOT(Action1()));
	//��ӿ�ݼ� A
	a1->setShortcut(QString("A"));
	

	QAction *a2 = m1->addAction(QStringLiteral("�����˵�1.2"));
	//QAction �����ͣ�ź�
	connect(a2, SIGNAL(hovered()), this, SLOT(Hover()));

	QAction *a3 = m1->addAction(QStringLiteral("�����˵�1.3"));
	a3->setIcon(QIcon("test.jpg"));

	a1->setCheckable(true);
	a2->setCheckable(true);
	a3->setCheckable(true);

	QActionGroup *ag = new QActionGroup(this);
	//ag->addAction(a1);
	ag->addAction(a2);
	ag->addAction(a3);
	//��ѡ
	ag->setExclusive(true);
	//�Ƿ�ѡ���¼�
	connect(a1, SIGNAL(triggered(bool)), this, SLOT(Action1(bool)));

	//�����˵�
	QMenu *m14 = m1->addMenu(QStringLiteral("�����˵�1.4"));
	m14->addAction(QStringLiteral("�����˵�1.4.1"));
	m14->setIcon(QIcon("test.jpg"));


	QMenu *m2 = m->addMenu(QStringLiteral("�˵�2"));

	m2->addAction(ui.actiontest);
	QMenu *m3 = m->addMenu(QStringLiteral("�˵�3"));


	////////////////////////////////////////////
	///������
	QToolBar *tbar = new QToolBar(this);
	tbar->setGeometry(0, m->height(), width(), 30);
	tbar->setIconSize(QSize(30, 30));
	tbar->addAction(a1);


	////////////////////////////////////////////
	///״̬��
	//ʵ����Ϣ��ʱ��ʧ
	QStatusBar * sbar = new QStatusBar(this);
	sbar->setGeometry(0, height() - 30, width(), 30);
	sbar->showMessage(QStringLiteral("������Ϣ������ʧ!"), 3000);

}

MenuWidget::~MenuWidget()
{
}

