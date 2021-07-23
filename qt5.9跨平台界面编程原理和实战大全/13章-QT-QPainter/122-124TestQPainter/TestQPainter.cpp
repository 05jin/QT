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

#include "TestQPainter.h"
#include <QPainter>

TestQPainter::TestQPainter(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}


void TestQPainter::paintEvent(QPaintEvent *ev)
{
	//���û����豸 ��widget��
	QPainter p(this);
	//p.begin(this);

	//���û�����ɫ
	p.setPen(QColor(255, 0, 0, 150));

	//��������
	//p.setFont(QFont(QStringLiteral("����"), 30));
	QFont font = ui.fontComboBox->currentFont();
	font.setPixelSize(30);
	p.setFont(font);

	//�����ı�
	p.drawText(100, 100, QStringLiteral("���Ե���ʾ����"));
	

	//������
	//���û�����ʽ
	QPen pen;
	//ʵ��
	pen.setStyle(Qt::SolidLine);
	//�ߴ�
	pen.setWidth(30);
	//��ˢ��
	pen.setBrush(Qt::red);

	//ˢ��ΪͼƬ
	pen.setBrush(QBrush(QImage("test.jpg")));

	//��β����ʽ
	pen.setCapStyle(Qt::RoundCap);

	//���Ӵ���ʽ
	pen.setJoinStyle(Qt::RoundJoin);

	p.setPen(pen);
	p.drawLine(QLine(0, 0, 300, 300));
	p.drawLine(QLine(300, 300, 600, 0));

	QVector<QLine> lines;
	lines.push_back(QLine(0, 0, 350, 350));
	lines.push_back(QLine(350, 350, 0, 450));
	lines.push_back(QLine(0, 450, 550, 550));
	p.drawLines(lines);
	p.end();
}