#pragma once

#include "AttatchedListener.hpp"
#include "qqmlintegration.h"
#include <QObject>

class Attacher : public QObject
{
    Q_OBJECT
    QML_ATTACHED(AttatchedListener)
    QML_ELEMENT
    
public:
    explicit Attacher(QObject *parent = nullptr);
    
    static AttatchedListener* qmlAttachedProperties(QObject* object);
};

