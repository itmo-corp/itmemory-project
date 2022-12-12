#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtQml>
#include <QUrl>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <QQuickItem>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QGuiApplication>

// WindowManager.LayoutParams
#define FLAG_TRANSLUCENT_STATUS 0x04000000
#define FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS 0x80000000
// View
#define SYSTEM_UI_FLAG_LIGHT_STATUS_BAR 0x00002000

#else
#include <QApplication>
#endif


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    KLocalizedString::setApplicationDomain("helloworld");
    QGuiApplication::setApplicationDisplayName(QStringLiteral("Hello World"));
    // QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    // QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));


    //The desktop QQC2 style needs it to be a QApplication
#ifdef Q_OS_ANDROID
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle(QStringLiteral("Material"));
#else
    // Default to org.kde.desktop style unless the user forces another style
    if (qEnvironmentVariableIsEmpty("QT_QUICK_CONTROLS_STYLE")) {
        QQuickStyle::setStyle(QStringLiteral("org.kde.desktop"));
    }
    QApplication app(argc, argv);
#endif


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextObject(new KLocalizedContext(&engine));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QString qmlStr = "import QtQuick 2.6; import QtQuick.Controls 2.0 as Controls; Controls.Label { anchors.centerIn: parent; text: i18n(\"Hello World!\"); }";
    
    QQmlComponent component(&engine);
    component.setData(qmlStr.toUtf8(), QUrl());
    QQuickItem *object = qobject_cast<QQuickItem *>(component.create(engine.rootContext()));
    if (object == nullptr) {
        qWarning() << component.errorString();
    }

    auto root = engine.rootObjects().last();
    auto mainPage = qobject_cast<QQuickItem *>(root->findChild<QObject*>("mainPage"));

    object->setParentItem(mainPage);

    return app.exec();
}
