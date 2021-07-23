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
#include "QFormLayoutTest.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
QFormLayoutTest::QFormLayoutTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFormLayout *lay = new QFormLayout(this);
	QLineEdit *name = new QLineEdit();
	lay->addRow("&Name", name);

	QLineEdit *email = new QLineEdit();
	lay->addRow("&Email", email);

	QLineEdit *age = new QLineEdit();
	//插入到下标1的位置（0开始）
	lay->insertRow(1, "&Age",age);

	//显示出错信息
	QLabel *info = new QLabel();
	info->setText("input");
	//设置样式表
	info->setStyleSheet("color:red;");
	lay->insertRow(0, "", info);


	//添加Save 和Clear按钮
	QPushButton *save = new QPushButton("Save");
	QPushButton *clear = new QPushButton("Clear");

	//绑定信号槽，按钮点击事件
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(Save()) );
	QObject::connect(clear, SIGNAL(clicked()), this, SLOT(Clear()));

	//添加一个平行布局
	QHBoxLayout *hlay = new QHBoxLayout();
	hlay->addWidget(save);
	hlay->addWidget(clear);
	lay->addRow(hlay);
}

void QFormLayoutTest::Save()
{
	//找到layout
	QFormLayout *lay = (QFormLayout*)this->layout();
	//显示错误信息label
	QLabel *label = (QLabel *)lay->itemAt(0, QFormLayout::FieldRole)->widget();
	//存放错误信息
	QString error = "";


	//遍历所有QLineEdit
	//遍历FormLayout的所有元素
	for (int i = 0; i < lay->rowCount(); i++)
	{
		//获取输入框
		QLayoutItem *item = lay->itemAt(i, QFormLayout::FieldRole);
		QLineEdit *e = (QLineEdit *)item->widget();
		if (!e) continue;

		//获取标题内容
		QLayoutItem *layItem = lay->itemAt(i, QFormLayout::LabelRole);
		if (!layItem) continue;
		QLabel *titleLabel = (QLabel *)layItem->widget();
		if (!titleLabel) continue;
		QString title = titleLabel->text();

		QString cname = e->metaObject()->className();
		if (cname == "QLineEdit")
		{
			if (e->text().trimmed() == "")
			{
				e->setFocus();
				error += title;
				error += " is empty!\n";
			}
		}
	}

	//设置错误显示
	label->setText(error);


}
void QFormLayoutTest::Clear()
{
	//找到layout
	QFormLayout *lay = (QFormLayout*)this->layout();
	//遍历所有QLineEdit
	//遍历FormLayout的所有元素
	for (int i = 0; i < lay->rowCount(); i++)
	{
		QLayoutItem *item = lay->itemAt(i, QFormLayout::FieldRole);
		QLineEdit *e = (QLineEdit *)item->widget();
		if (!e)
			continue;
		QString cname = e->metaObject()->className();
		if (cname == "QLineEdit")
		{
			e->setText("");
		}
	}
}