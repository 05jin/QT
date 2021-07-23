#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //按钮快捷键设置
    ui->shortButton->setShortcut(tr("X"));
    ui->shortButton->setShortcut(tr("Ctrl+X"));
    ui->shortButton->setShortcut(tr("Ctrl+X,A"));
}

Widget::~Widget()
{
    delete ui;
}
