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
#include <QPen>
class XImage : public QWidget
{
	Q_OBJECT

public:
	XImage(QWidget *parent=0);
	~XImage();
	void paintEvent(QPaintEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev)
	{
		mpos = QPoint();
	}
public slots:
	void Open();
	//���û��ʴ�ϸ����ɫ
	void SetPen(int size, QColor col);

protected:
	//ԭͼ
	QImage src;
	//��һ�ε����λ��
	QPoint mpos;
	QPen pen;
};
