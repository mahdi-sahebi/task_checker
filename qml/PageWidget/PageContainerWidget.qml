import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.12

Rectangle {
    color: "#f0f0f0"

    SwipeView {
        id: swipe
        anchors.fill: parent
        anchors.centerIn: parent
        spacing: 5

        Repeater {
            model: page_container.list
            delegate:

            PageWidget {
                width: swipe.width
                height: swipe.height

                page: modelData
            }
        }/* Repeater */
    }/* SwipeView */
}

//page container in qml is not on the page class

