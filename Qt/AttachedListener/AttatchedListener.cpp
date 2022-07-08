#include "AttatchedListener.hpp"
#include <QDebug>

AttatchedListener::AttatchedListener()
{
    setName("Test");
}

const QString& AttatchedListener::name() const
{
    return m_name;
}

void AttatchedListener::setName(const QString& newName)
{
    if (m_name == newName)
        return;
    
    m_name = newName;
    emit nameChanged();
}

void AttatchedListener::doSomthing()
{
    qDebug() << "Say something";
}