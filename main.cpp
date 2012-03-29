#include <QtGui/QApplication>
#include <qdeclarative.h>
#include "qmlapplicationviewer.h"
#include "jssupporter.h"
#include <QDeclarativeContext>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    qmlRegisterType<JSSupporter>("com.mcwk", 1, 0, "SupportClass");

    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    viewer->rootContext()->setContextProperty("fontSize", 19);
    viewer->rootContext()->setContextProperty("biggerFontSize", 24);

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/cinamon/main.qml"));
    viewer->showExpanded();

    return app->exec();
}
