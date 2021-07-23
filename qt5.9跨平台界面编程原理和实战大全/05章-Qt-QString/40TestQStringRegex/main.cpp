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
    QString str = "xcxjxcxc123asdasdas 345 asdasd";
    int pos = str.indexOf(QRegExp("[0-9]+"));
    qDebug()<<pos<<endl;
    QString str2 = str;
    str2.replace(QRegExp("[0-9]+") ,"[num]");
    qDebug()<<str2<<endl;
    QStringList rlist = str.split(QRegExp("[0-9]+"));

    for(int i = 0; i < rlist.size(); i++)
    {
        qDebug()<<rlist[i];
    }
    return a.exec();
}
