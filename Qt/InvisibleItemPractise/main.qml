import QtQuick
import Qt5Compat.GraphicalEffects
import Practise.QmlComponents


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("InvisibleItemPractise")
    
    
    Glow
    {
        id: glow
        visible: glowAnimation.running
        opacity: 0
        anchors.fill: rect
        radius: 60
        spread: 0
        color: "blue"
        transparentBorder: true
        source: rect
        
        
        SequentialAnimation
        {
            id: glowAnimation
            
            
            PropertyAnimation
            {
                target: glow
                properties: "opacity"
                duration: 400
                to: 1
            }
            
            PauseAnimation
            {
                duration: 100
            }
            
            PropertyAnimation
            {
                target: glow
                properties: "opacity"
                duration: 300
                to: 0
            }
        }
    }
    
    Rectangle
    {
        id: rect
        property int repeatingCount: 0
        
        width: parent.width / 2
        height: parent.height / 2
        anchors.centerIn: parent
        color: "green"
        
        GlowInitiater
        {
            id: glowInitiater
            width: parent.width
            height: parent.height
            
            onStartGlow: 
                (amount) =>
                {
                    rect.repeatingCount = amount;
                    timer.start();
                }
        }
        
        Timer
        {
            id: timer
            interval: 1000
            
            onTriggered: 
            {
                if(rect.repeatingCount > 0)
                {
                    glowAnimation.start();
                    rect.repeatingCount = rect.repeatingCount - 1;
                    timer.start();
                }
            }
        }
    }
}