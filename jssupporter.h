#ifndef JSSUPPORTER_H
#define JSSUPPORTER_H

#include <QObject>
#include <QSettings>
#include <QNetworkAccessManager>

class JSSupporter : public QObject
{
    Q_OBJECT
public:
    explicit JSSupporter(QObject *parent = 0);
    
    Q_INVOKABLE void debug(QString);
    Q_INVOKABLE void exit();
    Q_INVOKABLE void get_data(QString cinema_id);
    Q_INVOKABLE QString get_var(QString name);
    Q_INVOKABLE void set_var(QString name, QString value);
    // return: device language/territory, or empty string
    Q_INVOKABLE QString get_locale();
    Q_INVOKABLE void call_phone(QString tel_no);

signals:
    void dataRead(QString jsdata);
private slots:
    void readData(QNetworkReply *reply);

private:
    QSettings settings;
    QNetworkAccessManager qnam;
};

#endif // JSSUPPORTER_H
