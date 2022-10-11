#include "account.h"

void account::writeCredentialData()
{
	QString fileName = "cre.txt";

	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly)) {
		QByteArray data(ac.accountName.toLocal8Bit() + "\r\n");
		data.append(ac.accountPassword.toLocal8Bit() + "\r\n");
		data.append(ac.accountBalance);
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
	QString fileName = "cre.txt";

	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly)) {
		if (!file.isReadable()) {
			qInfo() << "Cannot read";
			return;
		}

		QTextStream stream(&file);
		stream.seek(0);

		while (!stream.atEnd())
		{
			qInfo() << "*** " << stream.readLine() << " ***";
		}
	}
	else
	{
		qInfo() << file.errorString();
	}
}
void account::deposit()
{
	qInfo() << "-----" << "Input amount" << "-----";
	QTextStream s(stdin);
	s.flush();
	s.skipWhiteSpace();
	ac.accountBalance += s.readLine().toInt();
}

void account::withDraw()
{
	qInfo() << "-----" << "Input amount" << "-----";
	QTextStream s(stdin);
	s.flush();
	s.skipWhiteSpace();
	ac.accountBalance -= s.readLine().toInt();
}

