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

#include "QButtonGroupCheckbox.h"
#include <QDebug>
QButtonGroupCheckbox::QButtonGroupCheckbox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QButtonGroup *group = new QButtonGroup(this);
	//�����Ĭ�ϱ�Ϊ��ѡ
	group->addButton(ui.checkBox1);
	group->addButton(ui.checkBox2);
	group->addButton(ui.checkBox3);
	//��Ϊ��ѡ
	//group->setExclusive(false);

	//�ֶ�����¼�
	QObject::connect(group, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(GClick(QAbstractButton *)));

	//״̬�仯�����¼�
	QObject::connect(group, SIGNAL(buttonToggled(QAbstractButton *,bool)), this, SLOT(GToggle(QAbstractButton *, bool)));
}
void QButtonGroupCheckbox::GClick(QAbstractButton *but)
{
	qDebug() <<"GClick:" <<but << but->isChecked();
}
void QButtonGroupCheckbox::GToggle(QAbstractButton *but, bool check)
{
	qDebug() <<"GToggle:"<< but << check;
}