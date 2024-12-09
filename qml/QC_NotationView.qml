import QtQuick 2.15
import QTuneLib 1.0
import "."

Item
{
    id: root

    property QNotation notation

    implicitWidth: 40
    implicitHeight: notation ? notation.octaves.length * 40 : 40

    Column
    {
        anchors.fill: parent

        Repeater
        {
            model: notation ? notation.octaves.length : 0

            QC_OctaveViewSmall
            {
                anchors.left: parent.left
                anchors.right: parent.right

                octave: notation.octaves[index]

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        notation.requestSelectOctave(octave.id);
                    }
                }
            }
        }
    }
}
