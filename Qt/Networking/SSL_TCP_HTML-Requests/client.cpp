#include "client.hpp"

Client::Client(QObject *parent) : QObject(parent)
{
    QObject::connect(&m_socket, &QSslSocket::connected, this, &Client::connected);
    QObject::connect(&m_socket, &QSslSocket::disconnected, this, &Client::disconnected);
    QObject::connect(&m_socket, &QSslSocket::hostFound, this, &Client::host_found);
    QObject::connect(&m_socket, &QSslSocket::proxyAuthenticationRequired, this, &Client::proxy_authentication_required);
    QObject::connect(&m_socket, &QSslSocket::errorOccurred, this, &Client::error_occured);
    QObject::connect(&m_socket, &QSslSocket::stateChanged, this, &Client::state_changed);
    QObject::connect(&m_socket, &QSslSocket::stateChanged, this, &Client::state_changed);
    QObject::connect(&m_socket, &QSslSocket::readyRead, this, &Client::ready_read);
    QObject::connect(&m_socket, &QSslSocket::bytesWritten, this, &Client::bytes_written);
    QObject::connect(&m_socket, &QSslSocket::bytesWritten, this, &Client::bytes_written);
    QObject::connect(&m_socket, &QSslSocket::sslErrors, this, &Client::ssl_errors);
    QObject::connect(&m_socket, &QSslSocket::preSharedKeyAuthenticationRequired, this, &Client::pre_shared_key_authentication_required);
    QObject::connect(&m_socket, &QSslSocket::modeChanged, this, &Client::mode_changed);
    QObject::connect(&m_socket, &QSslSocket::encryptedBytesWritten, this, &Client::encrypted_bytes_written);
    QObject::connect(&m_socket, &QSslSocket::encrypted, this, &Client::encrypted);
    QObject::connect(&m_socket, &QSslSocket::peerVerifyError, this, &Client::peer_verify_error);
    
}

void Client::connect_to_host(QString host, int port)
{
    qInfo() << "Connecting to host...";
    
    if(m_socket.isOpen()) disconnect();
    
    m_socket.setProtocol(QSsl::SecureProtocols);
    m_socket.connectToHostEncrypted(host, port);
}

void Client::disconnect()
{
    qInfo() << "Disconnecting";
    
    m_socket.close();
    
    // Wait until its disconnected to proceed
    m_socket.waitForDisconnected();
}


void Client::connected()
{
    qInfo() << "Connected!";
    
    qInfo() << "Sending...";
    
    // Request to get HTML source-code
    QByteArray data;
    data.append("GET / HTTP/1.1\r\n");
    data.append("Host: local\r\n");
    data.append("Connection: Close\r\n");
    data.append("\r\n");
    
    m_socket.write(data);
    m_socket.waitForBytesWritten();
}

void Client::disconnected()
{
    qInfo() << "Disconnected";
}

void Client::host_found()
{
    qInfo() << "Host found, trying to connect...";
}

void Client::proxy_authentication_required(const QNetworkProxy& proxy, QAuthenticator* authenticator)
{
    qDebug() << "Proxy authentification requiered!";
}

void Client::error_occured(QAbstractSocket::SocketError socket_error)
{
    qDebug() << "Socket error: " << socket_error << " " << m_socket.errorString();
}

void Client::state_changed(QAbstractSocket::SocketState socket_state)
{
    QMetaEnum meta_enum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State changed to: " << meta_enum.valueToKey(socket_state);
}

void Client::ready_read()
{
    qInfo() << "Reading ...";
    qInfo() << m_socket.readAll();
    
    m_socket.waitForReadyRead(10000);
}

void Client::bytes_written(qint64 bytes)
{
    qInfo() << "Bytes written: " << bytes;
}


void Client::ssl_errors(const QList<QSslError>& errors)
{
    qDebug() << "SSL errors:";
    
    for(const QSslError& error : errors)
    {
        qDebug() << error.errorString();
    }
}

void Client::pre_shared_key_authentication_required(QSslPreSharedKeyAuthenticator* authenticator)
{
    qDebug() << "Pre-shared authentification requiered!";
}

void Client::mode_changed(QSslSocket::SslMode mode)
{
    qInfo() << "SSL mode changed to: " << mode;
}

void Client::encrypted_bytes_written(qint64 written)
{
    qInfo() << "Encrypted bytes written: " << written;
}

void Client::encrypted()
{
    qInfo() << "Channel is now encrypted!";
}

void Client::peer_verify_error(const QSslError& error)
{
    qCritical() << "Peer verify error: " << error.errorString();
}
