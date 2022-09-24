#include <QtCore/QCoreApplication>

#include "bank.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bank* frendaBank = new Bank(&a, "Frenda");
    frendaBank->bankWorking();
    return a.exec();
}
