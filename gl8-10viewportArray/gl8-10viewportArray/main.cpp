#include "viewportarray.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	viewportArray w;
	w.show();
	return a.exec();
}
