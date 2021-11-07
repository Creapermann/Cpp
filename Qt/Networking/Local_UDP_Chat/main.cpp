#include <iostream>
#include <memory>
#include <array>

#include <QCoreApplication>
#include <QDebug>
#include <QtDebug>
#include <QVariant>
#include <QtConcurrent>

#include "display.hpp"
#include "chat.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Display display;
    Chat chat;
    
    QObject::connect(&display, &Display::send, &chat, &Chat::send, Qt::QueuedConnection);
    QObject::connect(&chat, &Chat::print, &display, &Display::print, Qt::QueuedConnection);

    auto future = QtConcurrent::run(&Chat::login, &chat);
    
    future.waitForFinished();
    auto f = QtConcurrent::run(&Display::monitor, &display);    

    return a.exec();
}
