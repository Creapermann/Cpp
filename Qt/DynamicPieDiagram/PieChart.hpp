#pragma once

#include <QQuickItem>
#include <QQmlEngine>
#include <QQuickPaintedItem>

class PieChart : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(double fill READ fill WRITE setFill NOTIFY fillChanged)
    QML_ELEMENT
    
public:
    PieChart();
    void paint(QPainter* painter) override;
    
    const QColor& color() const;
    void setColor(const QColor& newColor);
    
    const QString& name() const;
    void setName(const QString& newName);
    
    double fill() const;
    void setFill(double newFill);
    
signals:
    void colorChanged();
    void nameChanged();
    void fillChanged();
    
private:
    QColor m_color;
    QString m_name;
    int m_fill;
};