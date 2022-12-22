add_executable(itmoptics main.cpp resources.qrc
    api/APIClient.cpp
    api/JsonAPI.cpp
    api/PostsAPI.cpp
    api/models/Post.cpp
    api/utils/JsonHelper.cpp)
target_link_libraries(itmoptics Qt5::Quick Qt5::Qml Qt5::Gui Qt5::QuickControls2 Qt5::Widgets KF5::Kirigami2 KF5::I18n)


if (ANDROID)
    target_link_libraries(itmoptics Qt5::AndroidExtras OpenSSL::Crypto OpenSSL::SSL)
    # kirigami_package_breeze_icons(ICONS applications-graphics view-list-icons folder-sync view-list-details configure document-edit dialog-information dialog-positive dialog-warning dialog-error dialog-cancel document-decrypt system-run mail-reply-sender bookmarks folder media-record-symbolic add-placemark address-book-new-symbolic view-right-new view-right-close documentinfo go-home)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/android/version.gradle.in ${CMAKE_BINARY_DIR}/version.gradle)
else()
    target_link_libraries(itmoptics Qt::Widgets)
endif()


install(TARGETS itmoptics ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})