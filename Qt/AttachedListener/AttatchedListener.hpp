#pragma once

#include <QObject>
#include <QQmlEngine>

class AttatchedListener : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    QML_ANONYMOUS
    
public:
    explicit AttatchedListener();
    
    const QString& name() const;
    void setName(const QString& newName);
    
public slots:
    void doSomthing();
    
signals:
    void nameChanged();
    
private:
    QString m_name;
};