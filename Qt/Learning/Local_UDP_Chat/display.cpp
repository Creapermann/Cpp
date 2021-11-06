#include "display.hpp"

Display::Display(QObject *parent) 
    : QObject(parent), m_input_stream(stdin)
{
}

void Display::monitor()
{
    while(true)
    {
        QString input = m_input_stream.readLine();
        emit send(input, true);
    }
}

void Display::print(const QString& message)
{
    std::cout << message.toStdString() << "\n";
}
