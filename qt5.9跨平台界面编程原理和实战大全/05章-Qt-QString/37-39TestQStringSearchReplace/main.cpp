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
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "xcjasd,asdasd{,[name],[id]},[name]},asda[name]}sdsa";

    ///////////////////////////////////////////////
    //字符串遍历
    for(int i =0; i < str.size(); i++)
    {
        cout<<str[i].toLatin1();
    }
    cout<<endl;
    cout<<"========================\n";
    QString::iterator itr = str.begin();
    for(;itr!= str.end();itr++)
    {
        //(*itr).toLatin1();
        cout<<itr->toLatin1();
    }
    cout<<endl;

    ///////////////////////////////////////////////
    //字符串查找
    QString key = "[name]";
    int pos = str.indexOf(key);
    cout<<"pos = "<<pos<<endl;
    int pos2 = str.indexOf(key,pos+key.size());
    cout<<"pos2 = "<<pos2<<endl;
    int pos3 = str.indexOf(key,pos2+key.size());
    cout<<"pos3 = "<<pos3<<endl;
    cout<<str.indexOf("tttt");
    //str.chop(2);
    qDebug()<<str;

    //取第一个{括号之前  012{56}9
    int bpos = str.indexOf("{");
    int epos = str.lastIndexOf("}");
    qDebug()<<str.left(bpos);
    //取最后一个}括号之后123456789
    qDebug()<<str.right(str.size()-epos-1);
    //取括号之间
    QString str2 = str;
    str2.chop(str.size()-epos);
    qDebug()<<str2;
    qDebug()<<str2.right(epos-bpos-1);

    ///////////////////////////////////////////////
    //字符串替换
    str.replace("[name]","xiaoming");
    str.replace("[id]","007");
    qDebug()<<str;


    ///////////////////////////////////////////////
    //字符串切割 , csv
    QStringList list1 = str.split(",");
    cout<<"---------------------"<<endl;
    for(int i = 0; i<list1.size();i++)
    {
        qDebug()<<list1[i];
    }




    return a.exec();
}
