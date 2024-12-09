import QtQuick 2.15
import QTuneLib 1.0

Item
{
    id: root

    property QSampleProcessor sampleProcessor

    implicitHeight: 40
    implicitWidth: 140

    Rectangle
    {
        id: meter

        anchors.leftMargin: 5
        anchors.rightMargin: 5

        height: 10

        width: Math.min(sampleProcessor ? parent.width * sampleProcessor.level * 10 : 0, parent.width)

        color: "blue"
    }

    Text
    {
        id: noteName

        anchors.top: meter.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        text: sampleProcessor ? (sampleProcessor.freq / 1000 + "Hz") : ""

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        font.pointSize: 12
    }
}
