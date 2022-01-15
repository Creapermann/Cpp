import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts

FocusScope
{
    id: root
    width: closedWidth
    height: 100
    
    property int   closeDuration : 475
    property int   openDuration :  250
    property int   openedWidth : 200
    property int   closedWidth : 75
    property color backgroundColor : "white"
    property bool  closed : true
    property int   animationEasingType : Easing.OutQuad
    
    signal opening()
    signal closing()
    signal fullyOpened()
    signal fullyClosed()
    
    onClosedChanged:
    {
        if(closed)
            prvt.close();
        else
            prvt.open();
    }
    
    
    Item
    {
        id: prvt
        height: parent.height
        width:  parent.width
        
        function open()
        {
            opening();
            openTimer.start();
            openAnimation.start();
            seperator1OpenAnimation.start();
        }
        
        function close()
        {
            closing();
            closeTimer.start();
            closeAnimation.start();
            seperator1CloseAnimation.start();
            print("close");            
        }
        
        
        Rectangle
        {
            id: background
            height: parent.height
            width:  parent.width
            color: root.backgroundColor
            
            ColumnLayout
            {
                id: layout
                width: parent.width
                spacing: 0
                property int iconWidth : 44
                property int screenBorderWidth : 1
                property int leftPaddingToCenter : ((sidebar.closedWidth - iconWidth) / 2) - screenBorderWidth
                
                Row
                {
                    width: parent.width
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    Layout.topMargin: 20
                    Layout.leftMargin: (sidebar.closedWidth - logo.width) / 2 - layout.screenBorderWidth + 1
                    
                    Rectangle
                    {
                        id: logo
                        height: 40
                        width:  40
                        color: "#4945FF"
                        radius: 8
                        
                        Rectangle
                        {
                            anchors.centerIn: parent
                            width: parent.width / 2
                            height: parent.height / 2
                            radius: width / 4
                            color: "#F6F6F6"
                        }
                    }
                }
                
                Rectangle
                {
                    id: seperator1
                    height: 2
                    width: root.closedWidth
                    Layout.topMargin: 16              
                    color: "#EAEAEF"
                }
                
                Row
                {
                    id: download
                    width: parent.width
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    Layout.topMargin: 18
                    Layout.leftMargin: layout.leftPaddingToCenter
                    
                    Image
                    {
                        id: downloadIcon
                        width: layout.iconWidth
                        source: "/resources/app/images/download_arrow_icon.png"
                        fillMode: Image.PreserveAspectFit
                    }
                }
                
                Rectangle
                {
                    id: seperator2
                    height: 2
                    width: (root.closedWidth / 2) + 5
                    Layout.leftMargin: ((root.width - width) / 2) - layout.screenBorderWidth
                    Layout.topMargin: 16
                    color: "#EAEAEF"
                }
            }
        }
    }
    
    Timer
    {
        id: closeTimer
        interval: root.closeDuration
        
        onTriggered:
        {
            root.fullyClosed();
        }
    }
    
    Timer
    {
        id: openTimer
        interval: root.openDuration - 50
        
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
        duration: closeDuration
        to: root.closedWidth
        easing.type: animationEasingType
    }
    NumberAnimation
    {
        id: openAnimation
        target: root
        property: "width"
        duration: openDuration
        to: root.openedWidth
        easing.type: animationEasingType
    }
    
    NumberAnimation
    {
        id: seperator1OpenAnimation
        target: seperator1
        property: "width"
        duration: openDuration
        easing.type: animationEasingType
        to: root.openedWidth
    }
    NumberAnimation
    {
        id: seperator1CloseAnimation
        target: seperator1
        property: "width"
        duration: closeDuration
        easing.type: animationEasingType
        to: root.closedWidth
    }
}