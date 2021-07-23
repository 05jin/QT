#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
#include <QDebug>
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void Click(bool ch)
    {
        qDebug()<<ch;

    }
    void Pre()
    {
        qDebug()<<"pressed";
    }
    void Rel()
    {
        qDebug()<<"released";
    }

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
