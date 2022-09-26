#include <QtCore/QCoreApplication>

#include "account.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "What do you want to do? Please choose the number below";
    qInfo() << "1. Open account \n2. Login \n3. View account details \n4. Deposit \n5. WithDraw \n6. Exit";
    account* Frenda = new account(&a);
    int x;
    while (true)
    {
        qInfo() << "----- Input Action -----";
        std::cin >> x;
        qInfo() << "----- ------------ -----";
        if (x == 1) {
            qInfo() << "Open account";
            Frenda->openAccount();
            qInfo() << "Creating Done";
        }

        if (x == 3) {
            qInfo() << "View account details";
            Frenda->viewDetail();
        }

        if (x == 6) {
            qInfo() << "Exiting";
            return false;
        }
    }
    QCoreApplication::exit();
    return a.exec();
}
