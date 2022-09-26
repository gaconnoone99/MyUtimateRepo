#include "bank.h"

Bank::Bank(QObject *parent, QString name)
	: QObject(parent)
{
	qInfo() << "Welocome to " << name << " Bank";
}

Bank::~Bank()
{}

void Bank::bankWorking()
{
    qInfo() << "What do you want to do? Please choose the number below";
    qInfo() << "1. Open account \n2. Login \n3. Exit";

    int x;
    std::cin >> x;

    if (x == 1) {
        qInfo() << "Open account";
        openBankAccount();
    }

    if (x == 2) {
        qInfo() << "Open account";
        openBankAccount();
    }
}

void Bank::openBankAccount()
{
    account a(this);
    a.openAccount();
    a.viewDetail();
}
