#include "Post.h"

using namespace API::Posts::Models;

Post::Post(int id, QString title, QString text, QString image, QDateTime createdAt, QDateTime updatedAt, QObject *parent)
    : QObject(parent), id(id), title(title), text(text), image(image), createdAt(createdAt), updatedAt(updatedAt)
{
}

Post::Post(QJsonObject json, QObject *parent)
    : QObject(parent), id(json["id"].toInt()), title(json["title"].toString()), text(json["text"].toString()),
      image(json["image"].toString()), createdAt(QDateTime::fromString(json["createdAt"].toString(), Qt::ISODate)),
      updatedAt(QDateTime::fromString(json["updatedAt"].toString(), Qt::ISODate))
{
}

Post::Post(QObject *parent) : QObject(parent) {}

Post &Post::operator=(const Post &other)
{
    id = other.id;
    title = other.title;
    text = other.text;
    image = other.image;
    createdAt = other.createdAt;
    updatedAt = other.updatedAt;
    return *this;
}

int Post::getId() { return id; }
QString Post::getTitle() { return title; }
QString Post::getText() { return text; }
QString Post::getImage() { return image; }
QDateTime Post::getCreatedAt() { return createdAt; }
QDateTime Post::getUpdatedAt() { return updatedAt; }
