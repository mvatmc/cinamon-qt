import QtQuick 1.1
import "."

ListView {
    anchors.fill: parent
    model: model
    property bool loading : model.status == XmlListModel.Loading

    XmlListModel {
        id: model
        source: "../web/1001.xml"
        query: "/schedule/shows/show"

        XmlRole {name: "title"; query: "originalTitle/string()"}
        XmlRole {name: "iconUrl"; query: "normalize-space(images/imageType2/string())"}
        XmlRole {name: "hall"; query: "hall/string()"}
        XmlRole {name: "date"; query: "showDateTime/string()"}

        onStatusChanged: console.log("list status: " + status + ", error: " + errorString())
    }

    delegate: Item {
        width: parent.width
        height: icon.height + 30

        Image {
            id: icon
            source: iconUrl
            width: 157
            height: 160

            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                margins: 15
            }
        }

        Column {
            id: col
            anchors {
                margins: 15
                left: icon.right
                right: parent.right
                verticalCenter: parent.verticalCenter
            }
            spacing: 5

            Text {text: title; font.pixelSize: biggerFontSize}
            Text {text: hall; color: "gray"}
            Text {text: date; color: "gray"}
        }

    }
}
