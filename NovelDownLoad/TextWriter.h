#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>

class TextWriter
{
public:
	TextWriter(QString &sFileName);
	~TextWriter();
	void writeTitle(QString &sTitle);
	void writeContent(QString &sContent);
	void writeNovelName(QString &sName);

private:
	QFile oFile;
	QTextStream oStream;
};

