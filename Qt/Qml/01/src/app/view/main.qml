import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import "components"
import "js/utility.js" as Util


Window
{
    id: root
    width: 820
    height: 575
    visible: true
    title: qsTr("QML Learning")
    
    
    Frame
    {
        id: sidebarFrame
        width: 160
        height: parent.height
        
        ColumnLayout
        {
            width: parent.width
            spacing: 30
            
            Image 
            {
                id: resetImage
                sourceSize.width:  50
                sourceSize.height: 50
                Layout.topMargin: 20
                Layout.alignment: Qt.AlignHCenter
                source: "/resources/app/images/Refresh_Icon.png"
                
                MouseArea
                {
                    anchors.fill: parent
                    
                    onClicked:
                    {
                        Util.setListContent();
                    }
                }
            }
            
            GroupBox
            {
                id: defaultContentGroupBox
                width: sidebarFrame.width
                height: 100
                Layout.alignment: Qt.AlignHCenter
                
                ColumnLayout
                {
                    width: parent.width
                    RadioButton
                    {
                        checked: true
                        text: qsTr("Fruits");
                        
                        onCheckedChanged:
                        {
                            if(checked)
                            {
                                Util.setListContent(Util.fruitList);
                            }
                        }
                    }
                    
                    RadioButton
                    {
                        text: qsTr("Animals");
                        
                        onCheckedChanged:
                        {
                            if(checked)
                            {
                                Util.setListContent(Util.animalList);
                            }
                        }
                    }
                    
                    RadioButton
                    {
                        text: qsTr("Empty");
                        
                        onCheckedChanged:
                        {
                            if(checked)
                            {
                                Util.setListContent(Util.emptyList);
                            }
                        }
                    }
                }
            }
        }
    }
    
    Frame
    {
        id: mainFrame
        width: parent.width - sidebarFrame.width
        height: parent.height
        anchors.left: sidebarFrame.right
        
        ColumnLayout
        {
            width: parent.width
            spacing: 20
            
            Label
            {
                id: editableComoBoxLabel
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Choose action")
                font.pointSize: 20
                font.bold: true
            }
            
            MComboBox
            {
                id: editableComoboBox
                Layout.alignment: Qt.AlignHCenter
                editable: true
                textRole: "text"
                model: ListModel
                {
                    id: editableComoBoxList
                }
                
                
                // Validate new text and replace old text with new text if valid
                onAccepted:
                {
                    if(editText === "")
                        return;
                    if(find(editText, Qt.MatchFixedString) !== -1)
                        return;
                    
                    editableComoBoxList.set(currentIndex, { text: editText});
                }
                
                
                Component.onCompleted:
                {
                    Util.setListContent();
                }
            }
            
            
            Item { width: parent.width; height: 20 }
            
            
            Label
            {
                id: addButtonLabel
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Add new Item")
                font.pointSize: 20
                font.bold: true
            }
            
            Row
            {
                Layout.alignment: Qt.AlignHCenter
                spacing: 15
                
                MButton
                {
                    id: addButton
                    text: "Add"
                    font.pointSize: 12
                    font.bold: true
                    
                    onClicked:
                    {
                        if(newItemText.text !== "" && newItemText.text.length >= 2)
                        {
                            editableComoBoxList.append({text: newItemText.text});
                            newItemText.text = "";
                        }
                    }
                }
                
                Rectangle
                {
                    id: newItemTextBackground
                    color: "gray"
                    width:  100
                    height: 30
                    
                    TextInput
                    {
                        id: newItemText
                        width: 100
                        height: parent.height
                        padding: 5
                        anchors.verticalCenter: parent.verticalCenter
                        text: ""
                        color: "white"
                        font.pointSize: 13
                        
                        Keys.onPressed: function(event)
                        {
                            if(event.key === Qt.Key_Return)
                            {
                                if(newItemText.text !== "" && newItemText.text.length >= 2)
                                {
                                    editableComoBoxList.append({text: newItemText.text});
                                    newItemText.text = "";
                                }
                            }
                        }
                    }
                }
            }
            
            Item { width: parent.width; height: 20 }
            
            
            Label
            {   
                id: deletionLabel
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Delete this tiem")
                color: "red"
                font.pointSize: 18
                font.bold: true
            }
            
            MDelayButton
            {
                id: deleteButton
                width: 100
                height: 60
                Layout.alignment: Qt.AlignHCenter
                text: editableComoboBox.currentText
                delay: 1500
                
                
                onCheckedChanged:
                {
                    if(deleteButton.checked === false && editableComoBoxList.count > 0)
                    {
                        loadingTimer.start();
                    }
                }
            }
            
            Item { width: parent.width; height: 10 }
            
            BusyIndicator
            {
                id: loading
                Layout.alignment: Qt.AlignHCenter
                visible: loadingTimer.running
                
                Timer
                {
                    id: loadingTimer
                    interval: 1500
                    
                    onTriggered:
                    {
                        Util.deleteItemFromComboBoxAndRotateSelection();
                    }
                }
            }
        }
    }
}
