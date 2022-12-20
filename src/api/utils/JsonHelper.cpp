#include "JsonHelper.h"

using namespace API::Utils;

void JsonHelper::parse(QNetworkReply *reply, std::function<void(QJsonDocument)> callback)
{
    QString data = (QString)reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
    callback(json);
}

// get json from unfinished reply using connect and parse function
void JsonHelper::parseUnfinished(QNetworkReply *reply, std::function<void(QJsonDocument)> callback)
{
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() {
        JsonHelper::parse(reply, callback);
    });
}
