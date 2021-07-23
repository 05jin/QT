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
#include "QListWidgetTest.h"
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>
QListWidgetTest::QListWidgetTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//情况界面设计器添加的数据
	ui.listWidget->clear();

	//插入数据的多种方法
	QListWidgetItem *item1 = new QListWidgetItem;
	item1->setText(QString::fromLocal8Bit("测试数据1"));
	ui.listWidget->insertItem(0, item1);
	new QListWidgetItem("test item 2 ", ui.listWidget);
	ui.listWidget->addItem("test item 3");

	//插入包含图标的数据
	QListWidgetItem *itemIcon = new QListWidgetItem;
	itemIcon->setText("test item icon 4");
	itemIcon->setIcon(QIcon("test.jpg"));
	ui.listWidget->addItem(itemIcon);


	ui.listWidget->addItem("test item 9");
	ui.listWidget->addItem("test item 8");
	ui.listWidget->addItem("test item 5");


	//遍历列表
	for (int i = 0; i < ui.listWidget->count(); i++)
	{
		qDebug()<<ui.listWidget->item(i)->text();
	}

	//设置为可编辑状态
	//所有事件都激发编辑 双击 选择 选项变化
	ui.listWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	for (int i = 0; i < ui.listWidget->count(); i++)
	{
		ui.listWidget->item(i)->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	
	ui.listWidget->item(3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	
	
	//鼠标跟踪ItemEntered
	ui.listWidget->setMouseTracking(true);


	//显示QLineEdit控件
	QLineEdit *e = new QLineEdit("Test Line Edit");
	ui.listWidget->setItemWidget(ui.listWidget->item(4), e);

	//显示QSpinBox控件
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
	//遍历列表
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

//激活
void QListWidgetTest::ItemAct(QListWidgetItem *item)
{
	qDebug() << "ItemAct " << item->text();
}
//内容改变
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