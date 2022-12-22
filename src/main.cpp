#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtQml>
#include <QUrl>
#include <klocalizedcontext.h>
#include <klocalizedstring.h>
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

#include "api/APIClient.h"
#include "api/JsonAPI.h"
#include "api/PostsAPI.h"
#include "api/models/Post.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    KLocalizedString::setApplicationDomain("itmoptics");
    QGuiApplication::setApplicationDisplayName(QStringLiteral("IT[M]Optics"));
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

    API::APIClient apiClient = API::APIClient();
    API::JsonAPI jsonAPI = API::JsonAPI(&apiClient);
    API::Posts::PostsAPI postsAPI = API::Posts::PostsAPI(&jsonAPI);

    qmlRegisterAnonymousType<API::Posts::Models::Post>("org.itmocorp.itmoptics", 1);
    qmlRegisterSingletonInstance("org.itmocorp.itmoptics", 1, 0, "PostsAPI", &postsAPI);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
