import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Testing.QmlComponents


ApplicationWindow
{
    id: root
    width: 600
    height: 800
    visible: true
    background: Rectangle
    {
        anchors.fill: parent
        color: "white"
    }
    
    
    Pane
    {
        id: container
        padding: 0
        anchors.fill: parent
        anchors.margins: 50
        background: Rectangle
        {
            color: "transparent"
            border.color: "gray"
        }
        
        
        ListView
        {
            anchors.fill: parent
            clip: true
            model: ToDoListModel
            {
                list: toDoList
            }
            
            delegate: RowLayout
            {
                width: parent ? parent.width : 100
                
                
                CheckBox
                {
                    checked: model.done
                    onClicked: model.done = !model.done
                }
                
                TextField
                {
                    Layout.fillWidth: true
                    text: model.description
                    onEditingFinished: model.description = text
                }
            }
        }
    }
}