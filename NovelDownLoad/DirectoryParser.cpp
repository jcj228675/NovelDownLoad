#include "DirectoryParser.h"

#include <QWebFrame>

DirectoryParser::DirectoryParser(QWebFrame *pFrame, QString sUrlListSelector, QString sItemLabel)
:m_oDocElement(pFrame->documentElement()),
m_sUrlListSelector(sUrlListSelector),
m_sItemLabel(sItemLabel)
{
}


DirectoryParser::~DirectoryParser()
{
}

QStringList DirectoryParser::getParas()
{
	QStringList oReselt;
	QWebElement oList = m_oDocElement.findFirst(m_sUrlListSelector);
	QWebElementCollection oPages = oList.findAll(m_sItemLabel);
	for (int i = 0; i < oPages.count(); i++)
	{
		QWebElement oLink = oPages[i].findFirst(QString("a"));
		oReselt.push_back(oLink.attribute("href"));
	}
	return oReselt;
}

QString DirectoryParser::getNovelName()
{
	return m_oDocElement.findFirst("h1").toPlainText();
}
