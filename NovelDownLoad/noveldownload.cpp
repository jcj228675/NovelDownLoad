#include "noveldownload.h"

#include <QUrl>

#include "TextWriter.h"
#include "UrlParser.h"

QWebView *pView;
NovelDownLoad *pMainWindow;

NovelDownLoad::NovelDownLoad(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setLayout(ui.m_pGlobalLayout);
	//setFixedSize(QSize(400, 300));
	
	pView = ui.m_pNewWorkView;

	connect(ui.m_NetWorkOK, &QPushButton::clicked, this, &NovelDownLoad::onNewWorkFinished);
	connect(ui.m_pOK, &QPushButton::clicked, this, &NovelDownLoad::onDownLoad);
	ui.m_pFileEdit->setText(QString("d:/aaa.txt"));
	ui.m_pNetWorkEdit->setText(QString("http://www.biqusa.com/4_4983/"));
	pMainWindow = this;
}

NovelDownLoad::~NovelDownLoad()
{

}

void NovelDownLoad::onNewWorkFinished()
{
	QString sUrl = ui.m_pNetWorkEdit->text();
	pView->setUrl(QUrl(sUrl));
}

void NovelDownLoad::onDownLoad()
{
	QString sUrl = ui.m_pNetWorkEdit->text();
	QString sFile = ui.m_pFileEdit->text();

	m_pWriter.reset(new TextWriter(sFile));
	m_pParser.reset(new UrlParser(QUrl(sUrl), m_pWriter.get()));
	m_pParser->parse();
}

void NovelDownLoad::onEndLoad()
{
	m_pParser = nullptr;
	m_pWriter = nullptr;
}
