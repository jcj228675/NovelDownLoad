#ifndef NOVELDOWNLOAD_H
#define NOVELDOWNLOAD_H

#include <QtWidgets/QDialog>
#include "ui_NovelDownload.h"

class QWebView;

#include "TextWriter.h"
#include "UrlParser.h"

class NovelDownLoad : public QDialog
{
	Q_OBJECT

public:
	NovelDownLoad(QWidget *parent = 0);
	~NovelDownLoad();

public slots:
	void onNewWorkFinished();
	void onDownLoad();
	void onEndLoad();

private:
	QString getValue(QString sValueLabel);

	Ui::Dialog ui;
	std::unique_ptr<TextWriter> m_pWriter;
	std::unique_ptr<UrlParser> m_pParser;
};

extern QWebView *pView;
extern NovelDownLoad *pMainWindow;

#endif // NOVELDOWNLOAD_H
