import QtQuick 2.6
import QtQuick.Window 2.2
import "PageWidget"// TODO(MN): rename to Page

Window
{
    id: window
    visible: true
    width: 600
    height: 800
    title: "Hello World"
    color: "#f0f0f0"
    // TODO(MN): Manage resizing

    Row {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 10

        Column {
            id: header
            height: 40
            width: parent.width

            Text {
                text: "<"
                font.pointSize: 24
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                text: ">"
                font.pointSize: 24
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        PageContainerWidget {
            width: parent.width
            anchors.top: header.bottom
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter


        }
    }
}
