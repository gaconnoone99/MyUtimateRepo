#pragma once

#include <QObject>
#include <qdebug.h>

#include <iostream>
#include "account.h"


class Bank  : public QObject
{
	Q_OBJECT
protected:

public:
	Bank(QObject *parent, QString name);
	~Bank();
	void bankWorking();
	void openBankAccount();
};
