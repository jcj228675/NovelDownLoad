#include "ParaContentParser.h"

#include <QWebFrame>

ParaContentParser::ParaContentParser(QWebFrame *pFrame, QString sContentSelector, QString sTitleSelector)
: m_pDocElement(pFrame->documentElement()),
m_sContentSelector(sContentSelector),
m_sTitleSelector(sTitleSelector)
{
}


ParaContentParser::~ParaContentParser()
{
}

QString ParaContentParser::getContent()
{
	QWebElement body = m_pDocElement.findFirst(QString("body"));
	QWebElement content = body.findFirst(m_sContentSelector);
	return content.toPlainText();
}

QString ParaContentParser::getTitle()
{
	QWebElement body = m_pDocElement.findFirst(QString("body"));
	QWebElement head = body.findFirst(m_sTitleSelector);
	return head.toPlainText();
}
