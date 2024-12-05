import QtQuick 2.6


Text {
    signal clicked

    MouseArea {
        anchors.fill: parent

        onClicked : {
            clicked();
        }
    }
}
