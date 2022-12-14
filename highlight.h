#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include"mainwindow.h"

#include <QSyntaxHighlighter>
#include<QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QXmlStreamAttributes>
#include<QRegularExpression>
#include<QBrush>
#include<QColor>
#include<QFile>
#include <fstream>

struct HighlightingRule
{
    QRegularExpression pattern;
    QTextCharFormat format;
};


class Highlight : public QSyntaxHighlighter
{
    Q_OBJECT

private:


    QVector<HighlightingRule> highlighting_rules;

    QRegularExpression expr_begin;
    QRegularExpression expr_end;

    QTextCharFormat comment_format;

    QXmlStreamReader XMLStream; //!!! Что тут делает открытое поле? (исправлено)

    QString file; //!!! Что тут делает открытое поле? (исправлено)


public:

    Highlight(QTextDocument *parent, QVector<HighlightingRule>& highlightingRules); //!!! передача по значению (исправлено)

protected:
        void highlightBlock(const QString &text) override;

        friend class MainWindow;

};



#endif // HIGHLIGHT_H
