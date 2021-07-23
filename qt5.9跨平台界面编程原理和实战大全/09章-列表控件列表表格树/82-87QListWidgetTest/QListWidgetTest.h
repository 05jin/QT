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

#include <QtWidgets/QWidget>
#include "ui_QListWidgetTest.h"

class QListWidgetTest : public QWidget
{
	Q_OBJECT

public:
	QListWidgetTest(QWidget *parent = Q_NULLPTR);
public slots:
	void Click();
	void Sort();

	//��ǰѡ��仯
	void CurChange(QListWidgetItem *cur, QListWidgetItem *pre);
	void CurChange(int row);
	void CurChange(const QString &txt);
	//���� ���˫��
	void ItemAct(QListWidgetItem *item);
	//���ݸı� �����ƿ����س�ȷ��
	void ItemChange(QListWidgetItem *item);

	//����¼�
	void ItemClick(QListWidgetItem *item);
	void ItemDoubleClick(QListWidgetItem *item);
	//ui.listWidget->setMouseTracking(true);
	void ItemEntered(QListWidgetItem *item); 
	void ItemPressed(QListWidgetItem *item);

private:
	Ui::QListWidgetTestClass ui;
};
