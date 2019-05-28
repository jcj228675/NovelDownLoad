#include "noveldownload.h"

#include <QUrl>
#include <QSettings>

#include "TextWriter.h"
#include "UrlParser.h"

QWebView *pView;
NovelDownLoad *pMainWindow;

static const QString c_sUrlListSelector = "urlListSelector";
static const QString c_sItemLabel = "itemLabel";
static const QString c_sContentSelector = "contentSelector";
static const QString c_sTitleSelector = "titleSelector";
static const QString c_sRootPath = "rootPath";
static const QString c_sOutDir = "outDir";
static const QString c_sNovelDirUrl = "novelDirUrl";

NovelDownLoad::NovelDownLoad(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setLayout(ui.m_pGlobalLayout);
	
	pView = ui.m_pNewWorkView;

	connect(ui.m_NetWorkOK, &QPushButton::clicked, this, &NovelDownLoad::onNewWorkFinished);
	connect(ui.m_pOK, &QPushButton::clicked, this, &NovelDownLoad::onDownLoad);
	ui.m_pFileEdit->setText(getValue(c_sOutDir));
	ui.m_pNetWorkEdit->setText(getValue(c_sNovelDirUrl));
	ui.m_pRootPage->setText(getValue(c_sRootPath));
	ui.m_pUrlListSelector->setText(getValue(c_sUrlListSelector));
	ui.m_pItemLabel->setText(getValue(c_sItemLabel));
	ui.m_pTitleSelector->setText(getValue(c_sTitleSelector));
	ui.m_pContentSelector->setText(getValue(c_sContentSelector));
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
	QString sRootPage = ui.m_pRootPage->text();
	QString sTitleSelector = ui.m_pTitleSelector->text();
	QString sContentSelector = ui.m_pContentSelector->text();
	QString sUrlListSelector = ui.m_pUrlListSelector->text();
	QString sItemLable = ui.m_pItemLabel->text();

	m_pWriter.reset(new TextWriter(sFile));
	m_pParser.reset(new UrlParser(QUrl(sUrl), m_pWriter.get(), sRootPage, sContentSelector, sTitleSelector, sUrlListSelector, sItemLable));
	m_pParser->parse();
}

void NovelDownLoad::onEndLoad()
{
	m_pParser = nullptr;
	m_pWriter = nullptr;
}

QString NovelDownLoad::getValue(QString sValueLabel)
{
	QString sApplicationPath = QCoreApplication::applicationDirPath();
	if (!sApplicationPath.endsWith("/"))
	{
		sApplicationPath += "/";
	}
	
	QSettings oSettings(sApplicationPath + "settings.ini", QSettings::IniFormat);
	return oSettings.value(sValueLabel).toString();
}
