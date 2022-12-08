// Includes relevant modules used by the QML
import QtQuick 2.6
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.2
import org.kde.kirigami 2.13 as Kirigami

// Base element, provides basic features needed for all kirigami applications
Kirigami.ApplicationWindow {
    // ID provides unique identifier to reference this element
    id: root

    // Window title
    // i18nc is useful for adding context for translators, also lets strings be changed for different languages
    title: i18nc("@title:window", "Hello World")

    // Initial page to be loaded on app load
    pageStack.initialPage: Kirigami.ScrollablePage {
        title: i18nc("@title", "MainPage")

        Controls.Label {
            // Center label horizontally and vertically within parent element
            anchors.centerIn: parent
            text: i18n("Hello World!")
        }

        Kirigami.CardsListView {
            id: layout
            model: kountdownModel
            delegate: kountdownDelegate
        }

        ListModel {
            id: kountdownModel
            // Each ListElement is an element on the list, containing information
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 100 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 139293200 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 1055435340 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 10044422532546 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 10032546 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 1002546 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 9329329 }
            ListElement { name: " birthday!!"; description: "Big doggo birthday blowout."; date: 10022532546 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo birthday blowout."; date: 10022532546 }
            ListElement { name: "Dog!!"; description: "Big doggo birthday blowout."; date: 10022532546 }
            ListElement { name: "Dog birthday!!"; description: "doggo birthday blowout."; date: 10022532546 }
            ListElement { name: "Dog birthday!!"; description: "Big birthday blowout."; date: 10022532546 }
            ListElement { name: "Dog birthday!!"; description: "Big doggo blowout."; date: 10022532546 }
        }

        actions.main: Kirigami.Action {
            id: addAction
            icon.name: "list-add"
            text: i18nc("@action:button", "Add kountdown")
            onTriggered: kountdownModel.append({
                name: "Kirigami Action added card!",
                description: "Congratulations, your Kirigami Action works!",
                date: 1000
            })
        }

        Component {
            id: kountdownDelegate
            Kirigami.AbstractCard {
                contentItem: Item {
                    // implicitWidth/Height define the natural width/height of an item if no width or height is specified.
                    // The setting below defines a component's preferred size based on its content
                    implicitWidth: delegateLayout.implicitWidth
                    implicitHeight: delegateLayout.implicitHeight
                    GridLayout {
                        id: delegateLayout
                        anchors {
                            left: parent.left
                            top: parent.top
                            right: parent.right
                        }
                        rowSpacing: Kirigami.Units.largeSpacing
                        columnSpacing: Kirigami.Units.largeSpacing
                        columns: root.wideScreen ? 4 : 2

                        Kirigami.Heading {
                            Layout.fillHeight: true
                            level: 1
                            text: (date < 100000) ? date : i18n("%1 days", Math.round((date-Date.now())/86400000))
                        }

                        ColumnLayout {
                            Kirigami.Heading {
                                Layout.fillWidth: true
                                level: 2
                                text: name
                            }
                            Kirigami.Separator {
                                Layout.fillWidth: true
                                visible: description.length > 0
                            }
                            Controls.Label {
                                Layout.fillWidth: true
                                wrapMode: Text.WordWrap
                                text: description
                                visible: description.length > 0
                            }
                        }
                        Controls.Button {
                            Layout.alignment: Qt.AlignRight
                            Layout.columnSpan: 2
                            text: i18n("Edit")
                            // onClicked: to be done... soon!
                        }
                    }
                }
            }
        }
    }
}
