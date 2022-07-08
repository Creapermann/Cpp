#pragma once

#include "qqmlintegration.h"
#include "qtmetamacros.h"
#include <QObject>
#include <QQuickItem>

class Attachee : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    
public:
    explicit Attachee();

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();
};