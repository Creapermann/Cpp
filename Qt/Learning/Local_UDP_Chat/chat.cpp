#include "chat.hpp"

Chat::Chat(QObject *parent) 
    : QObject(parent), m_port{2020}
{
    if(m_socket.bind(m_port, QAbstractSocket::ReuseAddressHint))
    {
        
        QObject::connect(&m_socket, &QUdpSocket::readyRead, this, &Chat::read);
    }
    else
    {
        qDebug() << m_socket.errorString();    
    }
}

void Chat::send(QString& message, bool prepend_name)
{
    // prepend name to message only if requested
    if(prepend_name)
        message.prepend(m_name + ": ");
    
    if(!m_socket.writeDatagram(message.toUtf8(), QHostAddress::Broadcast, m_port))
    {
        qDebug() << m_socket.errorString();  
    }
}

void Chat::read()
{
    while(m_socket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = m_socket.receiveDatagram();
        
        
        // Prevent from printing your own data
        if(!datagram.data().startsWith(m_name.toUtf8()))
            std::cout << datagram.data().toStdString() << "\n";
    }
}

void Chat::login()
{
    std::cout << "Please enter your name: ";
    std::string name;   
    std::cin >> name;
    
    m_name = name.c_str();
    
    // Locally printing that user joined
    std::cout << m_name.toStdString() + " joined!\n";
    
    // Sending the message user joined to other users
    QString temp = m_name + " joined!";
    send(temp, false);
}
