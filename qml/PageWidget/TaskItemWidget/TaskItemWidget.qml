import QtQuick 2.6
import QtQuick.Window 2.2
import Task.Item 1.0

Row {
    property TaskItem task_item: null

    width: parent.width
    height: 40

    Image {
        id: button
        source: task_item.image_path
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter

        MouseArea {
            anchors.fill: parent
            enabled: task_item.is_enabled

            onClicked: {
                task_item.Run();
            }
        }
    }

    RotationAnimation {
        id: rotation
        target: button
        property: "rotation"
        duration: 1000
        from: 0
        to: 360
        loops: Animation.Infinite
        running: !task_item.is_enabled

        onStopped: {
            button.rotation = 0;
        }
    }

    Connections {
        target: task_item

        onEnableChanged: {
        }
    }

    Text {
        color: "#f0f0f0"
        text: task_item.title
        font.pointSize: 16
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        opacity: task_item.is_enabled ? 1 : 0.5
    }
}
