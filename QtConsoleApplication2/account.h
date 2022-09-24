#pragma once

#include <QObject>
#include <qdebug.h>

#include <iostream>
#include <string.h>
struct accounInfo
{
	QString accountName;
	qint64 accountBalance;
};

class account  : public QObject
{
	Q_OBJECT
	accounInfo ac;
public:
	account(QObject *parent);
	~account();

	void openAccount();
	void viewDetail();
};
