import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import "components"

Window
{
    id: root
    width: 820
    height: 525
    visible: true
    title: qsTr("QML Learning")
    
    ColumnLayout
    {
        width: parent.width
        spacing: 20
        
        
        Item { width: parent.width; height: 50 }
        
        
        Label
        {
            id: editableComoBoxLabel
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Choose action")
            font.pointSize: 20
            font.bold: true
        }
        
        ComboBox
        {
            id: editableComoboBox
            Layout.alignment: Qt.AlignHCenter
            editable: true
            textRole: "text"
            model: ListModel
            {
                id: editableComoBoxList
                
                ListElement { text: "Apple"; taste:  "sweet" }
                ListElement { text: "Banana"; taste: "sweet" }
                ListElement { text: "Berry"; taste:  "sour" }
                ListElement { text: "Grape"; taste:  "neutral" }
            }
            
            
            // Validate new text and replace old text with new text if valid
            onAccepted:
            {
                if(editText === "")
                    return;
                if(find(editText, Qt.MatchFixedString) !== -1)
                    return;
                
                editableComoBoxList.set(currentIndex, { text: editText, 
                                            taste: editableComoBoxList.get(currentIndex).taste });
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
            
            Button
            {
                id: addButton
                text: "Add"
                font.pointSize: 12
                font.bold: true
                
                onClicked:
                {
                    if(newItemText.text !== "" && newItemText.text.length >= 2)
                    {
                        editableComoBoxList.append({text: newItemText.text, taste: "default"});
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
                
                TextEdit
                {
                    id: newItemText
                    width: 100
                    height: parent.height
                    textMargin: 5
                    anchors.verticalCenter: parent.verticalCenter
                    text: ""
                    color: "white"
                    font.pointSize: 12
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
            width: 100
            height: 60
            Layout.alignment: Qt.AlignHCenter
            text: editableComoboBox.currentText
            delay: 1500
            
            
            onCheckedChanged:
            {
                if(checked === false && editableComoBoxList.count > 0)
                {
                    editableComoBoxList.remove(editableComoboBox.currentIndex);
                    
                    if(editableComoboBox.currentIndex === editableComoBoxList.count && 
                            editableComoboBox.currentIndex !== 0)
                        editableComoboBox.decrementCurrentIndex();
                }
            }
        }
        
        Item { width: parent.width; height: 10 }
        
        BusyIndicator
        {
            Layout.alignment: Qt.AlignHCenter
        }
        
    }
}
