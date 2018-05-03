#include "UrlParser.h"

#include <QWebPage>
#include <QWebFrame>
#include <QDomDocument>
#include <QMainWindow>
#include <QNetworkProxy>

#include "noveldownload.h"
#include "DirectoryParser.h"
#include "ParaContentParser.h"

UrlParser::UrlParser(QUrl &oUrl, TextWriter *pWriter)
:m_oUrl(oUrl), m_pWriter(pWriter)
{
	connect(pView, &QWebView::loadFinished, this, &UrlParser::endLoadPage);
	connect(this, &UrlParser::endDownLoad, pMainWindow, &NovelDownLoad::onEndLoad);
}

UrlParser::~UrlParser()
{
}

void UrlParser::parse()
{
	m_bCurDir = true;
	loadPage(m_oUrl);
}

void UrlParser::loadPage(QUrl &oUrl)
{
	pView->load(oUrl);
}

void UrlParser::endLoadPage(bool bOK)
{
	if (!bOK)
	{
		return;
	}
	
	parsePage();
}

void UrlParser::parsePage()
{
	QWebFrame *pFrame = pView->page()->mainFrame();
	
	if (m_bCurDir)
	{
		DirectoryParser oDirParser(pFrame);
		//m_pWriter->writeNovelName(oDirParser.getNovelName());

		m_oUrls = oDirParser.getParas();
		m_nCurPara = 0;
		loadPage(QUrl(m_oUrl.toDisplayString() + m_oUrls[m_nCurPara]));
		m_bCurDir = false;
	}
	else
	{
		ParaContentParser oContentParser(pFrame);

		m_pWriter->writeTitle(oContentParser.getTitle());
		m_pWriter->writeContent(oContentParser.getContent());

		m_nCurPara++;
		if (m_nCurPara < m_oUrls.size())
		{
			loadPage(QUrl(m_oUrl.toDisplayString() + m_oUrls[m_nCurPara]));
		}
		else
		{
			emit endDownLoad();
		}
	}
}