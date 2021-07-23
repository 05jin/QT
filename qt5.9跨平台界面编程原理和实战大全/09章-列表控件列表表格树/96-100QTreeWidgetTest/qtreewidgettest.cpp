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
#include "qtreewidgettest.h"
#include <QDebug>
#include <QPushButton>
QTreeWidgetTest::QTreeWidgetTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//������Եı���,����������
	//ui.treeWidget->setColumnCount(0); //��������
	ui.treeWidget->setHeaderItem(new QTreeWidgetItem());

	//�����������
	ui.treeWidget->clear();

	//ui.treeWidget->setColumnCount(3);
	//���ñ��⣬��������
	ui.treeWidget->headerItem()->setText(0, QStringLiteral("����1"));
	ui.treeWidget->headerItem()->setText(1, "head2");
	ui.treeWidget->headerItem()->setText(2, "head3");
	ui.treeWidget->headerItem()->setText(3, "head4");
	//ui.treeWidget->headerItem()->setText(5, "head4");
	qDebug() << "ColumnCount" << ui.treeWidget->columnCount();

	////////////////////////////////////////////////////////////////////////////////////////
	//��������
	//��β������
	ui.treeWidget->addTopLevelItem(new QTreeWidgetItem());
	ui.treeWidget->topLevelItem(0)->setText(0,"tree node1");
	ui.treeWidget->topLevelItem(0)->setText(1, "tree node1 col2");

	ui.treeWidget->addTopLevelItem(new QTreeWidgetItem({"tree node2 col1","tree node2 col2"}));

	//��ͷ����
	ui.treeWidget->insertTopLevelItem(0, new QTreeWidgetItem({ "tree node1-1 col1","tree node1-1 col2" }));

	//��β����
	ui.treeWidget->insertTopLevelItem(ui.treeWidget->topLevelItemCount(), new QTreeWidgetItem({ "tree node end col1" }));

	//��β����
	QTreeWidgetItem *node = new QTreeWidgetItem(ui.treeWidget);
	node->setText(0, "new ");


	//�����ӽڵ�
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child1" }));
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child2" }));
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child3" }));

	//������ڵ�
	ui.treeWidget->topLevelItem(0)->child(1)->addChild(new QTreeWidgetItem({ "grandSon" }));

	ui.treeWidget->topLevelItem(1)->addChild(new QTreeWidgetItem({ "2 - child1" }));
	ui.treeWidget->topLevelItem(1)->addChild(new QTreeWidgetItem({ "2 - child2" }));

	//����ͼ��
	ui.treeWidget->setIconSize(QSize(60, 60));
	ui.treeWidget->topLevelItem(0)->setIcon(0, QIcon("test.jpg"));

	//����Widget�ؼ�
	QPushButton *bu = new QPushButton("Test");
	ui.treeWidget->setItemWidget(ui.treeWidget->topLevelItem(1), 0, bu);

	ui.treeWidget->setMouseTracking(true);
}


void QTreeWidgetTest::Click(QTreeWidgetItem *item)
{
	qDebug() << "Click " << item->text(0);
}

void QTreeWidgetTest::Double(QTreeWidgetItem *item)
{
	qDebug() << "Double " << item->text(0);
}


void QTreeWidgetTest::Hover(QTreeWidgetItem *item)
{
	qDebug() << "Hover " << item->text(0);
	//ui.treeWidget->expandItem(item);
}
void QTreeWidgetTest::Expand(QTreeWidgetItem *item)
{
	qDebug() << "Expand " << item->text(0);

	//�����ʷ����
	while (item->childCount() > 0)
	{
		item->removeChild(item->child(0));
	}

	//��̬�����ӽڵ�
	item->addChild(new QTreeWidgetItem({ "new tree1" }));
	item->addChild(new QTreeWidgetItem({ "new tree2" }));
	item->addChild(new QTreeWidgetItem({ "new tree3" }));
}