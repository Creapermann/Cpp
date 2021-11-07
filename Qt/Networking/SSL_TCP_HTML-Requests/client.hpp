#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QSslSocket>
#include <QMetaEnum>
#include <QNetworkProxy>
#include <QAuthenticator>
#include <QByteArray>
#include <QSslPreSharedKeyAuthenticator>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    
signals:
    
public slots:
    void connect_to_host(QString host, int port);
    void disconnect();
    
private slots:
    // QTcpSocket
    void connected();
    void disconnected();
    void host_found();
    void proxy_authentication_required(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void error_occured(QAbstractSocket::SocketError socket_error);
    void state_changed(QAbstractSocket::SocketState socket_state);
    void ready_read();
    void bytes_written(qint64 bytes);
    
    // QSslSocket
    void ssl_errors(const QList<QSslError> &errors);
    void pre_shared_key_authentication_required(QSslPreSharedKeyAuthenticator *authenticator);
    void mode_changed(QSslSocket::SslMode mode);
    void encrypted_bytes_written(qint64 written);
    void encrypted();
    void peer_verify_error(const QSslError &error);
    
private:
    QSslSocket m_socket;
};

#endif // CLIENT_HPP
