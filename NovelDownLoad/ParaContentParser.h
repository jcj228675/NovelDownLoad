#pragma once

#include <QString>
#include <QWebElement>

class QWebFrame;

class ParaContentParser
{
public:
	ParaContentParser(QWebFrame *pElement, QString sContentSelector, QString sTitleSelector);
	~ParaContentParser();
	QString getContent();
	QString getTitle();

private:
	QWebElement m_pDocElement;
	QString m_sContentSelector;
	QString m_sTitleSelector;
};

