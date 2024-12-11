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

            Button {
                width: 40
                height: 40
                text: "<"
                font.pointSize: 24
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter

                onClicked : {
                    page_list.gotoPreviousPage();
                }
            }
            Button {
                width: 40
                height: 40
                text: ">"
                font.pointSize: 24
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter

                onClicked: {
                    page_list.gotoNextPage();
                }
            }
        }

        PageContainerWidget {
            id: page_list
            width: parent.width
            anchors.topMargin: 10
            anchors.top: header.bottom
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }


    Rectangle {
            id: mainContent
            anchors.fill: parent
            color: "lightgray"

            Row {
                width: parent.width
                height: 100
                spacing: 40

            Button {
                text: "Show"
                anchors.top: parent.top
                onClicked: waitingSplash.show()
            }
            Button {
                text: "Hide"
                anchors.top: parent.top
                onClicked: waitingSplash.hide()
            }
            }
        }

        Wait {
            id: waitingSplash
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }

}
