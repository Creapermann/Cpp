#include "Attacher.hpp"

Attacher::Attacher(QObject *parent)
    : QObject{parent}
{
}

AttatchedListener* Attacher::qmlAttachedProperties(QObject* object)
{
    auto attatchedListener = new AttatchedListener();
    attatchedListener->setParent(object);
    
    return attatchedListener;
}