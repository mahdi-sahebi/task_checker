import QtQuick 2.6
import QtQuick.Window 2.2

Window
{
    id: window
    visible: true
    width: 600
    height: 800
    title: "Hello World"
    color: "#f0f0f0"

    Column
    {
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        Row
        {
            id: header
            width: parent.width
            height: 50

            Text
            {
                text: "<"
                font.pointSize: 24
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
            }
            Text
            {
                text: "Page Title"
                font.pointSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            Text
            {
                text: ">"
                font.pointSize: 24
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
