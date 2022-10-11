#pragma once

#include <QObject>
#include <qdebug.h>

#include "account.h"


class Bank  : public QObject
{
	Q_OBJECT
public:
	Bank(QObject *parent, QString name);
	~Bank();
};
