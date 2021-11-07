#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QUrl>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    
signals:
    
    
public slots:
    void get(const QString& url);
    void post(const QString& url, const QByteArray& data);
    
private slots:
    void ready_read();
    
    // QNetworkAccessManager
    void authentication_required(QNetworkReply* reply, QAuthenticator* authenticator);
    void encrypted(QNetworkReply* reply);
    void finished(QNetworkReply* reply);
    void pre_shared_key_authentication_required(QNetworkReply* reply, QSslPreSharedKeyAuthenticator* authenticator);
    void proxy_authentication_required(const QNetworkProxy& proxy, QAuthenticator* authenticator);
    void ssl_errors(QNetworkReply* reply, const QList<QSslError>& errors);
    
    
private:
    QNetworkAccessManager m_network_manager;
    
};

#endif // CLIENT_HPP
