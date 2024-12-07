#include "CFactoryJSON.h"

#include "CFactoryDefaults.h"

#include "../note/CNoteI.h"
#include "../notation/CNotationI.h"
#include "../octave/COctaveI.h"

#include <nlohmann/json.hpp>
#include <cassert>

static const char* tag_version  = "version";
static const char* tag_notation = "notation";
static const char* tag_octaves  = "octaves";
static const char* tag_notes    = "notes";
static const char* tag_id       = "id";
static const char* tag_name     = "name";
static const char* tag_selected = "selected";
static const char* tag_freq     = "freq";

CFactoryJSON::CFactoryJSON(const std::string &inVersion) : CFactory(inVersion)
{

}

std::string CFactoryJSON::serialize(std::shared_ptr<CNotationI> inNotation)
{
    assert(inNotation);

    nlohmann::json root;

    if(inNotation)
    {
        root[tag_version] = version();

        nlohmann::json octave_list_js;

        for(int octave_idx = 0; octave_idx < inNotation->size(); ++octave_idx)
        {
            std::shared_ptr<COctaveI> octave = inNotation->octave_index(octave_idx);

            assert(octave);

            if(octave)
            {
                nlohmann::json note_list_js;

                for(int note_idx = 0; note_idx < octave->size(); ++note_idx)
                {
                    std::shared_ptr<CNoteI> note = octave->note_index(note_idx);

                    assert(note);

                    if(note)
                    {
                        nlohmann::json note_js;

                        note_js[tag_id] = note->id();
                        note_js[tag_name] = note->name();
                        note_js[tag_freq] = note->freq();

                        if(note->selected())
                            note_js[tag_selected] = true;

                        note_list_js.push_back(note_js);
                    }
                }

                nlohmann::json octave_js;

                octave_js[tag_id] = octave->id();
                octave_js[tag_name] = octave->name();
                if(octave->selected())
                    octave_js[tag_selected] = true;

                octave_js[tag_notes] = note_list_js;

                octave_list_js.push_back(octave_js);
            }
        }
        nlohmann::json notation_js;

        notation_js[tag_octaves] = octave_list_js;
        root[tag_notation] = notation_js;
    }

    return root.dump(4, ' ');
}

std::shared_ptr<CNotationI> CFactoryJSON::deserialize(const std::string &inData)
{
    std::shared_ptr<CNotationI> notation = createNotation();

    nlohmann::json root = nlohmann::json::parse(inData);

    nlohmann::json notation_js = root.value(tag_notation, nlohmann::json());

    nlohmann::json octave_list_js = notation_js.value(tag_octaves, nlohmann::json());

    for(nlohmann::json::iterator octaves_iter = octave_list_js.begin(); octaves_iter != octave_list_js.end(); ++octaves_iter)
    {
        nlohmann::json octave_js = *octaves_iter;

        int octaveId = octave_js.value(tag_id, 0);
        std::string octaveName = octave_js.value(tag_name, "noname");

        std::shared_ptr<COctaveI> octave = createOctave(static_cast<EOctaveId>(octaveId), octaveName);

        nlohmann::json note_list_js = octave_js.value(tag_notes, nlohmann::json());

        for(nlohmann::json::iterator notes_iter = note_list_js.begin(); notes_iter != note_list_js.end(); ++notes_iter)
        {
            nlohmann::json note_js = *notes_iter;

            int noteId = note_js.value(tag_id, 0);
            std::string noteName = note_js.value(tag_name, "noname");
            int noteFreq = note_js.value(tag_freq, 0);

            std::shared_ptr<CNoteI> note = createNote(static_cast<ENoteId>(noteId), static_cast<EOctaveId>(octaveId), noteName, noteFreq);

            if(note_js.value(tag_selected, false))
                note->setSelected(true);

            octave->addNote(note);
        }

        if(octave_js.value(tag_selected, false))
            octave->setSelected(false);

        notation->addOctave(octave);
    }

    return notation;
}
