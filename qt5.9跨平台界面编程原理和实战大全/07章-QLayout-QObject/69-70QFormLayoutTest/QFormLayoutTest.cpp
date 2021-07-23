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
#include "QFormLayoutTest.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
QFormLayoutTest::QFormLayoutTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFormLayout *lay = new QFormLayout(this);
	QLineEdit *name = new QLineEdit();
	lay->addRow("&Name", name);

	QLineEdit *email = new QLineEdit();
	lay->addRow("&Email", email);

	QLineEdit *age = new QLineEdit();
	//���뵽�±�1��λ�ã�0��ʼ��
	lay->insertRow(1, "&Age",age);

	//��ʾ������Ϣ
	QLabel *info = new QLabel();
	info->setText("input");
	//������ʽ��
	info->setStyleSheet("color:red;");
	lay->insertRow(0, "", info);


	//���Save ��Clear��ť
	QPushButton *save = new QPushButton("Save");
	QPushButton *clear = new QPushButton("Clear");

	//���źŲۣ���ť����¼�
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(Save()) );
	QObject::connect(clear, SIGNAL(clicked()), this, SLOT(Clear()));

	//���һ��ƽ�в���
	QHBoxLayout *hlay = new QHBoxLayout();
	hlay->addWidget(save);
	hlay->addWidget(clear);
	lay->addRow(hlay);
}

void QFormLayoutTest::Save()
{
	//�ҵ�layout
	QFormLayout *lay = (QFormLayout*)this->layout();
	//��ʾ������Ϣlabel
	QLabel *label = (QLabel *)lay->itemAt(0, QFormLayout::FieldRole)->widget();
	//��Ŵ�����Ϣ
	QString error = "";


	//��������QLineEdit
	//����FormLayout������Ԫ��
	for (int i = 0; i < lay->rowCount(); i++)
	{
		//��ȡ�����
		QLayoutItem *item = lay->itemAt(i, QFormLayout::FieldRole);
		QLineEdit *e = (QLineEdit *)item->widget();
		if (!e) continue;

		//��ȡ��������
		QLayoutItem *layItem = lay->itemAt(i, QFormLayout::LabelRole);
		if (!layItem) continue;
		QLabel *titleLabel = (QLabel *)layItem->widget();
		if (!titleLabel) continue;
		QString title = titleLabel->text();

		QString cname = e->metaObject()->className();
		if (cname == "QLineEdit")
		{
			if (e->text().trimmed() == "")
			{
				e->setFocus();
				error += title;
				error += " is empty!\n";
			}
		}
	}

	//���ô�����ʾ
	label->setText(error);


}
void QFormLayoutTest::Clear()
{
	//�ҵ�layout
	QFormLayout *lay = (QFormLayout*)this->layout();
	//��������QLineEdit
	//����FormLayout������Ԫ��
	for (int i = 0; i < lay->rowCount(); i++)
	{
		QLayoutItem *item = lay->itemAt(i, QFormLayout::FieldRole);
		QLineEdit *e = (QLineEdit *)item->widget();
		if (!e)
			continue;
		QString cname = e->metaObject()->className();
		if (cname == "QLineEdit")
		{
			e->setText("");
		}
	}
}