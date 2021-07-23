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
#include "qlineedittest.h"

void qlineedittest::View()
{
	QString txt = ui.lineEdit->text();
	txt += " ";
	txt += ui.textEdit->text();
	ui.label->setText(txt);
}
qlineedittest::qlineedittest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("��ʾ����"));
	ui.lineEdit->setInputMask("000.000.000.000;_");
	ui.textEdit->setInputMask("AAAAA;_");
	QIntValidator *ival = new QIntValidator();
	ival->setRange(1, 1000);
	ui.iedit->setValidator(ival);

	QDoubleValidator *dval = new QDoubleValidator();
	dval->setRange(-100, 10000,3);
	//���ÿ�ѧ������ 
	dval->setNotation(QDoubleValidator::StandardNotation);
	ui.dedit->setValidator(dval);

	//��֤���� xcxj123@x123.com
	QRegExp exp("[a-zA-Z0-9-_]+@[a-zA-Z0-9-_]+\\.[a-zA-Z]+");
	QRegExpValidator *rval = new QRegExpValidator(exp);
	ui.email->setValidator(rval);


}


void qlineedittest::Save()
{
	ui.label->setText(ui.email->text());
	//��ʽ����ȷ��ʾ
	const QValidator *v = ui.email->validator();
	int pos = 0;
	/*
	����
	    enum State {
        Invalid, ����ȷ
        Intermediate, �м�û������� 111@113.
        Acceptable ��ʽ��ȷ
    };*/
	if (v->validate(ui.email->text(), pos) != QValidator::Acceptable)
	{
		ui.label->setText(QString::fromLocal8Bit("�����ʽ����ȷ��"));
	}
}
void qlineedittest::Return()
{
	ui.rlabel->setText(ui.sedit->text());
}
void qlineedittest::Edit()
{
	ui.slabel->setText(ui.sedit->text());
}
void qlineedittest::Change(QString txt)
{
	ui.rlabel->setText(txt);
}

void qlineedittest::Edited(QString txt)
{
	ui.slabel->setText(txt);
}

void qlineedittest::Test()
{
	ui.lineEdit->setText("lineedit test");
	ui.sedit->setText("test123456");
}