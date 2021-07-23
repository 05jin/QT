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
#include "QComboBoxTest.h"
#include <QDebug>
struct MyType
{
	int x = 0;
	int y = 0;
};
//使得QT支持此类型
Q_DECLARE_METATYPE(MyType);
void QComboBoxTest::Click()
{

	qDebug() << ui.comboBox->itemText(0);
	//访问用户自定义数据
	QVariant var = ui.comboBox->itemData(0);
	qDebug()<<"var.value<MyType>().x = "<<var.value<MyType>().x;
	ui.comboBox->setCurrentIndex(3);
}


void QComboBoxTest::Hi(int index)
{
	qDebug() << "Hi int = " << index;
}
//用户选择，和代码调用
void QComboBoxTest::Cur(int index)
{
	qDebug() << "Cur int = " << index;
}
void QComboBoxTest::Cur(QString str)
{
	qDebug() << "Cur QString = " << str;
}

//只有用户选择
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
	//清空所有列表
	ui.comboBox->clear();


	//插入用户自定义数据
	QVariant var;
	MyType my;
	my.x = 101;
	var.setValue(my);
	ui.comboBox->addItem("Item001",var);


	ui.comboBox->addItem("Item002");

	//图标
	QIcon icon(":/QComboBoxTest/Resources/test.png");
	ui.comboBox->addItem(icon, "Item003_icon");

	//列表项
	QStringList sl = {"Item004_list","Item005_list" };
	//sl.push_back("Item004_list");
	ui.comboBox->addItems(sl);

	//第二行
	ui.comboBox->insertItem(1, "Item002_insert");

}
