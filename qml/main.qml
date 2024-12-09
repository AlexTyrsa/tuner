import QtQuick 2.15
import QtQuick.Window 2.15
import QTuneLib 1.0
import "."

Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    QC_NoteView
    {
        note: TuneData.notation.selectedNote
        inputFreq: 90000

        x: 10
        y: 10


        width: 140
        height: 40

    }
}
