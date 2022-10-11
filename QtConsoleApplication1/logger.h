#pragma once

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <iostream>
#include <QTextStream>

class logger  : public QObject
{
	Q_OBJECT

public:
	logger(QObject *parent);
	~logger();

	static bool logging;
	static QString filename;
	static void attach();
	static void handler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};
