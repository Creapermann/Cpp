#include <QPen>
#include <QPainter>
#include "PieChart.hpp"
#include "qnamespace.h"


PieChart::PieChart()
    : m_fill(90)
{
    
}


void PieChart::paint(QPainter* painter)
{
    QPen pen(m_color, 2);
    QBrush brush(m_color.lighter(), Qt::BrushStyle::Dense5Pattern);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 270*16, -m_fill*16);
}

const QColor& PieChart::color() const
{
    return m_color;
}

void PieChart::setColor(const QColor& newColor)
{
    if (m_color == newColor)
        return;
    
    m_color = newColor;
    emit colorChanged();
}


const QString& PieChart::name() const
{
    return m_name;
}

void PieChart::setName(const QString& newName)
{
    if (m_name == newName)
        return;
    
    m_name = newName;
    emit nameChanged();
}


double PieChart::fill() const
{
    return m_fill;
}

void PieChart::setFill(double newFill)
{
    if (m_fill == newFill)
        return;
    
    m_fill = newFill;
    this->update();
    emit fillChanged();
}