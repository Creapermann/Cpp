import QtQuick
import AttachedListener

Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    
    
    
    Rectangle
    {
        width: parent.width/2
        height: parent.height/2
        anchors.centerIn: parent
        color: "green"
        
        
        Attachee
        {
            id: attchee
            anchors.fill: parent
            
            onClicked: Attacher.doSomthing()
        }
    }
}