import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Extras 1.4

import DarkSide 1.0

import "SocketModelQML"
// import "SocketModelVisual"

Window {
    id: godObject
    width: 1280
    height: 800
    visible: true
    title: qsTr("Hello World")

    ListView
    {
        id: socListView
        anchors
        {
            fill: parent
            margins: 10
        }
        model: TheMightySocketModel {}
        // property int socketState
        // property int leftPower
        // property alias leftName: leftMode.modeName
        // property int rightPower
        // property alias rightName: rightMode.modeName
        // property alias socketName: socketNameText.text
        delegate: SocketDelegate {
            socketState: model.socketStatus
            socketName: model.socketName
            leftPower: model.socketLeftModePower
            leftName: model.socketLeftModeName
            rightPower: model.socketRightModePower
            rightName: model.socketRightModeName
        }
    }

}
