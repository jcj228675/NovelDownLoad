#include "noveldownload.h"
#include <QtWidgets/QApplication>
#include <QNetworkProxy>
#include <QNetworkAccessManager>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv); 
	NovelDownLoad w;
	w.show();
	return a.exec();
}
