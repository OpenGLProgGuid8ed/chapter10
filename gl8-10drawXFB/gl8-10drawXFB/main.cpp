#include "drawxfb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	drawXFB w;
	w.show();
	return a.exec();
}
