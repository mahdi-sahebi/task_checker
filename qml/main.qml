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


        Row
        {
            width: parent.width
            anchors.top: header.bottom
            anchors.topMargin: 25
            anchors.bottom: progress.top

            Rectangle
            {
                color: "#464646"
                width: parent.width - 4 - 4
                height: parent.height - 4 - 4
                anchors.centerIn: parent
                radius: 10

                Rectangle
                {
                    color: "#464646"
                    width: 200
                    height: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: -15
                    radius: 10

                    Text
                    {
                        text: "Commands"
                        color: "#f0f0f0"
                        font.pointSize: 22
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Column
                {
                    width: parent.width - 30
                    height: parent.height - 30
                    anchors.centerIn: parent

                    Row
                    {
                        width: parent.width
                        height: 40

                        Rectangle
                        {
                            color: "#ff8000"
                            width: 20
                            height: 20
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text
                        {
                            color: "#f0f0f0"
                            text: "Sample text item"
                            font.pointSize: 16
                            anchors.left: parent.left
                            anchors.leftMargin: 30
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }

                    Row
                    {
                        width: parent.width
                        height: 40

                        Rectangle
                        {
                            color: "#ff8000"
                            width: 20
                            height: 20
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text
                        {
                            color: "#f0f0f0"
                            text: "Sample text item"
                            font.pointSize: 16
                            anchors.left: parent.left
                            anchors.leftMargin: 30
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }

                    Row
                    {
                        width: parent.width
                        height: 40

                        Rectangle
                        {
                            color: "#ff8000"
                            width: 20
                            height: 20
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text
                        {
                            color: "#f0f0f0"
                            text: "Sample text item"
                            font.pointSize: 16
                            anchors.left: parent.left
                            anchors.leftMargin: 30
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }
        }

        Row
        {
            id: progress
            width: parent.width
            height: 40
            anchors.bottom: footer.top

            Rectangle
            {
                color: "#ff8000"
                width: 500
                height: 20
                anchors.centerIn: parent
            }
        }

        Row
        {
            id: footer
            width: parent.width
            height: 30
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4

            Text
            {
                color: "#ff8000"
                text: "X/X"
                font.pointSize: 16
                anchors.centerIn: parent
            }
        }
    }
}
