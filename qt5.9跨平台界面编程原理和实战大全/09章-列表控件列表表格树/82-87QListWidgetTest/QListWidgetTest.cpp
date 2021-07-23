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
#include "QListWidgetTest.h"
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>
QListWidgetTest::QListWidgetTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//��������������ӵ�����
	ui.listWidget->clear();

	//�������ݵĶ��ַ���
	QListWidgetItem *item1 = new QListWidgetItem;
	item1->setText(QString::fromLocal8Bit("��������1"));
	ui.listWidget->insertItem(0, item1);
	new QListWidgetItem("test item 2 ", ui.listWidget);
	ui.listWidget->addItem("test item 3");

	//�������ͼ�������
	QListWidgetItem *itemIcon = new QListWidgetItem;
	itemIcon->setText("test item icon 4");
	itemIcon->setIcon(QIcon("test.jpg"));
	ui.listWidget->addItem(itemIcon);


	ui.listWidget->addItem("test item 9");
	ui.listWidget->addItem("test item 8");
	ui.listWidget->addItem("test item 5");


	//�����б�
	for (int i = 0; i < ui.listWidget->count(); i++)
	{
		qDebug()<<ui.listWidget->item(i)->text();
	}

	//����Ϊ�ɱ༭״̬
	//�����¼��������༭ ˫�� ѡ�� ѡ��仯
	ui.listWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	for (int i = 0; i < ui.listWidget->count(); i++)
	{
		ui.listWidget->item(i)->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	
	ui.listWidget->item(3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	
	
	//������ItemEntered
	ui.listWidget->setMouseTracking(true);


	//��ʾQLineEdit�ؼ�
	QLineEdit *e = new QLineEdit("Test Line Edit");
	ui.listWidget->setItemWidget(ui.listWidget->item(4), e);

	//��ʾQSpinBox�ؼ�
	QSpinBox *  s = new QSpinBox();
	ui.listWidget->setItemWidget(ui.listWidget->item(5), s);

}

void QListWidgetTest::Sort()
{
	static bool isDesc = false;
	if (!isDesc)
	{
		ui.listWidget->sortItems(Qt::DescendingOrder);
	}
	else
	{
		ui.listWidget->sortItems(Qt::AscendingOrder);
	}
	isDesc = !isDesc;
}

void QListWidgetTest::Click()
{
	//�����б�
	for (int i = 0; i < ui.listWidget->count(); i++)
	{
		qDebug() << ui.listWidget->item(i)->text();
	}
}


void QListWidgetTest::CurChange(QListWidgetItem *cur, QListWidgetItem *pre)
{
	
	qDebug() << "CurChange QListWidgetItem" << cur->text();
	if (pre)
	{
		qDebug() << "Pre =  " << pre->text();
	}
}

void QListWidgetTest::CurChange(int row)
{
	qDebug() << "CurChange row" << row;
}

void QListWidgetTest::CurChange(const QString &txt)
{
	qDebug() << "CurChange QString " << txt;
}

//����
void QListWidgetTest::ItemAct(QListWidgetItem *item)
{
	qDebug() << "ItemAct " << item->text();
}
//���ݸı�
void QListWidgetTest::ItemChange(QListWidgetItem *item)
{
	qDebug() << "ItemChange " << item->text();
}

void QListWidgetTest::ItemClick(QListWidgetItem *item)
{
	qDebug() << "ItemClick " << item->text();
}

void QListWidgetTest::ItemDoubleClick(QListWidgetItem *item)
{
	qDebug() << "ItemDoubleClick " << item->text();
}

void QListWidgetTest::ItemEntered(QListWidgetItem *item)
{
	qDebug() << "ItemEnterd " << item->text();
}

void QListWidgetTest::ItemPressed(QListWidgetItem *item)
{
	qDebug() << "ItemPressed " << item->text();
}