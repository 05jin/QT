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
#include "QComboBoxTest.h"
#include <QDebug>
struct MyType
{
	int x = 0;
	int y = 0;
};
//ʹ��QT֧�ִ�����
Q_DECLARE_METATYPE(MyType);
void QComboBoxTest::Click()
{

	qDebug() << ui.comboBox->itemText(0);
	//�����û��Զ�������
	QVariant var = ui.comboBox->itemData(0);
	qDebug()<<"var.value<MyType>().x = "<<var.value<MyType>().x;
	ui.comboBox->setCurrentIndex(3);
}


void QComboBoxTest::Hi(int index)
{
	qDebug() << "Hi int = " << index;
}
//�û�ѡ�񣬺ʹ������
void QComboBoxTest::Cur(int index)
{
	qDebug() << "Cur int = " << index;
}
void QComboBoxTest::Cur(QString str)
{
	qDebug() << "Cur QString = " << str;
}

//ֻ���û�ѡ��
void QComboBoxTest::Act(int index)
{
	qDebug() << "Act int = " << index;
}
void QComboBoxTest::Act(QString str)
{
	qDebug() << "Act QString = " << str;
}
QComboBoxTest::QComboBoxTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//��������б�
	ui.comboBox->clear();


	//�����û��Զ�������
	QVariant var;
	MyType my;
	my.x = 101;
	var.setValue(my);
	ui.comboBox->addItem("Item001",var);


	ui.comboBox->addItem("Item002");

	//ͼ��
	QIcon icon(":/QComboBoxTest/Resources/test.png");
	ui.comboBox->addItem(icon, "Item003_icon");

	//�б���
	QStringList sl = {"Item004_list","Item005_list" };
	//sl.push_back("Item004_list");
	ui.comboBox->addItems(sl);

	//�ڶ���
	ui.comboBox->insertItem(1, "Item002_insert");

}
