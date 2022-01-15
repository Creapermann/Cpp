import QtQuick 

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    
    Rectangle
    {
        anchors.centerIn: parent
        width: 100
        height: 60
        color: "gray"
        
        Text
        {
            id: text
            anchors.centerIn: parent
            text: "Click me!"
            font.family: "Sans sarif"
            font.pointSize: 12
        }
        
        MouseArea
        {
            anchors.fill: parent
            
            onClicked:
            {
                text.visible = (text.visible ? false : true)
                console.log("WORKS");
            }
        }
    }
}
