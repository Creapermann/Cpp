import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts
import DynamicPieDiagram.Elements


Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("DynamicPieDiagram")
    
    
    ColumnLayout
    {
        id: mainLayout
        width: parent.width
        anchors.centerIn: parent
        spacing: 20
        
        
        Slider
        {
            id: slider
            Layout.preferredWidth: parent.width / 2
            Layout.alignment: Qt.AlignHCenter
        }
        
        PieChart
        {
            id: pieChart
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100
            Layout.alignment: Qt.AlignHCenter
            name: "A piechart"
            color: "red"
            fill: slider.value * 360
        }
        
        Label
        {
            id: pieChartNameDisplayLabel
            Layout.alignment: Qt.AlignHCenter
            text: pieChart.name
            font.pointSize: 14
            color: "black"
        }
    }
}