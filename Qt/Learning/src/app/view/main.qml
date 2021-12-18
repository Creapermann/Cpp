import QtQuick
import QtQuick.Window

import "components"


Window
{
    id: root
    width: 820
    height: 525
    visible: true
    title: qsTr("QML Learning")
    
    
    Shortcut
    {
        sequence: "CTRL+1"
        onActivated:
        {
            if(field1.positionX < field2.positionX)
            {
                field2.focus = false;
                field1.focus = true;
            }
            else
            {
                field1.focus = false;
                field2.focus = true;
            }
        }
    }
    
    Shortcut
    {
        sequence: "CTRL+2"
        onActivated:
        {
            if(field1.positionX > field2.positionX)
            {
                field2.focus = false;
                field1.focus = true;
            }
            else
            {
                field1.focus = false;
                field2.focus = true;
            }
        }
    }
    
    
    MField
    {
        id: field1
        maxXDrag: root.width  - width
        maxYDrag: root.height - height
    }
    
    MField
    {
        id: field2
        maxXDrag: root.width  - width
        maxYDrag: root.height - height
    }
    
    
    
    Component.onCompleted:
    {
        field1.decreaseCounter.connect(field2.decrease)
        field2.decreaseCounter.connect(field1.decrease)
    }
}