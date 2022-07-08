#include "Attachee.hpp"
#include "AttatchedListener.hpp"
#include "qnamespace.h"


Attachee::Attachee()
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Attachee::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}