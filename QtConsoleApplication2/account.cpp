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
	qInfo() << "Vui long nhap mat khau";
	s.skipWhiteSpace();
	ac.accountPassword = s.readLine();
	ac.accountBalance = 0;
}

void account::viewDetail()
{
	qInfo() << "Account Name: " << ac.accountName << Qt::endl << "Account Pass: " << ac.accountPassword << Qt::endl << "Balance: " << ac.accountBalance;
} 
