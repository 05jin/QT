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
#pragma once

#include <QWidget>
#include "ui_MenuWidget.h"
#include <QDebug>
#include <QMenu>
class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = Q_NULLPTR);
	~MenuWidget();
public slots:
	void Hover()
	{
		qDebug() << "Hover";
	}
	void Action1()
	{
		qDebug() << "Action1";
	}
	void Action1(bool isc)
	{
		qDebug() << "Action1 = " <<isc;
	}
	void Action(QAction* act)
	{
		qDebug() << "Action "<<act->text();
	}
	void Hovered(QAction* act)
	{
		//��̬�˵�
		if (act->text() == QStringLiteral("�˵�3"))
		{
			qDebug() << "Hovered " << act->text();
			act->menu()->clear();
			act->menu()->addAction(QStringLiteral("�˵�3.1"));
			act->menu()->addAction(QStringLiteral("�˵�3.2"));
			act->menu()->addAction(QStringLiteral("�˵�3.3"));
		}
		
	}

	void Click()
	{
		//���λ����ʾ�˵�
		m1->exec(QCursor::pos());
	}
private:
	QMenu *m1 = NULL;
	Ui::MenuWidget ui;
};
