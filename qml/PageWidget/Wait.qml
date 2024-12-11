import QtQuick 2.6


// TODO(MN): Make it available to change image source, speed, etc from outside
Rectangle {
    id: mask

    color: "black"
    opacity: 0
    visible: false
    z: 100


    Image {
        property real ratio: 1

        id: waiting
        width: Math.min(parent.width * 0.5, parent.height * ratio)
        height: width * ratio
        anchors.centerIn: parent
        source: "TaskItemWidget/assets/wait.png"

        RotationAnimation {
            id: rotationAnimation
            target: waiting
            property: "rotation"
            duration: 2000
            loops: Animation.Infinite
            from: 0
            to: 360
            running: true
        }
    }

    PropertyAnimation {
        id: fadeInAnimation
        target: mask
        property: "opacity"
        from: 0
        to: 0.7
        duration: 500
    }

    PropertyAnimation {
        id: fadeOutAnimation
        target: mask
        property: "opacity"
        from: 0.7
        to: 0
        duration: 500

        onStopped: {
            mask.visible = false;
        }
    }

    function show() {
        mask.visible = true
        fadeInAnimation.start()
    }

    function hide() {
        fadeOutAnimation.start();
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.AllButtons
        preventStealing: true
    }
}
