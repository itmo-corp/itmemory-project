#pragma once

#include <QNetworkReply>
#include <QJsonDocument>
#include <functional>

namespace API::Utils
{
    class JsonHelper
    {
    public:
        static void parse(QNetworkReply *reply, std::function<void(QJsonDocument)> callback);
        static void parseUnfinished(QNetworkReply *reply, std::function<void(QJsonDocument)> callback);
    };
}
