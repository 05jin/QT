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
#include "qtablewidgettest.h"
#include <QDebug>
#include <QLabel>
#include <set>
#include <QMessageBox>
class MyHead :public QTableWidgetItem
{
public:
	MyHead(QString txt) :QTableWidgetItem(txt)
	{

	}
	~MyHead()
	{
		qDebug() << this->text() << " removed!";
	}
};

QTableWidgetTest::QTableWidgetTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	//////////////////////////////////////////////
	//清空所有标题和内容
	ui.tableWidget->setColumnCount(0);
	ui.tableWidget->setRowCount(0);


	//////////////////////////////////////////////
	//插入水平标题
	ui.tableWidget->setColumnCount(5);
	ui.tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Head1"));
	ui.tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem);
	ui.tableWidget->horizontalHeaderItem(1)->setText("Head2");
	
	ui.tableWidget->setHorizontalHeaderItem(2, new MyHead("H3"));
	//插入标题，会清理之前的对象
	ui.tableWidget->setHorizontalHeaderItem(2, new MyHead("Head3"));

	ui.tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Head4"));
	ui.tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Head5"));

	//////////////////////////////////////////////
	//设定标题列的宽度
	ui.tableWidget->setColumnWidth(0, 200);
	
	//////////////////////////////////////////////
	//设置垂直标题
	ui.tableWidget->setRowCount(3);
	QStringList list = { "row1","row2","row3" };
	//list.push_back("col1");
	ui.tableWidget->setVerticalHeaderLabels(list);

	//////////////////////////////////////////////
	//插入数据
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem("col 0,0"));
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem("col 0,1"));
	ui.tableWidget->setItem(0, 2, new QTableWidgetItem("col 0,2"));
	ui.tableWidget->setItem(1, 0, new QTableWidgetItem("col 1,0"));
	ui.tableWidget->setItem(2, 0, new QTableWidgetItem("col 2,0"));

	//结尾添加一行
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
	ui.tableWidget->setItem(row, 0, new QTableWidgetItem("new row 4"));
	
	//开始添加一行
	ui.tableWidget->insertRow(0);
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem("new row 0"));

	//////////////////////////////////////////////
	//插入QIcon 图片
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem("new row 1"));
	ui.tableWidget->item(0, 1)->setIcon(QIcon("test.jpg"));
	//设置行高
	ui.tableWidget->setRowHeight(0,80);
	//设置图标显示大小
	ui.tableWidget->setIconSize(QSize(ui.tableWidget->rowHeight(0), ui.tableWidget->rowHeight(0)));


	//////////////////////////////////////////////
	//插入widget 图片
	QLabel *img = new QLabel();
	QPixmap pix("test.jpg");
	//缩放到和表格单元的宽高一致
	pix = pix.scaled(ui.tableWidget->columnWidth(0),ui.tableWidget->rowHeight(row));
	img->setPixmap(pix);
	ui.tableWidget->setCellWidget(row, 0, img);

	//插入空数据
	ui.tableWidget->insertRow(0);
	ui.tableWidget->insertRow(0);

	//设置鼠标跟踪，itemEnter事件生效
	ui.tableWidget->setMouseTracking(true);


	//标题栏点击信号
	//void sectionClicked(int logicalIndex)
	connect(ui.tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)),
		this, SLOT(SectionClicked(int)) );
}

void QTableWidgetTest::Del()
{
	//空行无法选择
	QList<QTableWidgetItem*> items = ui.tableWidget->selectedItems();
	qDebug() << "=====================================";
	for (int i = 0; i < items.size(); i++)
	{
		qDebug() <<items[i]->row()<<":"<<items[i]->column()<<" text="<< items[i]->text();
	}
	//选择模式器
	QItemSelectionModel *smodel = ui.tableWidget->selectionModel();
	//获取所有的选择索引
	QModelIndexList slist = smodel->selectedIndexes();
	
	//获取所有被选中的行号
	std::set<int> rows;
	for (int i = 0; i < slist.size(); i++)
	{
		//重复的插入失败
		rows.insert(slist[i].row());
	}

	//给用户提示
	QString msg = QStringLiteral("您确认删除:");

	for (std::set<int>::iterator itr = rows.begin(); itr != rows.end(); itr++)
	{
		QTableWidgetItem *item = ui.tableWidget->item(*itr, 0);
		msg += "[";
		msg += QString::number(*itr+1);
		msg += ":";
		if (item)
			msg += item->text();
		msg += "]";
	}
	int re = QMessageBox::information(this, "", msg, QStringLiteral("确认"), QStringLiteral("取消"));
	if (re != 0)
	{
		return;
	}

	//删除多行
	for (;;)
	{
		//获取所有的选择索引
		QModelIndexList s = smodel->selectedIndexes();
		if (s.size() <= 0) break;
		//每次只删除一行
		ui.tableWidget->removeRow(s[0].row());
	}


}

void QTableWidgetTest::Click(int row, int column)
{
	QString msg = "Click = ";
	QTableWidgetItem *item = ui.tableWidget->item(row, column);
	msg += QString::number(row);
	msg += ",";
	msg += QString::number(column);
	msg += " ";
	if (item)
	{

		msg += item->text();
	}
	qDebug() << msg;
}
void QTableWidgetTest::Double(int row, int column)
{
	QString msg = "Double  = ";
	QTableWidgetItem *item = ui.tableWidget->item(row, column);
	msg += QString::number(row);
	msg += ",";
	msg += QString::number(column);
	msg += " ";
	if (item)
	{

		msg += item->text();
	}
	qDebug() << msg;
}

//元素修改
void QTableWidgetTest::Change(int row, int column)
{
	QString msg = "Change  = ";
	QTableWidgetItem *item = ui.tableWidget->item(row, column);
	msg += QString::number(row);
	msg += ",";
	msg += QString::number(column);
	msg += " ";
	if (item)
	{

		msg += item->text();
	}
	qDebug() << msg;
}


//顶部标题点击
void QTableWidgetTest::SectionClicked(int col)
{
	//获取标题文本
	QTableWidgetItem *h = ui.tableWidget->horizontalHeaderItem(col);
	qDebug() << "SectionClicked " << col;
	if (h)
	{
		qDebug() << h->text();
	}
}

void QTableWidgetTest::CellEntered(int row, int column)
{
	QString msg = "CellEntered = ";
	QTableWidgetItem *item = ui.tableWidget->item(row, column);
	msg += QString::number(row);
	msg += ",";
	msg += QString::number(column);
	msg += " ";
	if (item)
	{

		msg += item->text();
	}
	qDebug() << msg;
}

void QTableWidgetTest::ItemEntered(QTableWidgetItem *item)
{
	QString msg = "ItemEntered = ";
	if (item)
	{
		msg += QString::number(item->row());
		msg += ",";
		msg += QString::number(item->column());
		msg += " ";
		msg += item->text();
	}
	qDebug() << msg;
}