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
#include "XPS.h"
#include <QColorDialog>
XPS::XPS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//��ͼƬ
	connect(ui.openaction, SIGNAL(triggered()), ui.image, SLOT(Open()));
	//����ͼƬ
	connect(ui.saveaction, SIGNAL(triggered()), ui.image, SLOT(Save()));
	col = QColor(200, 0, 0, 255);
	SetPen();

	//���ʺ���Ƥ��ť����ѡ��
	QButtonGroup *gp = new QButtonGroup(this);
	gp->addButton(ui.eraseButton);
	gp->addButton(ui.penButton);
	gp->setExclusive(true);
	
}
void XPS::SetPen()
{
	ui.image->SetPen(ui.penSize->value(), col);
	status = XPEN;
	ui.penButton->setChecked(true);
}
void XPS::SetEraser()
{
	ui.image->SetEraser(ui.penSize->value());
	status = XERASER;
	ui.eraseButton->setChecked(true);
}
void XPS::SetColor()
{
	col = QColorDialog::getColor(Qt::red, this);
	QString sty = QString("background-color:rgba(%1,%2,%3,%4)")
		.arg(col.red()).arg(col.green()).arg(col.blue()).arg(col.alpha());
	ui.colorButton->setStyleSheet(sty);
	SetPen();
}
void XPS::Save()
{
	ui.image->Save();
	ui.statusBar->showMessage(QStringLiteral("�������"), 5000);
}
