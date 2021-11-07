#include "client.hpp"

Client::Client(QObject *parent) 
    : QObject(parent)
{
    QObject::connect(&m_network_manager, &QNetworkAccessManager::authenticationRequired, this, &Client::authentication_required);
    QObject::connect(&m_network_manager, &QNetworkAccessManager::encrypted, this, &Client::encrypted);
    QObject::connect(&m_network_manager, &QNetworkAccessManager::finished, this, &Client::finished);
    QObject::connect(&m_network_manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &Client::pre_shared_key_authentication_required);
    QObject::connect(&m_network_manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &Client::proxy_authentication_required);
    QObject::connect(&m_network_manager, &QNetworkAccessManager::sslErrors, this, &Client::ssl_errors);
}

void Client::get(const QString& url)
{
    qInfo() << "Getting...";
    
    QNetworkReply* reply = m_network_manager.get(QNetworkRequest(QUrl(url)));
    
    QObject::connect(reply, &QNetworkReply::readyRead, this, &Client::ready_read);
}

void Client::post(const QString& url, const QByteArray& data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "test/plain");
    
    QNetworkReply* reply = m_network_manager.post(request, data);
    
    QObject::connect(reply, &QNetworkReply::readyRead, this, &Client::ready_read);
}

void Client::ready_read()
{
    qInfo() << "Reading...";
    
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    
    if(reply)
        qInfo() << reply->readAll();
}

void Client::authentication_required(QNetworkReply* reply, QAuthenticator* authenticator)
{
    qDebug() << "Authentiaction requiered!";
}

void Client::encrypted(QNetworkReply* reply)
{
    qInfo() << "Now encrypted!";
}

void Client::finished(QNetworkReply* reply)
{
    qInfo() << "Finished";
    reply->deleteLater();
}

void Client::pre_shared_key_authentication_required(QNetworkReply* reply, QSslPreSharedKeyAuthenticator* authenticator)
{
    qDebug() << "Pre-shared key authentication required!";
}

void Client::proxy_authentication_required(const QNetworkProxy& proxy, QAuthenticator* authenticator)
{
    qDebug() << "Proxy authentication required";
}

void Client::ssl_errors(QNetworkReply* reply, const QList<QSslError>& errors)
{
    qDebug() << "SSL-Errors:";
    
    for(const QSslError& error : errors)
    {
        qDebug() << error.errorString();
    }
}
