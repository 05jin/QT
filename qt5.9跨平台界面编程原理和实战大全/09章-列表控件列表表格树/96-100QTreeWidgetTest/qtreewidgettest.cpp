/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：夏曹俊，此代码可用作为学习参考                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Contact       : xiacaojun@qq.com
**        博客   : http://blog.csdn.net/jiedichina
**		视频课程 : http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961
**                 http://edu.51cto.com/lecturer/12016059.html
**                 http://study.163.com/u/xiacaojun
**                 https://jiedi.ke.qq.com/
**   购买课程后请加入《QT5跨平台界面编程》452758022 QQ群，可在群中咨询课程问题和下载源码
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
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
	//清理测试的标题,不清理数据
	//ui.treeWidget->setColumnCount(0); //不会清理
	ui.treeWidget->setHeaderItem(new QTreeWidgetItem());

	//清理测试数据
	ui.treeWidget->clear();

	//ui.treeWidget->setColumnCount(3);
	//设置标题，设置四列
	ui.treeWidget->headerItem()->setText(0, QStringLiteral("标题1"));
	ui.treeWidget->headerItem()->setText(1, "head2");
	ui.treeWidget->headerItem()->setText(2, "head3");
	ui.treeWidget->headerItem()->setText(3, "head4");
	//ui.treeWidget->headerItem()->setText(5, "head4");
	qDebug() << "ColumnCount" << ui.treeWidget->columnCount();

	////////////////////////////////////////////////////////////////////////////////////////
	//插入数据
	//结尾处插入
	ui.treeWidget->addTopLevelItem(new QTreeWidgetItem());
	ui.treeWidget->topLevelItem(0)->setText(0,"tree node1");
	ui.treeWidget->topLevelItem(0)->setText(1, "tree node1 col2");

	ui.treeWidget->addTopLevelItem(new QTreeWidgetItem({"tree node2 col1","tree node2 col2"}));

	//开头插入
	ui.treeWidget->insertTopLevelItem(0, new QTreeWidgetItem({ "tree node1-1 col1","tree node1-1 col2" }));

	//结尾插入
	ui.treeWidget->insertTopLevelItem(ui.treeWidget->topLevelItemCount(), new QTreeWidgetItem({ "tree node end col1" }));

	//结尾插入
	QTreeWidgetItem *node = new QTreeWidgetItem(ui.treeWidget);
	node->setText(0, "new ");


	//插入子节点
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child1" }));
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child2" }));
	ui.treeWidget->topLevelItem(0)->addChild(new QTreeWidgetItem({ "child3" }));

	//插入孙节点
	ui.treeWidget->topLevelItem(0)->child(1)->addChild(new QTreeWidgetItem({ "grandSon" }));

	ui.treeWidget->topLevelItem(1)->addChild(new QTreeWidgetItem({ "2 - child1" }));
	ui.treeWidget->topLevelItem(1)->addChild(new QTreeWidgetItem({ "2 - child2" }));

	//插入图标
	ui.treeWidget->setIconSize(QSize(60, 60));
	ui.treeWidget->topLevelItem(0)->setIcon(0, QIcon("test.jpg"));

	//插入Widget控件
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

	//清空历史数据
	while (item->childCount() > 0)
	{
		item->removeChild(item->child(0));
	}

	//动态插入子节点
	item->addChild(new QTreeWidgetItem({ "new tree1" }));
	item->addChild(new QTreeWidgetItem({ "new tree2" }));
	item->addChild(new QTreeWidgetItem({ "new tree3" }));
}