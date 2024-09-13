import QtQuick 2.6
import QtQuick.Window 2.2

Row
{
    width: parent.width
    height: 40

    property string title: "";

    Image
    {
        id: image1
        source: "assets/check.png"
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter

        MouseArea
        {
            anchors.fill: parent

            onClicked:
            {
                task_item.Check();
            }
        }
    }

    Text
    {
        color: "#f0f0f0"
        text: task_item.title
        font.pointSize: 16
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.verticalCenter: parent.verticalCenter
    }
}
