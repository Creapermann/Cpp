import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

import "components"


ApplicationWindow
{
    id: root
    width: 880
    height: 700
    visible: true
    title: qsTr("App Demo")
    background: Rectangle
    {
        anchors.fill: parent
        color: "#141719"
    }
    
    readonly property int contentFieldWidth : (root.width - closedSideBar.x + closedSideBar.width);
    
    
    Rectangle
    {
        id: closedSideBar
        height: root.height
        width: 52
        color: "#1a2229"
        
        ColumnLayout
        {
            anchors.fill: parent
            
            
            Button
            {
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                Layout.bottomMargin: 5
                width: closedSideBar.width - 10
                
                
                Image 
                {
                    id: expandImage
                    sourceSize.height: parent.height
                    sourceSize.width:  parent.width
                    anchors.centerIn: parent
                    source: "/resources/app/images/Expand.png"
                    
                    MouseArea
                    {
                        anchors.fill: parent
                        
                        onClicked:
                        {
                            openedSideBar.open();
                        }
                    }
                }
            }
        }
    }
    
    Drawer
    {
        id: openedSideBar
        width: openedWidth
        height: root.height
        
        readonly property int openedWidth : 160
        
        background: Rectangle
        {
            anchors.fill: parent
            color: "#1a2229"
        }
        
        ColumnLayout
        {
            anchors.fill: parent
            
            RowLayout
            {
                spacing: 8
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                
                Button
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredWidth: 45
                    Layout.preferredHeight: 45
                    Layout.bottomMargin: 5
                    Layout.leftMargin: 5
                    
                    onClicked:
                    {
                        profileEditDialog.open();
                    }
                    
                    Label
                    {
                        text: "P"
                        anchors.centerIn: parent
                        font.pointSize: 20
                        font.bold: true
                        color: "white"
                    }
                    
                    Dialog
                    {
                        id: profileEditDialog
                        width: root.width / 2
                        height: root.height / 2
                        x: Math.round((contentFieldWidth - width) / 2)
                        y: Math.round(root.height / 6)
                        title: "Your profile"
                        parent: Overlay.overlay
                        modal: true
                    }
                }
                
                Button
                {
                    
                    Layout.bottomMargin: 5
                    Layout.rightMargin:  8
                    Layout.preferredWidth: 90
                    Layout.preferredHeight: 38
                    Layout.alignment: Qt.AlignRight
                    
                    Image 
                    {
                        id: closeImage
                        sourceSize.height: 35
                        sourceSize.width:  closedSideBar.width - 10
                        anchors.centerIn:  parent
                        source: "/resources/app/images/Close.png"
                    }
                    
                    onClicked:
                    {
                        openedSideBar.close();
                    }
                }
            }
        }
    }
    
    
    Column
    {
        width: parent.width
        id: heading
        
        Item 
        { 
            width: parent.width; 
            height: 30
        }
        
        Label
        {
            
            x: Math.round(emailRect.x + emailRect.width / 2)
            font.bold: true
            font.pointSize: 15
            text: "Sign Up"
            color: "white"
        }
    }
    
    
    ColumnLayout
    {
        anchors.top:   heading.bottom
        anchors.right: parent.right
        anchors.left:  closedSideBar.right
        
        
        Item
        { 
            width: parent.width; height: 25
            Layout.alignment: Qt.AlignTop
        }
        
        Column
        {
            width: parent.width
            spacing: 5
            
            Label
            {
                x: contentFieldWidth * 0.2
                text: "Email"
                font.bold: true
                font.pointSize: 12
                color: "white"
            }
            
            Rectangle
            {
                id: emailRect
                x: contentFieldWidth * 0.2
                width: contentFieldWidth * 0.48
                height: 40
                color: "transparent"
                radius: 5
                border.width: 0
                border.color: "white"
                
                TextField
                {
                    id: emailField
                    anchors.fill: parent
                    color: "white"
                    background: Rectangle
                    {
                        anchors.fill: parent
                        color: parent.focus ? "transparent" : "#3f3f41"
                        radius: 5
                    }
                    
                    onFocusChanged: 
                    {
                        if(focus)
                            parent.border.width = 1;
                        else
                            parent.border.width = 0;
                    }
                }
            }
            
            Item 
            { 
                width: parent.width; height: 15
                Layout.alignment: Qt.AlignTop
            }
            
            Row
            {
                x: contentFieldWidth * 0.2
                spacing: 12
                
                Image
                {
                    sourceSize.height: 19
                    sourceSize.width: 19
                    source: "/resources/app/images/Phone.png"
                }
                
                Label
                {
                    text: "Use phone instead"
                    font.pointSize: 15
                    font.bold: true
                    color: "#9a67e7"
                }
            }
        }
        
        Item
        { 
            width: parent.width; height: 7
            Layout.alignment: Qt.AlignTop
        }
        
        Column
        {
            width: parent.width
            spacing: 5
            
            Label
            {
                x: contentFieldWidth * 0.2
                text: "Username"
                font.bold: true
                font.pointSize: 12
                color: "white"
            }
            
            Rectangle
            {
                x: contentFieldWidth * 0.2
                width: contentFieldWidth * 0.48
                height: 40
                color: "transparent"
                radius: 5
                border.width: 0
                border.color: "white"
                
                TextField
                {
                    id: usernameField
                    anchors.fill: parent
                    color: "white"
                    background: Rectangle
                    {
                        anchors.fill: parent
                        color: parent.focus ? "transparent" : "#3f3f41"
                        radius: 5
                    }
                    
                    onFocusChanged: 
                    {
                        if(focus)
                            parent.border.width = 1;
                        else
                            parent.border.width = 0;
                    }
                }
            }
            
            Item 
            { 
                width: parent.width; height: 8
                Layout.alignment: Qt.AlignTop
            }
            
            Column
            {
                width: parent.width
                spacing: 5
                
                Label
                {
                    x: contentFieldWidth * 0.2
                    text: "Password"
                    font.bold: true
                    font.pointSize: 12
                    color: "white"
                }
                
                Rectangle
                {
                    x: contentFieldWidth * 0.2
                    width: contentFieldWidth * 0.48
                    height: 40
                    color: "transparent"
                    radius: 5
                    border.width: 0
                    border.color: "white"
                    
                    TextField
                    {
                        id: passwordField
                        anchors.fill: parent
                        color: "white"
                        echoMode: TextInput.Password
                        
                        background: Rectangle
                        {
                            anchors.fill: parent
                            color: parent.focus ? "transparent" : "#3f3f41"
                            radius: 5
                        }
                        
                        onFocusChanged: 
                        {
                            if(focus)
                                parent.border.width = 1;
                            else
                                parent.border.width = 0;
                        }
                    }
                }
            }
            
            Item 
            { 
                width: parent.width; height: 8
                Layout.alignment: Qt.AlignTop
            }
            
            Column
            {
                width: parent.width
                spacing: 5
                
                Label
                {
                    x: contentFieldWidth * 0.2
                    text: "Date of Birth"
                    font.bold: true
                    font.pointSize: 12
                    color: "white"
                }
                
                Rectangle
                {
                    x: contentFieldWidth * 0.2
                    width: contentFieldWidth * 0.48
                    height: 40
                    color: "transparent"
                    radius: 5
                    border.width: 0
                    border.color: "white"
                    
                    TextField
                    {
                        id: dateOfBirthField
                        anchors.fill: parent
                        color: "white"
                        background: Rectangle
                        {
                            anchors.fill: parent
                            color: parent.focus ? "transparent" : "#3f3f41"
                            radius: 5
                        }
                        
                        onFocusChanged: 
                        {
                            if(focus)
                                parent.border.width = 1;
                            else
                                parent.border.width = 0;
                        }
                    }
                }
            }
        }
        
        Item
        { 
            width: parent.width; height: 12
            Layout.alignment: Qt.AlignTop
        }
        
        Item
        {
            width: root.width
            height: infoLabel.implicitHeight
            
            Label
            {
                id: infoLabel
                x: contentFieldWidth * 0.2
                width: contentFieldWidth * 0.48
                wrapMode: Text.Wrap
                textFormat: Text.RichText
                color: "#8f8f94"
                text: "By clicking Sing Up, you are indicating that you have read 
                       and acknowledged the <font color='#9a67e7'>Terms of Service</font> and 
                       <font color='#9a67e7'>Privacy Notice</font>."
                font.pointSize: 10
            }
        }
        
        Item
        { 
            width: parent.width; height: 15
            Layout.alignment: Qt.AlignTop
        }
        
        Column
        {
            width: root.width
            
            Rectangle
            {
                x: contentFieldWidth * 0.2
                width: contentFieldWidth * 0.48
                height: 40
                radius: 5
                color: "#3f3f41"
                
                enabled: (emailField.length >= 6 && usernameField.length >= 6 &&
                          passwordField.length >= 6 && dateOfBirthField.length >= 6) ? true : false
                
                Label
                {
                    anchors.centerIn: parent
                    color: "#cac8cd"
                    text: "Sign Up"
                    font.pointSize: 14
                    font.bold: true
                }
                
                MouseArea
                {
                    anchors.fill: parent
                    
                    onPressed:
                    {
                        parent.color = "#767479"
                    }
                    
                    onReleased:
                    {
                        parent.color = "#3f3f41"
                    }
                }
            }
        }
    }
}