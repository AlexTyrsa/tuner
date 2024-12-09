import QtQuick 2.15
import QTuneLib 1.0
import "."

Item
{
    id: root

    property QOctave octave
    property int inputFreq: 0

    implicitWidth: 140
    implicitHeight: octave ? octave.notes.length * 40 : 40

    Column
    {
        anchors.fill: parent

        Repeater
        {
            model: octave ? octave.notes.length : 0

            QC_NoteView
            {
                anchors.left: parent.left
                anchors.right: parent.right

                note: octave.notes[index]
                inputFreq: root.inputFreq

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        octave.requestSelectNote(note.id);
                    }
                }
            }
        }
    }
}
