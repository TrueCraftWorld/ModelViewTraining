import QtQuick 2.15
import QtQuick.Layouts 1.15


Item {
    id: rootDelegate
    width: ListView.view.width
    height: ListView.view.height/socListView.count
    property int socketState
    property int leftPower
    property alias leftName: leftMode.modeName
    property int rightPower
    property alias rightName: rightMode.modeName
    property alias socketName: socketNameText.text

    Rectangle{
        anchors.fill: parent
        // color: rootDelegate.socketState > 1 ? "black" : "gray"

        Text {
            anchors {
                left: parent.left
                top: parent.top
            }
            height: 10
            width: .5*parent.width

            id: socketNameText
            color: "black"
        }
        Row {
            id: layout
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            Layout.margins: 13

            Layout.alignment: Qt.AlignHCenter

            Mode {
                id: leftMode
                power: leftPower.toString()
                isLeft: true
                width: parent.width/2 -10

            }
            Mode {
                id: rightMode
                power: rightPower.toString()
                isLeft: false
                width: parent.width/2 -10
            }
        }


        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(rootDelegate.socketName);
            }
        }
    }

}
