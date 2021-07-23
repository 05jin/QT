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
#include "QRadioButtonTest.h"
#include <QRadioButton>
#include<QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QMessageBox>
QRadioButtonTest::QRadioButtonTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QRadioButton *rb1 = new QRadioButton("QRadioButton001");
	QRadioButton *rb2 = new QRadioButton("QRadioButton002");
	QRadioButton *rb3 = new QRadioButton("QRadioButton003");

	//按钮组
	QButtonGroup *group = new QButtonGroup(this);
	group->setObjectName("group");

	group->addButton(rb1);
	group->addButton(rb2);
	group->addButton(rb3);

	//垂直布局器
	QVBoxLayout *vb = new QVBoxLayout(this);
	
	//遍历按钮组
	for (int i = 0; i < group->buttons().size(); i++)
	{
		vb->addWidget(group->buttons()[i]);
	}

	//保存按钮
	QPushButton *save = new QPushButton("Save");
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(Save()));
	vb->addWidget(save);
}
void QRadioButtonTest::Save()
{
	//获取按钮组
	QButtonGroup *group = this->findChild<QButtonGroup*>("group");
	if (!group)return;

	//获取被选中的按钮
	QRadioButton *but = (QRadioButton *)group->checkedButton();
	if (!but)
	{
		QMessageBox::warning(this, "", "Please checked!");
		return;
	}

	QMessageBox::information(this, "", but->text());
}