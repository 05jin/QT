#include "QMenuTest.h"
#include <QtWidgets/QApplication>
#include "MenuWidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMenuTest w;
	MenuWidget m;
	//��ʾ�Զ��崰�ڣ����������˵���״̬��
	//m.show();
	//QMainWindow
	w.show();
	return a.exec();
}
