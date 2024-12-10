import QtQuick 2.15
import QTuneLib 1.0
import "."

Item
{
    id: root

    property QOctave octave
    property QNote nearestNote
    property int inputFreq: 0

    implicitWidth: 160
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
                showDiff: note.selected || (nearestNote === note)

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
