#pragma once

#include <QTimer>
#include <QQmlEngine>
#include <QQuickItem>


class GlowInitiater : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    
public:
    GlowInitiater();
    
signals:
    void startGlow(int amount);
    
private slots:
    void timerFinished();
    
protected:
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    
    
private:
    bool m_inExecution;
    QList<int> m_keyCodes;
};

