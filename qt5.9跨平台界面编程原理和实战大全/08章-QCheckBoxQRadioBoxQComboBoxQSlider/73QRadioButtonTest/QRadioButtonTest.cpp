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
#include "QRadioButtonTest.h"
#include <QRadioButton>
#include<QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QMessageBox>
QRadioButtonTest::QRadioButtonTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QRadioButton *rb1 = new QRadioButton("QRadioButton001");
	QRadioButton *rb2 = new QRadioButton("QRadioButton002");
	QRadioButton *rb3 = new QRadioButton("QRadioButton003");

	//��ť��
	QButtonGroup *group = new QButtonGroup(this);
	group->setObjectName("group");

	group->addButton(rb1);
	group->addButton(rb2);
	group->addButton(rb3);

	//��ֱ������
	QVBoxLayout *vb = new QVBoxLayout(this);
	
	//������ť��
	for (int i = 0; i < group->buttons().size(); i++)
	{
		vb->addWidget(group->buttons()[i]);
	}

	//���水ť
	QPushButton *save = new QPushButton("Save");
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(Save()));
	vb->addWidget(save);
}
void QRadioButtonTest::Save()
{
	//��ȡ��ť��
	QButtonGroup *group = this->findChild<QButtonGroup*>("group");
	if (!group)return;

	//��ȡ��ѡ�еİ�ť
	QRadioButton *but = (QRadioButton *)group->checkedButton();
	if (!but)
	{
		QMessageBox::warning(this, "", "Please checked!");
		return;
	}

	QMessageBox::information(this, "", but->text());
}