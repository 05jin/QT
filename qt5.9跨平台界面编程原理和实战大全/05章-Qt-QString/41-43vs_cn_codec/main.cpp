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
#include "vs_cn_codec.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QTextCodec>
#include <windows.h>
using namespace std;

//#pragma execution_character_set("UTF-8")
int main(int argc, char *argv[])
{ 
	QApplication a(argc, argv);
	QString str = QStringLiteral("中文测试");
	//str = "中文测试";
	qDebug() << str;
	//QMessageBox::information(0, "title", str);
	char *src = "元数据中文GBK";

	//元数据是gbk或者gb2312 多字节存入QString
	//本地编码方式 默认GBK
	QString str1 = QString::fromLocal8Bit(src);
	qDebug() << "str1 = " << str1;
	
	//把QString 转为gbk
	cout << str1.toLocal8Bit().toStdString() << endl;
	//本地处理编码方式，默认是GBK，改为UTF-8
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QString str2 = QString::fromLocal8Bit(str1.toUtf8());

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	qDebug() << "str2 = " << str2;
	//win api调用qstring作为参数
	MessageBox(0, str2.toStdWString().c_str(), L"中文标题",0);

	//vs_cn_codec w;
	//w.show();
	return a.exec();
}
