#include "DirectoryParser.h"

#include <QWebFrame>

DirectoryParser::DirectoryParser(QWebFrame *pFrame)
:m_oDocElement(pFrame->documentElement())
{
}


DirectoryParser::~DirectoryParser()
{
}

QStringList DirectoryParser::getParas()
{
	QStringList oReselt;
	QWebElement oList = m_oDocElement.findFirst(QString("dl"));
	QWebElementCollection oPages = oList.findAll(QString("dd"));
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
