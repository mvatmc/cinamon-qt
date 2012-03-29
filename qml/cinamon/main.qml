import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: window
    anchors.fill: parent
    initialPage: page_portrait

    Page {
        id: page_portrait
        orientationLock: PageOrientation.LockPortrait
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: "black"
        }

        //WebContent {            anchors.fill: parent  ; id: webView      }
        ListPage {       id: webView;            anchors.fill: parent        }

        Rectangle {
            color: "black"
            anchors.fill: parent
            opacity: 0.1
            visible: webView.loading

            BusyIndicator {
                anchors.centerIn: parent
                running: webView.loading
            }
        }

    } // page
}
