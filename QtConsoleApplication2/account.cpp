#include "account.h"

void account::writeCredentialData()
{
	QString fileName = "cre.txt";

	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly)) {
		QByteArray data(ac.accountName.toLocal8Bit());
		data.append(ac.accountPassword.toLocal8Bit());
		qInfo() << "----- Writting data -----";
		file.write(data);
		qInfo() << "----- Done -----";
		file.close();
	}
	else
	{
		qInfo() << file.errorString();
	}
}

account::account(QObject *parent)
	: QObject(parent)
{
}

account::~account()
{}

void account::openAccount()
{
	qInfo() << "Full Name";
	
	QTextStream s(stdin);
	s.flush();
	s.skipWhiteSpace();
	ac.accountName = s.readLine();
	qInfo() << "Password";
	s.skipWhiteSpace();
	ac.accountPassword = s.readLine();
	ac.accountBalance = 0;
	writeCredentialData();
}

void account::viewDetail()
{
	qInfo() << "Account Name: " << ac.accountName << Qt::endl << "Account Pass: " << ac.accountPassword << Qt::endl << "Balance: " << ac.accountBalance;
} 
