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
#include "ui_qtablewidgettest.h"

class QTableWidgetTest : public QWidget
{
	Q_OBJECT

public:
	QTableWidgetTest(QWidget *parent = Q_NULLPTR);
public slots:
	void Del();
	//�����ͣ����֧�����õ�widget
	void ItemEntered(QTableWidgetItem *item);
	void CellEntered(int row, int column);

	//����������
	void Click(int, int);

	//˫�������������Ҽ�
	void Double(int, int);

	//Ԫ���޸�
	void Change(int, int);

	//����������
	void SectionClicked(int col);
private:
	Ui::QTableWidgetTestClass ui;
};
