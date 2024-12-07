#pragma once

#include "../CNoteDefs.h"
#include <string>

template<ENoteId cNoteIdT, EOctaveId cOctIdT, int cFreqT>
struct note_traits
{
    static const ENoteId cNoteId = cNoteIdT;
    static const EOctaveId cOctId = cOctIdT;
    constexpr static const char cName[3] = {'A' + cNoteIdT, '0' + cOctIdT, 0};
    static const int cFreq = cFreqT;
};

typedef note_traits<ENoteId_C, EOctaveId_0, 16352> C0;
typedef note_traits<ENoteId_D, EOctaveId_0, 18354> D0;
typedef note_traits<ENoteId_E, EOctaveId_0, 20602> E0;
typedef note_traits<ENoteId_F, EOctaveId_0, 21827> F0;
typedef note_traits<ENoteId_G, EOctaveId_0, 24500> G0;
typedef note_traits<ENoteId_A, EOctaveId_0, 27500> A0;
typedef note_traits<ENoteId_B, EOctaveId_0, 30868> B0;

typedef note_traits<ENoteId_C, EOctaveId_1, 32703> C1;
typedef note_traits<ENoteId_D, EOctaveId_1, 36708> D1;
typedef note_traits<ENoteId_E, EOctaveId_1, 41203> E1;
typedef note_traits<ENoteId_F, EOctaveId_1, 43654> F1;
typedef note_traits<ENoteId_G, EOctaveId_1, 48999> G1;
typedef note_traits<ENoteId_A, EOctaveId_1, 55000> A1;
typedef note_traits<ENoteId_B, EOctaveId_1, 61735> B1;

typedef note_traits<ENoteId_C, EOctaveId_2,  65406> C2;
typedef note_traits<ENoteId_D, EOctaveId_2,  73416> D2;
typedef note_traits<ENoteId_E, EOctaveId_2,  82406> E2;
typedef note_traits<ENoteId_F, EOctaveId_2,  87307> F2;
typedef note_traits<ENoteId_G, EOctaveId_2,  97999> G2;
typedef note_traits<ENoteId_A, EOctaveId_2, 110000> A2;
typedef note_traits<ENoteId_B, EOctaveId_2, 123470> B2;

typedef note_traits<ENoteId_C, EOctaveId_3, 130810> C3;
typedef note_traits<ENoteId_D, EOctaveId_3, 146830> D3;
typedef note_traits<ENoteId_E, EOctaveId_3, 164810> E3;
typedef note_traits<ENoteId_F, EOctaveId_3, 174610> F3;
typedef note_traits<ENoteId_G, EOctaveId_3, 196000> G3;
typedef note_traits<ENoteId_A, EOctaveId_3, 220000> A3;
typedef note_traits<ENoteId_B, EOctaveId_3, 246940> B3;

typedef note_traits<ENoteId_C, EOctaveId_4, 261630> C4;
typedef note_traits<ENoteId_D, EOctaveId_4, 293670> D4;
typedef note_traits<ENoteId_E, EOctaveId_4, 329630> E4;
typedef note_traits<ENoteId_F, EOctaveId_4, 349230> F4;
typedef note_traits<ENoteId_G, EOctaveId_4, 392000> G4;
typedef note_traits<ENoteId_A, EOctaveId_4, 440000> A4;
typedef note_traits<ENoteId_B, EOctaveId_4, 493880> B4;

typedef note_traits<ENoteId_C, EOctaveId_5, 523250> C5;
typedef note_traits<ENoteId_D, EOctaveId_5, 587330> D5;
typedef note_traits<ENoteId_E, EOctaveId_5, 659260> E5;
typedef note_traits<ENoteId_F, EOctaveId_5, 698460> F5;
typedef note_traits<ENoteId_G, EOctaveId_5, 783990> G5;
typedef note_traits<ENoteId_A, EOctaveId_5, 880000> A5;
typedef note_traits<ENoteId_B, EOctaveId_5, 987770> B5;

typedef note_traits<ENoteId_C, EOctaveId_6, 1046500> C6;
typedef note_traits<ENoteId_D, EOctaveId_6, 1174700> D6;
typedef note_traits<ENoteId_E, EOctaveId_6, 1318500> E6;
typedef note_traits<ENoteId_F, EOctaveId_6, 1396900> F6;
typedef note_traits<ENoteId_G, EOctaveId_6, 1568000> G6;
typedef note_traits<ENoteId_A, EOctaveId_6, 1760000> A6;
typedef note_traits<ENoteId_B, EOctaveId_6, 1975500> B6;

typedef note_traits<ENoteId_C, EOctaveId_7, 2093000> C7;
typedef note_traits<ENoteId_D, EOctaveId_7, 2349300> D7;
typedef note_traits<ENoteId_E, EOctaveId_7, 2637000> E7;
typedef note_traits<ENoteId_F, EOctaveId_7, 2793800> F7;
typedef note_traits<ENoteId_G, EOctaveId_7, 3136000> G7;
typedef note_traits<ENoteId_A, EOctaveId_7, 3520000> A7;
typedef note_traits<ENoteId_B, EOctaveId_7, 3951100> B7;

typedef note_traits<ENoteId_C, EOctaveId_8, 4186000> C8;
typedef note_traits<ENoteId_D, EOctaveId_8, 4698600> D8;
typedef note_traits<ENoteId_E, EOctaveId_8, 5274000> E8;
typedef note_traits<ENoteId_F, EOctaveId_8, 5587700> F8;
typedef note_traits<ENoteId_G, EOctaveId_8, 6271900> G8;
typedef note_traits<ENoteId_A, EOctaveId_8, 7040000> A8;
typedef note_traits<ENoteId_B, EOctaveId_8, 7902100> B8;
