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