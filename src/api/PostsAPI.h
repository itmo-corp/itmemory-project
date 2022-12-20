#pragma once

#include "JsonAPI.h"
#include "models/Post.h"

namespace API::Posts
{
    // PostsAPI is a class that provides methods for getting posts from the API
    // It takes an JsonAPI as a parameter
    class PostsAPI : public QObject
    {
        Q_OBJECT
    public:
        PostsAPI(JsonAPI *api, QObject *parent = nullptr);
        // get all posts
        Q_INVOKABLE void getAll();
        // get a post by id
        Q_INVOKABLE void getById(int id);
        // create a post
        Q_INVOKABLE void create(QString title, QString text);
        // update a post
        Q_INVOKABLE void update(int id, QString title, QString text);
        // delete a post
        Q_INVOKABLE void deletePost(int id);
    signals:
        // emitted when all posts are fetched
        void allPostsFetched(QList<API::Posts::Models::Post *> posts);
        // emitted when a post is fetched
        void postFetched(API::Posts::Models::Post *post);
        // emitted when a post is crea*ted
        void postCreated(Models::Post *post);
        // emitted when a post is upda*ted
        void postUpdated(Models::Post *post);
        // emitted when a post is dele*ted
        void postDeleted(Models::Post *post);
    private:
        JsonAPI *api;
        QString path = "https://api.followy.ru/itmoptics/api/v1/exhibits";
    };
}
