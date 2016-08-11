#include "fur.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	fur w;
	w.show();
	return a.exec();
}
