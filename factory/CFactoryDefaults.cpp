#include "CFactoryDefaults.h"

#include "CFactory.h"

#include "../notation/CNotationI.h"
#include "../octave/COctaveI.h"

std::shared_ptr<CNotationI> CFactory::createDefault()
{
    std::shared_ptr<CNotationI> notation = createNotation();

    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_0, "0");
        notation->addOctave(octave);

        octave->addNote(createNote(C0::cNoteId, C0::cOctId, C0::cName, C0::cFreq));
        octave->addNote(createNote(D0::cNoteId, D0::cOctId, D0::cName, D0::cFreq));
        octave->addNote(createNote(E0::cNoteId, E0::cOctId, E0::cName, E0::cFreq));
        octave->addNote(createNote(F0::cNoteId, F0::cOctId, F0::cName, F0::cFreq));
        octave->addNote(createNote(G0::cNoteId, G0::cOctId, G0::cName, G0::cFreq));
        octave->addNote(createNote(A0::cNoteId, A0::cOctId, A0::cName, A0::cFreq));
        octave->addNote(createNote(B0::cNoteId, B0::cOctId, B0::cName, B0::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_1, "1");
        notation->addOctave(octave);

        octave->addNote(createNote(C1::cNoteId, C1::cOctId, C1::cName, C1::cFreq));
        octave->addNote(createNote(D1::cNoteId, D1::cOctId, D1::cName, D1::cFreq));
        octave->addNote(createNote(E1::cNoteId, E1::cOctId, E1::cName, E1::cFreq));
        octave->addNote(createNote(F1::cNoteId, F1::cOctId, F1::cName, F1::cFreq));
        octave->addNote(createNote(G1::cNoteId, G1::cOctId, G1::cName, G1::cFreq));
        octave->addNote(createNote(A1::cNoteId, A1::cOctId, A1::cName, A1::cFreq));
        octave->addNote(createNote(B1::cNoteId, B1::cOctId, B1::cName, B1::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_2, "2");
        notation->addOctave(octave);

        octave->addNote(createNote(C2::cNoteId, C2::cOctId, C2::cName, C2::cFreq));
        octave->addNote(createNote(D2::cNoteId, D2::cOctId, D2::cName, D2::cFreq));
        octave->addNote(createNote(E2::cNoteId, E2::cOctId, E2::cName, E2::cFreq));
        octave->addNote(createNote(F2::cNoteId, F2::cOctId, F2::cName, F2::cFreq));
        octave->addNote(createNote(G2::cNoteId, G2::cOctId, G2::cName, G2::cFreq));
        octave->addNote(createNote(A2::cNoteId, A2::cOctId, A2::cName, A2::cFreq));
        octave->addNote(createNote(B2::cNoteId, B2::cOctId, B2::cName, B2::cFreq));

        octave->requestSelectNote(G2::cNoteId);
        octave->setSelected(true);
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_3, "3");
        notation->addOctave(octave);

        octave->addNote(createNote(C3::cNoteId, C3::cOctId, C3::cName, C3::cFreq));
        octave->addNote(createNote(D3::cNoteId, D3::cOctId, D3::cName, D3::cFreq));
        octave->addNote(createNote(E3::cNoteId, E3::cOctId, E3::cName, E3::cFreq));
        octave->addNote(createNote(F3::cNoteId, F3::cOctId, F3::cName, F3::cFreq));
        octave->addNote(createNote(G3::cNoteId, G3::cOctId, G3::cName, G3::cFreq));
        octave->addNote(createNote(A3::cNoteId, A3::cOctId, A3::cName, A3::cFreq));
        octave->addNote(createNote(B3::cNoteId, B3::cOctId, B3::cName, B3::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_4, "4");
        notation->addOctave(octave);

        octave->addNote(createNote(C4::cNoteId, C4::cOctId, C4::cName, C4::cFreq));
        octave->addNote(createNote(D4::cNoteId, D4::cOctId, D4::cName, D4::cFreq));
        octave->addNote(createNote(E4::cNoteId, E4::cOctId, E4::cName, E4::cFreq));
        octave->addNote(createNote(F4::cNoteId, F4::cOctId, F4::cName, F4::cFreq));
        octave->addNote(createNote(G4::cNoteId, G4::cOctId, G4::cName, G4::cFreq));
        octave->addNote(createNote(A4::cNoteId, A4::cOctId, A4::cName, A4::cFreq));
        octave->addNote(createNote(B4::cNoteId, B4::cOctId, B4::cName, B4::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_5, "5");
        notation->addOctave(octave);

        octave->addNote(createNote(C5::cNoteId, C5::cOctId, C5::cName, C5::cFreq));
        octave->addNote(createNote(D5::cNoteId, D5::cOctId, D5::cName, D5::cFreq));
        octave->addNote(createNote(E5::cNoteId, E5::cOctId, E5::cName, E5::cFreq));
        octave->addNote(createNote(F5::cNoteId, F5::cOctId, F5::cName, F5::cFreq));
        octave->addNote(createNote(G5::cNoteId, G5::cOctId, G5::cName, G5::cFreq));
        octave->addNote(createNote(A5::cNoteId, A5::cOctId, A5::cName, A5::cFreq));
        octave->addNote(createNote(B5::cNoteId, B5::cOctId, B5::cName, B5::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_6, "6");
        notation->addOctave(octave);

        octave->addNote(createNote(C6::cNoteId, C6::cOctId, C6::cName, C6::cFreq));
        octave->addNote(createNote(D6::cNoteId, D6::cOctId, D6::cName, D6::cFreq));
        octave->addNote(createNote(E6::cNoteId, E6::cOctId, E6::cName, E6::cFreq));
        octave->addNote(createNote(F6::cNoteId, F6::cOctId, F6::cName, F6::cFreq));
        octave->addNote(createNote(G6::cNoteId, G6::cOctId, G6::cName, G6::cFreq));
        octave->addNote(createNote(A6::cNoteId, A6::cOctId, A6::cName, A6::cFreq));
        octave->addNote(createNote(B6::cNoteId, B6::cOctId, B6::cName, B6::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_7, "7");
        notation->addOctave(octave);

        octave->addNote(createNote(C7::cNoteId, C7::cOctId, C7::cName, C7::cFreq));
        octave->addNote(createNote(D7::cNoteId, D7::cOctId, D7::cName, D7::cFreq));
        octave->addNote(createNote(E7::cNoteId, E7::cOctId, E7::cName, E7::cFreq));
        octave->addNote(createNote(F7::cNoteId, F7::cOctId, F7::cName, F7::cFreq));
        octave->addNote(createNote(G7::cNoteId, G7::cOctId, G7::cName, G7::cFreq));
        octave->addNote(createNote(A7::cNoteId, A7::cOctId, A7::cName, A7::cFreq));
        octave->addNote(createNote(B7::cNoteId, B7::cOctId, B7::cName, B7::cFreq));
    }
    {
        std::shared_ptr<COctaveI> octave = createOctave(EOctaveId_8, "8");
        notation->addOctave(octave);

        octave->addNote(createNote(C8::cNoteId, C8::cOctId, C8::cName, C8::cFreq));
        octave->addNote(createNote(D8::cNoteId, D8::cOctId, D8::cName, D8::cFreq));
        octave->addNote(createNote(E8::cNoteId, E8::cOctId, E8::cName, E8::cFreq));
        octave->addNote(createNote(F8::cNoteId, F8::cOctId, F8::cName, F8::cFreq));
        octave->addNote(createNote(G8::cNoteId, G8::cOctId, G8::cName, G8::cFreq));
        octave->addNote(createNote(A8::cNoteId, A8::cOctId, A8::cName, A8::cFreq));
        octave->addNote(createNote(B8::cNoteId, B8::cOctId, B8::cName, B8::cFreq));
    }

    return notation;
}
