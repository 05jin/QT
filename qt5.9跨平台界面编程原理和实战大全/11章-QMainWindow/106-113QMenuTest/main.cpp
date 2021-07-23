#include "QMenuTest.h"
#include <QtWidgets/QApplication>
#include "MenuWidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMenuTest w;
	MenuWidget m;
	//显示自定义窗口（工具栏、菜单、状态）
	//m.show();
	//QMainWindow
	w.show();
	return a.exec();
}
