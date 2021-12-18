import QtQuick

FocusScope {
    id: root
    
    width:  mainRect.width
    height: mainRect.height
    
    property variant colors: ["dodgerblue", "green", "grey", "yellow", "purple", "pink"]
    property int maxXDrag: 500
    property int maxYDrag: 500
    property int minXDrag: 0
    property int minYDrag: 0
    
    property alias backgroundColor: mainRect.color
    property alias startingText: counterText.text
    property alias fontColor: counterText.color
    property alias fontPointSize: counterText.font.pointSize
    property alias fontBold: counterText.font.bold
    property alias borderWidth:  mainRect.border.width
    property alias borderColor:  mainRect.border.color
    property alias borderRadius: mainRect.radius
    
    signal decreaseCounter();
    
    function decrease() { mainRect.counter--; }
    
    Keys.onPressed: function(event)
    {
        if(event.key === Qt.Key_Return)
        {
            mainRect.color = colors[Math.floor(Math.random() * colors.length)];
        }
    }
    
    
    Rectangle
    {
        id: mainRect
        width: 120
        height: 90
        color: "grey"
        border.width: 2
        border.color: root.focus ? "red" : "black"
        radius: 12
        
        property int counter: 0
        
        MouseArea
        {
            id: mouseArea
            anchors.fill: mainRect
            drag.target: mainRect
            drag.axis: Drag.XAndYAxis
            drag.minimumX: minXDrag
            drag.minimumY: minYDrag
            drag.maximumX: maxXDrag
            drag.maximumY: maxYDrag
            
            
            onClicked: 
            {
                root.focus = true;
                root.decreaseCounter();
                mainRect.counter += 2;
            }
        }
        
        Text 
        {
            id: counterText
            text: mainRect.counter
            anchors.centerIn: parent
            font.pointSize: 22
            font.bold: true
        }
    }
}
