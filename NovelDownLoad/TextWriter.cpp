#include "TextWriter.h"

TextWriter::TextWriter(QString &sFileName)
: oFile(sFileName)
{
	if (!oFile.open(QIODevice::WriteOnly))
	{
		throw std::runtime_error("Can't Open File");
	}
	oStream.setDevice(&oFile);
}

TextWriter::~TextWriter()
{
}

void TextWriter::writeTitle(QString &sTitle)
{
	oStream << "\n\n" << sTitle << "\n\n";
}

void TextWriter::writeContent(QString &sContent)
{
	oStream << sContent << "\n";
}

void TextWriter::writeNovelName(QString &sName)
{
	oFile.setFileName(sName);
}
