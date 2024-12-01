import QtQuick 2.6
import QtQuick.Window 2.2


Rectangle {
    anchors.fill: parent
    anchors.centerIn: parent

    Repeater {
        model: page_container.list
        delegate: PageWidget {
            page: modelData
        }
    }
}


//page container in qml is not on the page class
