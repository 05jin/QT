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
#include "MenuWidget.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//插入菜单栏
	QMenuBar *m = new QMenuBar(this);

	////动态菜单 包含QMenu所有子节点（子节点的子节点）触发
	connect(m, SIGNAL(hovered(QAction*)), this, SLOT(Hovered(QAction*)));

	m->resize(width(), m->height());
	//一级菜单
	m1 = m->addMenu(QStringLiteral("菜单1"));

	//包含QMenu所有子节点（子节点的子节点）触发
	connect(m1, SIGNAL(triggered(QAction*)), this, SLOT(Action(QAction*)));

	//二级菜单
	QAction *a1= m1->addAction(QStringLiteral("二级菜单1.1"));
	a1->setIcon(QIcon("test.jpg"));
	//QAction 触发信号
	connect(a1, SIGNAL(triggered()), this, SLOT(Action1()));
	//添加快捷键 A
	a1->setShortcut(QString("A"));
	

	QAction *a2 = m1->addAction(QStringLiteral("二级菜单1.2"));
	//QAction 鼠标悬停信号
	connect(a2, SIGNAL(hovered()), this, SLOT(Hover()));

	QAction *a3 = m1->addAction(QStringLiteral("二级菜单1.3"));
	a3->setIcon(QIcon("test.jpg"));

	a1->setCheckable(true);
	a2->setCheckable(true);
	a3->setCheckable(true);

	QActionGroup *ag = new QActionGroup(this);
	//ag->addAction(a1);
	ag->addAction(a2);
	ag->addAction(a3);
	//单选
	ag->setExclusive(true);
	//是否选中事件
	connect(a1, SIGNAL(triggered(bool)), this, SLOT(Action1(bool)));

	//三级菜单
	QMenu *m14 = m1->addMenu(QStringLiteral("二级菜单1.4"));
	m14->addAction(QStringLiteral("三级菜单1.4.1"));
	m14->setIcon(QIcon("test.jpg"));


	QMenu *m2 = m->addMenu(QStringLiteral("菜单2"));

	m2->addAction(ui.actiontest);
	QMenu *m3 = m->addMenu(QStringLiteral("菜单3"));


	////////////////////////////////////////////
	///工具栏
	QToolBar *tbar = new QToolBar(this);
	tbar->setGeometry(0, m->height(), width(), 30);
	tbar->setIconSize(QSize(30, 30));
	tbar->addAction(a1);


	////////////////////////////////////////////
	///状态栏
	//实现消息定时消失
	QStatusBar * sbar = new QStatusBar(this);
	sbar->setGeometry(0, height() - 30, width(), 30);
	sbar->showMessage(QStringLiteral("测试消息三秒消失!"), 3000);

}

MenuWidget::~MenuWidget()
{
}

