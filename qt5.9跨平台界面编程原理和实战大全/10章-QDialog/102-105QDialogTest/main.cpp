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
#include "QDialogTest.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "xmessagebox.h"
#include "progreedialog.h"
#include "TestPro.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestPro tp;
	//加载进度条显示
	ProgreedDialog p;
	//绑定信号
	QObject::connect(&tp, SIGNAL(SetPos(int)), &p, SLOT(SetPos(int)));
	//启动线程
	tp.start();

	p.exec();
	


	


	qDebug() << XMessageBox::info(QStringLiteral("测试新插入的提示!"));
	//XMessageBox box;
	//box.exec();


	QDialogTest w;

	//QDialog d;
	//d.setWindowTitle("New Dialog");
	//阻塞有返回值
	//int re = d.exec();
	int re = w.exec();
	qDebug() << "re = " << re;
	qDebug() << "result() = " << w.result();
	switch (re)
	{
	case QDialog::Accepted:
		qDebug() << "Accepted";
		break;
	case QDialog::Rejected:
		qDebug() << "Rejected";
		break;
	default:
		qDebug() << re;
		break;
	}

	
	//w.show();



	return a.exec();
}
