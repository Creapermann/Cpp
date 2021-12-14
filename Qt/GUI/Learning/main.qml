import QtQuick 
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts


Window 
{
    width: 640
    height: 480
    visible: true
    title: qsTr("My first window")
    
    Rectangle
    {
        id: outerRect
        
        color: "blue"
        
        anchors
        {
            top:    parent.top
            bottom: parent.bottom
            left:   parent.left
            right:  parent.right
        }
        
        Rectangle
        {
            id: innerRect
            
            anchors.centerIn: parent
            width: 200
            height: 150
            color: "green"
            
            TextArea
            {
                id: innerInputArea
                
                anchors.centerIn: parent
                width: 120
                height: 30
                color: black
                text: "Input here"
            }
        }
    }
}