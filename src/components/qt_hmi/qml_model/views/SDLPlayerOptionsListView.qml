import QtQuick 2.0
import "../controls"

Item {
    anchors.fill: parent

    Item {
        // 3/4 top screen
        height: parent.height * 3/4
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        ListView {
            id: sdlPlayerOptionsListView
            anchors.horizontalCenter: parent.horizontalCenter
            width:parent.width
            height:parent.height

            model: ListModel{
                ListElement{
                    name: "Policies Test"
                }
                ListElement{
                    name: "XML Test"
                }
            }


            delegate: Text  {
                text: name
                color: "#1d81d5"
                font.pixelSize: 40
                MouseArea {
                  anchors.fill: parent
                  onClicked: {
                    }
                }
            }
        }
    }

    Item{
        // 1/4 bottom screen
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width
        height: 1/4 * parent.height

        BackButton { anchors.horizontalCenter: parent.horizontalCenter }
    }
}
