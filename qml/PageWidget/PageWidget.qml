import QtQuick 2.6
import QtQuick.Window 2.2
import "TaskItemWidget"
import Task.Container 1.0
import Page.Page 1.0


Rectangle {
    property Page page
    color: "#f0f0f0"

    Column {
        anchors.fill: parent
        anchors.centerIn: parent

        Row {
            id: tasks
            anchors.fill: parent

            Rectangle {
                color: "#464646"
                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                radius: 10

                Rectangle {
                    color: "#464646"
                    width: 250
                    height: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: -15
                    radius: 10

                    Text {
                        text: page.title
                        color: "#f0f0f0"
                        font.pointSize: 20
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Column {
                    width: parent.width - 30
                    height: parent.height - 30
                    anchors.centerIn: parent

                    Repeater {
                        model: page.taskList
                        delegate: TaskItemWidget {
                            task_item: modelData
                        }
                    }
                }
            }
        }

        ProgressBar {
            id: progress_bar
            width: parent.width * 0.8
            height: 20
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 5
            percent: 0.97
        }

    }
}
