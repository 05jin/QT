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
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <iostream>
using namespace std;
static QObject *PrintName(QObject *obj)
{
    if(!obj)
    {
        return NULL;
    }
    cout<<obj->objectName().toStdString();
    const QMetaObject *mobj = obj->metaObject();
    QString cname = mobj->className();
    cout<<":"<<cname.toStdString()<<endl;

    if(cname == "QPushButton")
    {
        QPushButton *pb = qobject_cast<QPushButton*>(obj);
        if(pb)
        {
             pb->setText(pb->text()+"class");
        }
    }

    QObjectList cs = obj->children();
    if(cs.size()<=0)
    {
        return NULL;
    }
    for(int i =0;i < cs.size(); i++)
    {
        PrintName(cs[i]);
    }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    PrintName(this);
    qDebug()<<"====================";
    QObjectList cs = this->children();
    for(int i = 0; i < cs.size(); i++)
    {
        qDebug()<<cs[i]->objectName();
    }

    QObjectList gs = ui->groupwidget->children();
    for(int i = 0; i < gs.size();i++)
    {
        qDebug()<<gs[i]->objectName();
    }
}

Widget::~Widget()
{
    delete ui;
}
