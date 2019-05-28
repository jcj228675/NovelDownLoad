#pragma once

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "TextWriter.h"

class UrlParser : public QObject
{
	Q_OBJECT
public:
	UrlParser(QUrl &oUrl, TextWriter *pWriter, QString sRootPage, QString sContentSelector, QString sTitleSelector, QString sUrlListSelector, QString sItemLabelSelector);
	~UrlParser();
	void parse();
	void loadPage(QUrl &oUrl);

signals:
	void endDownLoad();

private slots:
	void endLoadPage(bool bOK);

private:
	QUrl m_oUrl;
	TextWriter *m_pWriter;
	QStringList m_oUrls;
	int m_nCurPara;
	bool m_bCurDir;
	QString m_sRootPage;
	QString m_sContentSelector;
	QString m_sTitleSelector;
	QString m_sUrlListSelector;
	QString m_sItemLabelSelector;

	void parsePage();
	void skipEmpty();
	QString rootUrl();
};

