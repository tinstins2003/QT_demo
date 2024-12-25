import QtQuick
import QtQuick.Controls 2.15


Rectangle {
        id: container
        width: 320
        height: 100
        color: "#ffffff"
        radius: 20
        property alias contentText: content.text
        property int indexx
        property bool isEditing:false
        ScrollView{
            id:scrollView
            width: container.width*0.7
            height: container.height
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff


            TextInput {
                 visible:isEditing
                 id: content1
                 width: scrollView.width
                 height: scrollView.height
                 text: content.text
                 font.pixelSize: 12
                 wrapMode: Text.Wrap

                 MouseArea {
                     id: mouseArea
                     anchors.fill:parent
                     cursorShape: Qt.IBeamCursor
                     z:-1
                 }


             }

            Text {
                 visible:!isEditing
                 id: content
                 width: scrollView.width
                 height: scrollView.height
                 text: qsTr("Text")
                 font.pixelSize: 12
                 lineHeightMode: Text.ProportionalHeight
                 wrapMode: Text.Wrap
                 fontSizeMode: Text.FixedSize


             }
            background:Rectangle{
                anchors.fill:parent
                color:"#dbeda7"
                z: -1
            }
        }
         Button {
             id: deleteBtn
             x: container.width*0.7
             width: container.width*0.3
             height: container.height/2
             text: "Delete"
             z:0

             onClicked:toDoListPage.deleteClicked(index)

             background:Rectangle{
                 anchors.fill:deleteBtn
                 color:"#92ff0000"
                 z: -1

             }
         }

         Button {
             id: editBtn
             x: container.width*0.7
             y:container.height/2
             width: container.width*0.3
             height: container.height/2
             text: "Edit"
             z:0

             onClicked:{

                 if(!isEditing){
                     editBtn.text = "Save";
                 }else{
                     content.text=content1.text;
                     editBtn.text = "Edit";
                     toDoListPage.editClicked(indexx,content.text);
                 }
                 isEditing = !isEditing;

             }

             background:Rectangle{
                 anchors.fill:deleteBtn
                 color:"#1cff00"
                 z: -1

             }
         }


    }



