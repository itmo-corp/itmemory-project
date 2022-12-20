// Includes relevant modules used by the QML
import QtQuick 2.6
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.2
import org.kde.kirigami 2.13 as Kirigami
import org.kde.helloworld 1.0

Kirigami.ApplicationWindow {
    id: root

    title: i18nc("@title:window", "Exhibits")

    pageStack.initialPage: Kirigami.ScrollablePage {
        title: i18nc("@title", "MainPage")

        objectName: "mainPage"

        implicitWidth: Kirigami.Units.gridUnit * 40

        Component.onCompleted: {
            PostsAPI.getAll();
            console.log("hello world");
        }

        // subscribe to the postsApi's postsLoaded signal
        Connections {
            target: PostsAPI
            function onAllPostsFetched(posts)
            {
                console.log("posts fetched");
                for (var i = 0; i < posts.length; ++i) {
                    console.log(posts[i].title);
                    exhibitListModel.append(posts[i])
                }
            }
        }

        // card list view of exhibit previews (exhibit title)
        Kirigami.CardsListView {
            id: exhibitList

            anchors.fill: parent

            width: parent.width

            model: ListModel {
                id: exhibitListModel
            }

            delegate: exhibitPreviewDelegate
        }


        // implement exhibit preview delegate
        Component {
            id: exhibitPreviewDelegate

            Kirigami.Card {
                id: card

                banner {
                    title: model.title
                    source: model.image
                }

                contentItem: Controls.Label {
                    wrapMode: Text.WordWrap
                    text: "created: " + model.createdAt + " updated: " + model.updatedAt
                }

                // on click, push the exhibit page to the page stack
                onClicked: {
                    // root.pageStack.push("qrc:/ExhibitPage.qml", { "title_": model.title, "text_": model.text })
                    overlaySheet.title = model.title
                    overlaySheet.text = model.text
                    overlaySheet.open()
                }
            }
        }

        // overlay sheet
        Kirigami.OverlaySheet {
            id: overlaySheet

            property string text: ""
            property string title: ""

            header: Kirigami.Heading {
                text: overlaySheet.title
            }

            Controls.Label {
                wrapMode: Text.WordWrap
                text: overlaySheet.text
            }
        }
    }
}

