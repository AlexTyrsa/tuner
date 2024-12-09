import QtQuick 2.15
import QTuneLib 1.0

Item
{
    id: root

    property QNote note
    property int inputFreq: 0

    QtObject
    {
        id: private_data

        readonly property string name: note ? note.name : ""
        readonly property bool selected: note ? note.selected : ""
        readonly property int freq: note? note.freq : 0
    }

    Rectangle
    {
        anchors.fill: parent

        color: "grey"

        border.color: private_data.selected ? "blue" : "darkgrey"
        border.width: 1

        Text
        {
            id: noteName

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: height

            text: private_data.name

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            color: private_data.selected ? "blue" : "black"

            font.pointSize: 16
        }

        Column
        {
            anchors.left: noteName.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            Text
            {
                height: parent.height / 2
                verticalAlignment: Text.AlignVCenter

                text: "Freq: " + private_data.freq / 1000

                font.pointSize: 12
            }

            Text
            {
                height: parent.height / 2
                verticalAlignment: Text.AlignVCenter

                text: "Diff: " + (root.inputFreq !==0 ? (private_data.freq - root.inputFreq) / 1000 : "")

                font.pointSize: 12
            }
        }
    }
}
