#pragma once

#include <QString>
#include <QWebElement>

class QWebFrame;

class ParaContentParser
{
public:
	ParaContentParser(QWebFrame *pElement);
	~ParaContentParser();
	QString getContent();
	QString getTitle();

private:
	QWebElement m_pDocElement;

};

