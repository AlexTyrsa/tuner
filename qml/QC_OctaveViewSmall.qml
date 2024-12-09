import QtQuick 2.15
import QTuneLib 1.0

Item
{
    id: root

    property QOctave octave

    implicitHeight: 40
    implicitWidth: 40

    QtObject
    {
        id: private_data

        readonly property string name: octave ? octave.name : ""
        readonly property bool selected: octave ? octave.selected : false
    }

    Rectangle
    {
        anchors.fill: parent

        color: "grey"

        border.color: private_data.selected ? "blue" : "darkgrey"
        border.width: 1

        Text
        {
            anchors.fill: parent

            text: octave ? octave.name : ""

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            color: private_data.selected ? "blue" : "black"

            font.pointSize: 16
        }
    }
}
