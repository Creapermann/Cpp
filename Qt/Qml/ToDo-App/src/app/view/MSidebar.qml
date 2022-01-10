import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts

FocusScope
{
    id: root
    width: closedWidth
    height: 100
    
    property int   closedWidth : 60
    property int   openedWidth : 200
    property int   animationDuration : 200
    property color backgroundColor : "white"
    property bool  closed : true
    
    signal opening()
    signal closing()
    signal fullyOpened()
    signal fullyClosed()
    
    onClosedChanged:
    {
        if(closed)
        {
            closing();
            closeAnimation.start();
            closeTimer.start();
        }
        else
        {
            opening();
            openAnimation.start();
            openTimer.start();
        }
        
        
    }
    
    
    Item
    {
        id: prvt
        height: parent.height
        width:  parent.width
        
        Rectangle
        {
            id: background
            height: parent.height
            width:  parent.width
            color: root.backgroundColor
        }
    }
    
    Timer
    {
        id: closeTimer
        interval: root.animationDuration
        
        onTriggered:
        {
            root.fullyClosed();
        }
    }
    
    Timer
    {
        id: openTimer
        interval: root.animationDuration
        
        onTriggered:
        {
            root.fullyOpened();
        }
    }
    
    
    NumberAnimation
    {
        id: closeAnimation
        target: root
        property: "width"
        duration: animationDuration
        to: root.closedWidth
        easing.type: Easing.Linear
    }
    
    NumberAnimation
    {
        id: openAnimation
        target: root
        property: "width"
        duration: animationDuration
        to: root.openedWidth
        easing.type: Easing.Linear
    }
}