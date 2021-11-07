#include <iostream>
#include <memory>
#include <array>

#include <QCoreApplication>
#include <QDebug>
#include <QtDebug>
#include <QVariant>
#include <QtConcurrent>
#include <QTcpSocket>
#include <QThread>

#include "client.hpp"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.get("https://postman-echo.com/get?foo1=bar1&foo2=bar2");
    
    QByteArray data;
    data.append("param1=hello");
    data.append("&");
    data.append("param2=foo");
    
    client.post("https://postman-echo.com/post", data);

    return a.exec();
}