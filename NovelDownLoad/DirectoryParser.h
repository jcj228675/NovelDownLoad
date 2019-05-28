#pragma once

#include <QStringList>
#include <QWebElement>

class QWebFrame;

class DirectoryParser
{
public:
	DirectoryParser(QWebFrame *pFrame, QString sUrlListSelector, QString sItemLabel);
	~DirectoryParser();

	QString getNovelName();
	QStringList getParas();
private:
	QWebElement m_oDocElement;
	QString m_sUrlListSelector;
	QString m_sItemLabel;
};

