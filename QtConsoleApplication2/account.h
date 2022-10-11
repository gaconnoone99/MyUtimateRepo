#pragma once

//Qt Lib
#include <QObject>
#include <qdebug.h>
#include <qbuffer.h>
#include <qfile.h>
#include <qdatetime.h>

//C++ lib
#include <iostream>
#include <string.h>

struct accounInfo
{
	QString accountName;
	QString accountPassword;
	qint64 accountBalance;
};

class account  : public QObject
{
	Q_OBJECT
	accounInfo ac;
protected:
	void writeCredentialData();
public:
	account(QObject *parent);
	~account();

	void openAccount();
	void viewDetail();
	void deposit();
	void withDraw();
};
