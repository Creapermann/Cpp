#include <iostream>
#include <memory>
#include <array>

#include <QCoreApplication>
#include <QDebug>
#include <QtDebug>
#include <QVariant>
#include <QtConcurrent>
#include <QTcpSocket>

#include "client.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.connect_to_host("www.httpbin.org", 443);

    return a.exec();
}