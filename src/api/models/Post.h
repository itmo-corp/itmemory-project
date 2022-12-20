#pragma once

#include <QString>
#include <QUrl>
#include <QJsonObject>
#include <QDateTime>
#include <QtQml/qqml.h>


// json representation of a post
//
// {
//   "id": 1,
//   "title": "Lorem ipsum dolor sit amet",
//   "text": "Vivamus vitae lorem velit. Maecenas finibus consectetur viverra.",
//   "image": "https://i.redd.it/tospo6k2u9l81.png",
//   "createdAt": "2022-12-03T16:10:26.507Z",
//   "updatedAt": "2022-12-03T16:10:26.507Z"
// }

namespace API::Posts::Models
{
    class Post : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(int id READ getId)
        Q_PROPERTY(QString title READ getTitle)
        Q_PROPERTY(QString text READ getText)
        Q_PROPERTY(QString image READ getImage)
        Q_PROPERTY(QDateTime createdAt READ getCreatedAt)
        Q_PROPERTY(QDateTime updatedAt READ getUpdatedAt)
        QML_ANONYMOUS
    public:
        Post(int id, QString title, QString text, QString image, QDateTime createdAt, QDateTime updatedAt, QObject *parent = nullptr);
        Post(QJsonObject json, QObject *parent = nullptr);
        Post(const Post &other, QObject *parent = nullptr);
        Post(QObject *parent = nullptr);
        Post &operator=(const Post &other);
        int getId();
        QString getTitle();
        QString getText();
        QString getImage();
        QDateTime getCreatedAt();
        QDateTime getUpdatedAt();

    private:
        int id;
        QString title;
        QString text;
        QString image;
        QDateTime createdAt;
        QDateTime updatedAt;
    };
}
