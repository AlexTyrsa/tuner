import QtQuick 2.15
import QtQuick.Window 2.15
import QTuneLib 1.0
import "."

Window
{
    width: 235
    height: 445
    visible: true
    title: qsTr("Tuner")

    color: "lightgrey"

    Item
    {
        anchors.fill: parent
        anchors.margins: 15

        Column
        {
            anchors.fill: parent

            QC_SampleDataView
            {
                sampleProcessor: TuneData.sampleProcessor
            }

            Row
            {
                QC_NotationView
                {
                    notation: TuneData.notation
                }

                Column
                {
                    QC_OctaveView
                    {
                        octave: TuneData.notation.selectedOctave
                        inputFreq: TuneData.sampleProcessor.freq
                        nearestNote: TuneData.notation.findNearest(inputFreq)
                    }

                    Text
                    {
                        height: 40
                        width: 140
                        x: 10

                        verticalAlignment: Text.AlignVCenter

                        text: "Selected:"
                    }

                    QC_NoteView
                    {
                        note: TuneData.notation.selectedNote
                        inputFreq: TuneData.sampleProcessor.freq

                        showDiff: true
                    }
                }
            }
        }
    }
}
