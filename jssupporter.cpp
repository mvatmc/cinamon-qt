#include "jssupporter.h"
#include <QDebug>
#include <QSettings>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>
#include <QDesktopServices>
#include <qplatformdefs.h>

#if defined(MEEGO_EDITION_HARMATTAN) || defined(Q_OS_SYMBIAN)

#define USE_SYSTEMINFO
#include <QSystemInfo>
QTM_USE_NAMESPACE

#endif

JSSupporter::JSSupporter(QObject *parent) :
    QObject(parent),
    settings("Cinamon", "Cinamon")
{
    connect(&qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(readData(QNetworkReply*)));
}

void JSSupporter::debug(QString msg)
{
    qDebug() << "JSSupporter::debug: " << msg;
}

void JSSupporter::exit()
{
    qDebug() << "JSSupporter::exit()";
    QApplication::exit();
}

void JSSupporter::get_data(QString cinema_id)
{
    qDebug() << "get_data (" << cinema_id << ")";
    QUrl url("http://cat.mooncascade.com/projects/cinamon/php/schedule.php");

    QNetworkRequest req(url);
    qnam.get(req);
}

void JSSupporter::readData(QNetworkReply * reply)
{
    QByteArray result = reply->readAll();
    qDebug() << "JSSupporter::readData " << reply->url().toString() <<
                "error: " << reply->error() << " (" << reply->errorString() << "): "
             << result.length() << "bytes";
    reply->deleteLater();
    emit dataRead(QString(result));
}

QString JSSupporter::get_var(QString name)
{
    QString value(settings.value(name).toString());
    qDebug() << "JSSupporter::get_var( " << name << "): " << value;
    return value;
}

void JSSupporter::set_var(QString name, QString value)
{
    qDebug() << "JSSupporter::set_var( " << name << ", " << value << ")";
    settings.setValue(name, value);
    settings.sync();
}

QString JSSupporter::get_locale()
{
#ifdef USE_SYSTEMINFO
    QSystemInfo i;
    QString c = i.currentCountryCode();
#else
    QString c = "et";
#endif

    qDebug() << "JSSupporter::get_locale() " << c;

    return c;
}

void JSSupporter::call_phone(QString tel_no)
{
    qDebug() << "JSSupporter::call_phone(" << tel_no << ")";
    QDesktopServices::openUrl("tel:"+tel_no);
}


