import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts



ApplicationWindow {
    id: root
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Hello World")
    background: Rectangle
    {
        anchors.fill: parent
        color: "#24292D"
    }
    
    MSidebar
    {
        id: sidebar
        height: root.height
        closedWidth: 60
        openedWidth: 180
        backgroundColor: "#3B4146"
    }
    
    Button
    {
        anchors.centerIn: parent
        width: 100
        height: 60
        
        onClicked:
        {
            if(sidebar.closed === true)
                sidebar.closed = false;
            else
                sidebar.closed = true;
        }
    }
    
    
//    Rectangle
//    {
//        id: sidebar
//        width: 70
//        height: root.height
        
//        color: "gray"
//    }
    
//    ColumnLayout
//    {
//        id: layout
//        width: root.width - sidebar.width - sideBuffer*2
//        anchors.top: parent.top
//        anchors.right: parent.right
//        anchors.rightMargin: sideBuffer
//        spacing: 5
        
//        property int sideBuffer : 20
        
//        Label
//        {
//            id: title
//            Layout.topMargin: 20
//            text: "ToDo:"
//            font.pointSize: 28
//            font.bold: true
//            color: "dodgerblue"
//        }
        
//        Rectangle
//        {
//            id: outerAddButton
//            height: 60
//            width: parent.width
//            Layout.topMargin: 15
//            border.width: 2
//            color: "#2B2F33"
//            border.color: "gray"
//            radius: 8
            
            
//            Row
//            {
//                height: parent.height
//                anchors.left: parent.left
//                anchors.leftMargin: 18
//                spacing: 14
                
//                Image
//                {
//                    id: plusImage
//                    width: 28
//                    source: "/resources/app/images/plus.png"
//                    fillMode: Image.PreserveAspectFit 
//                    anchors.verticalCenter: parent.verticalCenter
//                }
                
//                Label
//                {
//                    id: addText
//                    text: "Add a new entry"
//                    font.pointSize: 16
//                    font.bold: true
//                    font.family: "sans sarif"
//                    anchors.verticalCenter: parent.verticalCenter
//                    color: "dodgerblue"
//                }
//            }
//        }
        
        
//        ListView
//        {
//            id: listView
//            width:  parent.width
//            height: model.count * entryHeight
//            Layout.topMargin: 30
            
//            property int topSpace : 5
//            property int entryHeight : 65 + topSpace
            
//            model: ListModel
//            {
//                id: model
                
//                ListElement
//                {
//                    name: "Clean up room"
//                }
//                ListElement
//                {
//                    name: "Bring out trash"
//                }
//                ListElement
//                {
//                    name: "Do homework"
//                }
//                ListElement
//                {
//                    name: "Go out with dog"
//                }
//                ListElement
//                {
//                    name: "Wash dishes"
//                }
//            }
            
//            delegate: Column
//            {
//                id: delegate
//                width: listView.width
//                height: listView.entryHeight
                
//                Rectangle
//                {
//                    width: parent.width
//                    height: listView.topSpace
//                    color: "transparent"
//                }
                
//                Rectangle
//                {
//                    height: listView.entryHeight - listView.topSpace
//                    width:  parent.width
//                    color: "#2B2F33"
//                    border.width: 1
//                    border.color: "gray"
//                    radius: 8
                    
//                    Row
//                    {
//                        height: parent.height
//                        anchors.left: parent.left
//                        anchors.leftMargin: 18
//                        spacing: 14
                        
//                        Image
//                        {
//                            id: checkCircleImage
//                            width: 28
//                            source: "/resources/app/images/circle.png"
//                            fillMode: Image.PreserveAspectFit 
//                            anchors.verticalCenter: parent.verticalCenter
//                            antialiasing: true
//                        }
                        
//                        Label
//                        {
//                            id: circleTick
//                            anchors.verticalCenter: parent.verticalCenter
//                            text: modelData
//                            font.family: "sans sarif"
//                            font.pointSize: 18
//                        }
//                    }
//                }
//            }
//        }
//    }
}
