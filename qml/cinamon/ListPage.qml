// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    property alias loading : list.loading

    List {
        id: list
        anchors.fill: parent

        header: Item {height: head.height; Component.onCompleted: list.headerItem = item; id: item }

        property Item headerItem
    }

    Rectangle {
        width: parent.width
        height: head.height + 25
        y: head.y
        gradient: Gradient {
            GradientStop {position: 0; color: "black"}
            GradientStop {position: 0.8; color: "black"}
            GradientStop {position: 1; color: "transparent"}
        }
    }

    Column {
        id: head
        width: parent.width
     //   y: -Math.max(list.contentY + , input.height)
           y: Math.max(-list.contentY + list.headerItem.y, -img.height)
           spacing: 10

        Image {
            id: img
            source: "../web/images/logo.png"
            width: parent.width
            smooth: true
        }

        TextField {
            id: input
            anchors {
                left: parent.left
                right: parent.right
                margins: 15
            }
            placeholderText: "Search Text Here"

        }
    }

}
