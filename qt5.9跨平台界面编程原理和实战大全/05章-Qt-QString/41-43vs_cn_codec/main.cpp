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
	QString str = QStringLiteral("���Ĳ���");
	//str = "���Ĳ���";
	qDebug() << str;
	//QMessageBox::information(0, "title", str);
	char *src = "Ԫ��������GBK";

	//Ԫ������gbk����gb2312 ���ֽڴ���QString
	//���ر��뷽ʽ Ĭ��GBK
	QString str1 = QString::fromLocal8Bit(src);
	qDebug() << "str1 = " << str1;
	
	//��QString תΪgbk
	cout << str1.toLocal8Bit().toStdString() << endl;
	//���ش�����뷽ʽ��Ĭ����GBK����ΪUTF-8
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QString str2 = QString::fromLocal8Bit(str1.toUtf8());

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	qDebug() << "str2 = " << str2;
	//win api����qstring��Ϊ����
	MessageBox(0, str2.toStdWString().c_str(), L"���ı���",0);

	//vs_cn_codec w;
	//w.show();
	return a.exec();
}
