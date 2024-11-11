import QtQuick 2.15

Item {
    id: modeDelegate
    property alias modeName: nameText.text
    property alias power: powerText.text
    property bool isLeft
    property string activeColor : isLeft ? "gold" : "royalblue"

    height: parent.height - 8;

    Rectangle {
        id: backPlate
        anchors.fill: parent
        radius: 6
        color: activeColor

        Text {
            id: powerText
            width: parent.width
            height: .7*parent.height
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Font.bold: true
            Font.pixelSize: 24
            // text: qsTr("text")
        }
        Text {
            id: nameText
            width: parent.width
            height: .3*parent.height
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            // text: qsTr("text")
        }

    }

}
