#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>

namespace API
{
    class APIClient : public QObject
    {
        Q_OBJECT
    public:
        explicit APIClient(QObject *parent = nullptr);
        QNetworkReply *doGet(QString url);
        QNetworkReply *doPost(QString url, QJsonDocument json);
        QNetworkReply *doPut(QString url, QJsonDocument json);
        QNetworkReply *doDel(QString url);
        QNetworkAccessManager *manager;
    signals:

    public slots:
    };
}