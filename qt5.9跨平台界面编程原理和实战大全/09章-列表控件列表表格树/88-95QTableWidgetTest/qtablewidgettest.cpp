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
	//������б��������
	ui.tableWidget->setColumnCount(0);
	ui.tableWidget->setRowCount(0);


	//////////////////////////////////////////////
	//����ˮƽ����
	ui.tableWidget->setColumnCount(5);
	ui.tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Head1"));
	ui.tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem);
	ui.tableWidget->horizontalHeaderItem(1)->setText("Head2");
	
	ui.tableWidget->setHorizontalHeaderItem(2, new MyHead("H3"));
	//������⣬������֮ǰ�Ķ���
	ui.tableWidget->setHorizontalHeaderItem(2, new MyHead("Head3"));

	ui.tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Head4"));
	ui.tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Head5"));

	//////////////////////////////////////////////
	//�趨�����еĿ��
	ui.tableWidget->setColumnWidth(0, 200);
	
	//////////////////////////////////////////////
	//���ô�ֱ����
	ui.tableWidget->setRowCount(3);
	QStringList list = { "row1","row2","row3" };
	//list.push_back("col1");
	ui.tableWidget->setVerticalHeaderLabels(list);

	//////////////////////////////////////////////
	//��������
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem("col 0,0"));
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem("col 0,1"));
	ui.tableWidget->setItem(0, 2, new QTableWidgetItem("col 0,2"));
	ui.tableWidget->setItem(1, 0, new QTableWidgetItem("col 1,0"));
	ui.tableWidget->setItem(2, 0, new QTableWidgetItem("col 2,0"));

	//��β���һ��
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
	ui.tableWidget->setItem(row, 0, new QTableWidgetItem("new row 4"));
	
	//��ʼ���һ��
	ui.tableWidget->insertRow(0);
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem("new row 0"));

	//////////////////////////////////////////////
	//����QIcon ͼƬ
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem("new row 1"));
	ui.tableWidget->item(0, 1)->setIcon(QIcon("test.jpg"));
	//�����и�
	ui.tableWidget->setRowHeight(0,80);
	//����ͼ����ʾ��С
	ui.tableWidget->setIconSize(QSize(ui.tableWidget->rowHeight(0), ui.tableWidget->rowHeight(0)));


	//////////////////////////////////////////////
	//����widget ͼƬ
	QLabel *img = new QLabel();
	QPixmap pix("test.jpg");
	//���ŵ��ͱ��Ԫ�Ŀ��һ��
	pix = pix.scaled(ui.tableWidget->columnWidth(0),ui.tableWidget->rowHeight(row));
	img->setPixmap(pix);
	ui.tableWidget->setCellWidget(row, 0, img);

	//���������
	ui.tableWidget->insertRow(0);
	ui.tableWidget->insertRow(0);

	//���������٣�itemEnter�¼���Ч
	ui.tableWidget->setMouseTracking(true);


	//����������ź�
	//void sectionClicked(int logicalIndex)
	connect(ui.tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)),
		this, SLOT(SectionClicked(int)) );
}

void QTableWidgetTest::Del()
{
	//�����޷�ѡ��
	QList<QTableWidgetItem*> items = ui.tableWidget->selectedItems();
	qDebug() << "=====================================";
	for (int i = 0; i < items.size(); i++)
	{
		qDebug() <<items[i]->row()<<":"<<items[i]->column()<<" text="<< items[i]->text();
	}
	//ѡ��ģʽ��
	QItemSelectionModel *smodel = ui.tableWidget->selectionModel();
	//��ȡ���е�ѡ������
	QModelIndexList slist = smodel->selectedIndexes();
	
	//��ȡ���б�ѡ�е��к�
	std::set<int> rows;
	for (int i = 0; i < slist.size(); i++)
	{
		//�ظ��Ĳ���ʧ��
		rows.insert(slist[i].row());
	}

	//���û���ʾ
	QString msg = QStringLiteral("��ȷ��ɾ��:");

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
	int re = QMessageBox::information(this, "", msg, QStringLiteral("ȷ��"), QStringLiteral("ȡ��"));
	if (re != 0)
	{
		return;
	}

	//ɾ������
	for (;;)
	{
		//��ȡ���е�ѡ������
		QModelIndexList s = smodel->selectedIndexes();
		if (s.size() <= 0) break;
		//ÿ��ֻɾ��һ��
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

//Ԫ���޸�
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


//����������
void QTableWidgetTest::SectionClicked(int col)
{
	//��ȡ�����ı�
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