import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
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
        onClicked: {
            toDoListPage.addClicked(toDoInput.text)
            toDoInput.text = "Text Input";
        }

        background:Rectangle {
            color: "#b30aa228"
            anchors.fill:parent
            z:-1
        }
    }
 ScrollView {
    id: scrollView
    x: 408
    y: 130
    width: 144
    height: 162
    ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

    TextArea {
        id: toDoInput
        color: "#000000"
        anchors.fill:scrollView
        text: qsTr("Text Input")
        font.pixelSize: 12
        wrapMode: Text.Wrap
        selectedTextColor: "#000000"
        onFocusChanged:{
            if(focus){
                toDoInput.clear();
            }
        }

        background:Rectangle {
            id: toDoInputBackground
            color: "#5028cd40"
            anchors.fill: toDoInput

            MouseArea {
                id: mouseArea
                anchors.fill:toDoInputBackground
                cursorShape: Qt.IBeamCursor
                z:-1

            }
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
        clip: true

        Rectangle{
            anchors.fill:parent
            color:"#71b23939"
            z:-1
        }

        model: stringListModel

        delegate: RowLayout {
           id: todoItem
           width: parent.width
           height: 100
           ToDoItem{
               Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
               Layout.preferredWidth: todoItem.width
               Layout.preferredHeight: todoItem.height-10
               contentText:display
               indexx:index

           }
       }

    }

}
