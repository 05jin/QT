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
#include "progreedialog.h"
#include <QThread>



ProgreedDialog::ProgreedDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//ȥ��������
	this->setWindowFlags(Qt::FramelessWindowHint);

	//���ñ���͸��
	this->setAttribute(Qt::WA_TranslucentBackground, true);

}

ProgreedDialog::~ProgreedDialog()
{
}

void ProgreedDialog::SetPos(int pos)
{
	ui.progressBar->setValue(pos);
	if (pos == 1000)
	{
		for (int i = 100; i > 0; i--)
		{
			//͸���� 1.0 0.0
			this->setWindowOpacity((float)i / 100.0);
			QThread::msleep(10);
			ui.label->setText(QString::number(i));
			QEventLoop loop;
			loop.processEvents();
		}
		this->close();
	}
}