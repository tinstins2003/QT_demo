import QtQuick
import QtQuick.Controls
Item {
    id: _item
    width: 640
    height: 480
    Button {
        id: addButton
        x: 408
        y: 322
        width: 144
        height: 43
        text: "ADD"
        focus: false
        font.family: "Arial"
        icon.color: "#000000"
        highlighted: false
        transformOrigin: Item.Center
        onClicked: toDoList.addClicked()

        background:Rectangle {
            color: "#b30aa228"
            anchors.fill:parent
            z:-1
        }
    }

    TextInput {
        id: toDoInput
        x: 408
        y: 130
        width: 144
        height: 162
        text: qsTr("Text Input")
        anchors.right: parent.right
        anchors.rightMargin: 88
        font.pixelSize: 12
        anchors.verticalCenterOffset: -29
        anchors.horizontalCenterOffset: 160

        onFocusChanged:{
            if(focus){
                toDoInput.clear();
            }
        }

        Rectangle {
            id: toDoInputBackground
            color: "#5028cd40"
            anchors.fill: toDoInput
            z:-1
            MouseArea {
                id: mouseArea
                anchors.fill:toDoInputBackground
                cursorShape: Qt.IBeamCursor
                z:-1

            }
        }


    }

    ListView {
        id: listView
        x: 95
        y: 130
        width: 259
        height: 235
        visible: true
        layoutDirection: Qt.LeftToRight

        Rectangle{
            anchors.fill:parent
            color:"#71b23939"
            z:-1
        }

        model: ToDoListPage {
            list:toDoList
        }
        delegate: Item {
            id: todoItem
            width: parent.width
            height: 40
            Row{
                width: parent.width
                height: 20

                Button {
                    id:buttonList
                    width:parent.width*0.9
                    height: parent.height
                    anchors.centerIn: parent

                    Text {
                        width: buttonList.width
                        text: content

                    }
                    background:Rectangle{
                        color:colorCode
                        width:parent.width
                        height: 20
                        z:-1
                    }

                }

            }
        }
    }

}
