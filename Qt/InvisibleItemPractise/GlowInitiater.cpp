#include <qnamespace.h>
#include "GlowInitiater.hpp"
#include <QKeySequence>


GlowInitiater::GlowInitiater()
    : m_inExecution(false)
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

void GlowInitiater::timerFinished()
{
    QKeySequence sequence(m_keyCodes.at(1));
    auto keyAsInt( sequence.toString().toInt() );
    
    emit startGlow(keyAsInt);
    
    m_keyCodes.clear();
    m_inExecution = false;
}

void GlowInitiater::keyPressEvent(QKeyEvent* event)
{
    if(m_inExecution)
        return;
    
    if(event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9)
        m_keyCodes.emplace_back(event->key());
    else
        return;
    
    
    if(m_keyCodes.count() >= 2)
    {
        m_inExecution = true;
        
        QKeySequence sequence(m_keyCodes.at(0));
        auto keyAsInt( sequence.toString().toInt() );
        
        QTimer::singleShot(keyAsInt*1000, this, &GlowInitiater::timerFinished);
    }
}

void GlowInitiater::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        forceActiveFocus();
    }
}
