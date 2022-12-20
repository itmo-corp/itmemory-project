#include "JsonAPI.h"

#include "utils/JsonHelper.h"

using namespace API;

JsonAPI::JsonAPI(APIClient *api, QObject *parent) : QObject(parent), api(api)
{
}

void JsonAPI::doGet(QString url, std::function<void(QJsonDocument)> callback)
{
    QNetworkReply *reply = api->doGet(url);
    Utils::JsonHelper::parseUnfinished(reply, callback);
}

void JsonAPI::doPost(QString url, QJsonDocument json, std::function<void(QJsonDocument)> callback)
{
    QNetworkReply *reply = api->doPost(url, json);
    Utils::JsonHelper::parseUnfinished(reply, callback);
}

void JsonAPI::doPut(QString url, QJsonDocument json, std::function<void(QJsonDocument)> callback)
{
    QNetworkReply *reply = api->doPut(url, json);
    Utils::JsonHelper::parseUnfinished(reply, callback);
}

void JsonAPI::doDel(QString url, std::function<void(QJsonDocument)> callback)
{
    QNetworkReply *reply = api->doDel(url);
    Utils::JsonHelper::parseUnfinished(reply, callback);
}