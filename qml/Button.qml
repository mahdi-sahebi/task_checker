import QtQuick 2.6


Text {
    id: button
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    signal clicked

    Rectangle {
        id: background
        anchors.fill: parent
        radius: 5
        color: "#404040"
        opacity: 0.0
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled:  true

        onClicked : {
            button.clicked();
        }

        onEntered: {
            background.opacity = 0.15
        }

        onExited: {
            background.opacity = 0.0
        }

        onPressed: {
        background.opacity = 0.3
        }

        onReleased: {
            background.opacity = 0.15
        }
    }
}
