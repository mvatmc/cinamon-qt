// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtWebKit 1.0
import com.mcwk 1.0


Flickable {
    id: flx
    contentHeight: webView.height
    contentWidth: webView.width

    WebView {
        id: webView
        url: "../web/index.html"
        //url: "http://192.168.1.118/mooncascade_projects/cinamon/trunk/web/index.html"

        //html: "<script>window.mcwk.get_locale();</script>"

        onUrlChanged: flx.contentY = 0


        /*
        preferredWidth: window.width
        preferredHeight: window.height
        */
        preferredWidth: 480
        preferredHeight: 854

       // scale: 2.0

        property string location_update_function: ""
        property bool single_update: false

        property bool loading : false
        onLoadFinished: loading = false
        onLoadFailed: {
            loading = false
            console.log("error")
        }
        onLoadStarted: loading = true

        javaScriptWindowObjects: SupportClass {
            WebView.windowObjectName: "mcwk"

            onDataRead: webView.evaluateJavaScript("on_data_received("+jsdata+")")
        } // javaScriptWindowObjects

    } // WebView

}
