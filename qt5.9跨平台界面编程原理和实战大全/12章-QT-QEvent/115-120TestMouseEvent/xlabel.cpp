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

#include "xlabel.h"
#include <QEvent>
#include<QMouseEvent>
#include <QDebug>
XLabel::XLabel(QWidget *parent)
	: QLabel(parent)
{
	this->setMouseTracking(true);
	menu.addAction(QStringLiteral("�˵�1"));
	menu.addAction(QStringLiteral("�˵�2"));
	menu.addAction(QStringLiteral("�˵�3"));
}

XLabel::~XLabel()
{
}
bool XLabel::event(QEvent *ev)
{
	if (ev->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *me = static_cast<QMouseEvent*> (ev);
		////�������
		qDebug() << "LocalPos " << me->x() << ":" << me->y();
		//��������
		qDebug() << "windowPos " << me->windowPos().x() << ":" << me->windowPos().y();
		//��Ļ����
		qDebug() << "screenPos " << me->screenPos().x() << ":" << me->screenPos().y();

		//��������תȫ�֣���Ļ���꣩
		QPoint gpos = mapToGlobal(me->pos());
		qDebug() << "mapToGlobal " << gpos.x() << ":" << gpos.y();

		//��ȡ������Ļ����
		qDebug() << "QCursor " << QCursor::pos().x() <<":"  << QCursor::pos().y();

		//��갴���¼�
		if (me->buttons() & Qt::LeftButton)
		{
			qDebug() << "LeftButton";
			setCursor(Qt::ArrowCursor);
		}
		if (me->buttons() & Qt::RightButton)
		{
			qDebug() << "RightButton";
			//�Ҽ��˵�
			menu.exec(gpos);

		}
		if (me->buttons() & Qt::MidButton)
		{
			qDebug() << "MidButton";
		}

		//���Ҽ�ͬʱ����
		if ( (me->buttons() & Qt::LeftButton) && (me->buttons() & Qt::RightButton) )
		{
			qDebug() << "LeftButton&RightButton";
			//���ͼ���滻 -1 -1 �ȵ��м�
			QPixmap pix("cursor.png");
			QCursor cur = QCursor(pix, -1, -1);
			setCursor(cur);
		}
	}
	return QWidget::event(ev);
}