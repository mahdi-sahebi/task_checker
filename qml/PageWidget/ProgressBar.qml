import QtQuick 2.6


Item {
    property real percent: 0

    Rectangle {
        color: "#666666"
        anchors.fill: parent
        radius: 5
    }
    Rectangle {
        color: "#ff8000"
        width: (parent.width * progress_bar.percent)
        height: parent.height
        radius: 5
    }
    Text {
        text: (progress_bar.percent * 100) + "%"
        anchors.centerIn: parent
        font.pointSize: 16
        color: "#ffffff"
    }
}
