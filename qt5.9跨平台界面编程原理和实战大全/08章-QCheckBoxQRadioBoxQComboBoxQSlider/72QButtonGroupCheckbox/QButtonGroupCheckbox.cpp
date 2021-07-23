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

#include "QButtonGroupCheckbox.h"
#include <QDebug>
QButtonGroupCheckbox::QButtonGroupCheckbox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QButtonGroup *group = new QButtonGroup(this);
	//加组后默认变为单选
	group->addButton(ui.checkBox1);
	group->addButton(ui.checkBox2);
	group->addButton(ui.checkBox3);
	//改为多选
	//group->setExclusive(false);

	//手动点击事件
	QObject::connect(group, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(GClick(QAbstractButton *)));

	//状态变化触发事件
	QObject::connect(group, SIGNAL(buttonToggled(QAbstractButton *,bool)), this, SLOT(GToggle(QAbstractButton *, bool)));
}
void QButtonGroupCheckbox::GClick(QAbstractButton *but)
{
	qDebug() <<"GClick:" <<but << but->isChecked();
}
void QButtonGroupCheckbox::GToggle(QAbstractButton *but, bool check)
{
	qDebug() <<"GToggle:"<< but << check;
}