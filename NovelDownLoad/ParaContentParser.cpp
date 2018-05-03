#include "ParaContentParser.h"

#include <QWebFrame>

ParaContentParser::ParaContentParser(QWebFrame *pFrame)
: m_pDocElement(pFrame->documentElement())
{
}


ParaContentParser::~ParaContentParser()
{
}

QString ParaContentParser::getContent()
{
	QWebElement body = m_pDocElement.findFirst(QString("body"));
	QWebElement content = body.findFirst(QString("div[id=content]"));
	return content.toPlainText();
}

QString ParaContentParser::getTitle()
{
	QWebElement body = m_pDocElement.findFirst(QString("body"));
	QWebElement head = body.findFirst(QString("h1"));
	return head.toPlainText();
}
