#ifndef CHAT_HPP
#define CHAT_HPP

#include <iostream>
#include <string>

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>


class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = nullptr);
    
    void login();
    
signals:
    void print(const QString& message);

public slots:
    void send(QString& message, bool prepend_name);
    void read();
    
    
private:
    QUdpSocket m_socket;
    QString m_name;
    int m_port;
};

#endif // CHAT_HPP
