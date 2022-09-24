#include "account.h"

account::account(QObject *parent)
	: QObject(parent)
{
}

account::~account()
{}

void account::openAccount()
{
	qInfo() << "Vui long nhap ten";
	
	QTextStream s(stdin);
	s.flush();
	s.skipWhiteSpace();
	ac.accountName = s.readLine();
	ac.accountBalance = 0;
}

void account::viewDetail()
{
	qInfo() << "Account Name: " << ac.accountName << Qt::endl << "Balance: " << ac.accountBalance;
} 
