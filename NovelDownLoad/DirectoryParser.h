#pragma once

#include <QStringList>
#include <QWebElement>

class QWebFrame;

class DirectoryParser
{
public:
	DirectoryParser(QWebFrame *pFrame);
	~DirectoryParser();

	QString getNovelName();
	QStringList getParas();
private:
	QWebElement m_oDocElement;
};

