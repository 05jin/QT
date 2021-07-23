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
#include "QMenuTest.h"

QMenuTest::QMenuTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//菜单栏
	this->menuBar()->addAction("TestMenu1");

	//状态栏
	this->statusBar()->showMessage("status Bar");

	//工具栏
	ui.mainToolBar->addAction(QStringLiteral("按钮一"));

	ui.mainToolBar->addAction(QIcon("test.jpg"),QStringLiteral("按钮二"));

	//文件显示在图标下面
	ui.mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//工具栏换行
	this->addToolBarBreak();

	//默认顶部插入
	QToolBar *t2 = this->addToolBar("tool2");
	t2->addAction(QStringLiteral("顶部"));
	

	//左侧
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("左侧"));
		this->addToolBar(Qt::LeftToolBarArea, t);
	}

	//右侧
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("右侧"));
		this->addToolBar(Qt::RightToolBarArea, t);
	}

	//底部
	{
		QToolBar *t = new QToolBar(this);
		t->addAction(QStringLiteral("底侧"));
		this->addToolBar(Qt::BottomToolBarArea, t);
	}

}
