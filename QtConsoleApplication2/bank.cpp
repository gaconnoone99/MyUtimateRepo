#include "bank.h"

Bank::Bank(QObject *parent, QString name)
	: QObject(parent)
{
	qInfo() << "Welocome to " << name << " Bank";
	qInfo() << "What do you want to do? Please choose the number below";
	qInfo() << "1. Open account \n2. Login \n3.Exit"; 
}

Bank::~Bank()
{}
