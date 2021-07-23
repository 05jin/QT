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
#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str;
    str = QString("name=%1 arg=%2 %3 %4 %5")
            .arg("xiaoming")
            .arg(15)
            .arg(14.5)
            .arg(123,0,2)
            .arg(255,6,16)
            ;
    qDebug()<<str;
    QString num = QString::number(14);
    qDebug()<<num;
    int i = num.toInt();
    qDebug()<<"i="<<i;
    qDebug()<<"num double"<<num.toDouble();
    QString num2 = QString::number(15.6);
    qDebug()<<num2;
    qDebug()<<num2.toInt();
    qDebug()<<num2.toDouble();


    return a.exec();
}
