import QtQuick 2.6
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.2
import org.kde.kirigami 2.13 as Kirigami
import org.kde.helloworld 1.0

Kirigami.ScrollablePage {
    property string title_: "Hello World"
    property string text_: "Hello World"

    title: title_

    implicitWidth: Kirigami.Units.gridUnit * 20

    Controls.Label {
        text: text_
        wrapMode: Text.WordWrap
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    }
}