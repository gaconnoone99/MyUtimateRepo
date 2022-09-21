#pragma once

#include <QObject>

class account  : public QObject
{
	Q_OBJECT

public:
	account(QObject *parent);
	~account();
};
