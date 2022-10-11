#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTextStream>


#include "logger.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "File:" << logger::filename;
    logger::attach();

    qInfo() << "test";
    return a.exec();
}
