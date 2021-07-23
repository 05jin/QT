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
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("提示输入"));
	ui.lineEdit->setInputMask("000.000.000.000;_");
	ui.textEdit->setInputMask("AAAAA;_");
	QIntValidator *ival = new QIntValidator();
	ival->setRange(1, 1000);
	ui.iedit->setValidator(ival);

	QDoubleValidator *dval = new QDoubleValidator();
	dval->setRange(-100, 10000,3);
	//不用科学计数法 
	dval->setNotation(QDoubleValidator::StandardNotation);
	ui.dedit->setValidator(dval);

	//验证邮箱 xcxj123@x123.com
	QRegExp exp("[a-zA-Z0-9-_]+@[a-zA-Z0-9-_]+\\.[a-zA-Z]+");
	QRegExpValidator *rval = new QRegExpValidator(exp);
	ui.email->setValidator(rval);


}


void qlineedittest::Save()
{
	ui.label->setText(ui.email->text());
	//格式不正确提示
	const QValidator *v = ui.email->validator();
	int pos = 0;
	/*
	返回
	    enum State {
        Invalid, 不正确
        Intermediate, 中间没输入结束 111@113.
        Acceptable 格式正确
    };*/
	if (v->validate(ui.email->text(), pos) != QValidator::Acceptable)
	{
		ui.label->setText(QString::fromLocal8Bit("邮箱格式不正确！"));
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