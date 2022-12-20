#pragma once

#include "APIClient.h"

namespace API
{
    // make class JsonAPI that takes APIClient as a parameter and inherits from QObject
    // it has methods that takes callback as a parameter and returns void and pass json as a parameter to callback function

    class JsonAPI : public QObject
    {
        Q_OBJECT
    public:
        explicit JsonAPI(APIClient *api, QObject *parent = nullptr);
        void doGet(QString url, std::function<void(QJsonDocument)> callback);
        void doPost(QString url, QJsonDocument json, std::function<void(QJsonDocument)> callback);
        void doPut(QString url, QJsonDocument json, std::function<void(QJsonDocument)> callback);
        void doDel(QString url, std::function<void(QJsonDocument)> callback);
    signals:
    
    public slots:
    private:
        APIClient *api;
    };
}