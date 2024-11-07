import QtQuick 2.6
import QtQuick.Window 2.2

Row
{
    width: parent.width
    height: 40

    Image
    {
        id: button
        source: task_item.image_path
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter

        MouseArea
        {
            anchors.fill: parent
            enabled: task_item.is_enabled

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
