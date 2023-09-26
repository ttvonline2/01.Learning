import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Calculator"

    Grid {
        rows: 5
        columns: 4
        anchors.fill: parent
        spacing: 10

        Label {
            id: displayLabel
            text: "0"
            row: 0
            column: 0
            columnSpan: 4
            horizontalAlignment: Text.AlignRight
            padding: 10
            font.pointSize: 24
        }

        Button {
            text: "7"
            onClicked: handleButtonClick("7")
            row: 1
            column: 0
        }

        Button {
            text: "8"
            onClicked: handleButtonClick("8")
            row: 1
            column: 1
        }

        Button {
            text: "9"
            onClicked: handleButtonClick("9")
            row: 1
            column: 2
        }

        Button {
            text: "+"
            onClicked: handleButtonClick("+")
            row: 1
            column: 3
        }

        // Rest of the buttons...

        Button {
            text: "="
            onClicked: handleButtonClick("=")
            row: 4
            column: 2
            columnSpan: 2
        }
    }

    function handleButtonClick(buttonText) {
        // Calculate logic based on the button clicked
        // Update the displayLabel text accordingly
    }
}