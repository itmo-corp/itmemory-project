#include "APIClient.h"

namespace API
{
    APIClient::APIClient(QObject *parent) : QObject(parent)
    {
        manager = new QNetworkAccessManager(parent);
    }

    QNetworkReply *APIClient::doGet(QString url)
    {
        return manager->get(QNetworkRequest(QUrl(url)));
    }

    QNetworkReply *APIClient::doPost(QString url, QJsonDocument json)
    {
        QNetworkRequest request{QUrl(url)};
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = QJsonDocument(json).toJson();
        return manager->post(request, data);
    }

    QNetworkReply *APIClient::doPut(QString url, QJsonDocument json)
    {
        QNetworkRequest request{QUrl(url)};
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = QJsonDocument(json).toJson();
        return manager->put(request, data);
    }

    QNetworkReply *APIClient::doDel(QString url)
    {
        return manager->deleteResource(QNetworkRequest(QUrl(url)));
    }
}
