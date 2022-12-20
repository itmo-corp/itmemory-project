#include "PostsAPI.h"

// implement PostsAPI class

using namespace API::Posts;

PostsAPI::PostsAPI(JsonAPI *api, QObject *parent)
    : QObject(parent), api(api)
{
}

void PostsAPI::getAll()
{
    api->doGet(path, [=](QJsonDocument json) {
        QList<Models::Post *> posts;
        for (auto post : json.array()) {
            posts.append(new Models::Post(post.toObject()));
        }
        emit allPostsFetched(posts);
    });
}

void PostsAPI::getById(int id)
{
    api->doGet(path + "/" + QString::number(id), [=](QJsonDocument json) {
        emit postFetched(new Models::Post(json.object())); // TODO: fix memory leak
    });
}

void PostsAPI::create(QString title, QString text)
{
    throw "Not implemented";
    // QJsonObject json;
    // json["title"] = title;
    // json["text"] = text;
    // api->doPost(path, QJsonDocument(json), [=](QJsonDocument json) {
    //     emit postCreated(&Models::Post(json["post"].toObject()));
    // });
}

void PostsAPI::update(int id, QString title, QString text)
{
    throw "Not implemented";
    // QJsonObject json;
    // json["title"] = title;
    // json["text"] = text;
    // api->doPut(path + "/" + QString::number(id), QJsonDocument(json), [=](QJsonDocument json) {
    //     emit postUpdated(&Models::Post(json["post"].toObject()));
    // });
}

void PostsAPI::deletePost(int id)
{
    throw "Not implemented";
    // api->doDel(path + "/" + QString::number(id), [=](QJsonDocument json) {
    //     emit postDeleted(&Models::Post(json["post"].toObject()));
    // });
}
