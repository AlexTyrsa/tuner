#pragma once

#include "../note/CNote.h"

#include <QObject>

class QNote : public QObject,
              public CNote

{
    Q_OBJECT

public:
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(int id READ id CONSTANT)
    Q_PROPERTY(int freq READ freq CONSTANT)
    Q_PROPERTY(int octId READ octave CONSTANT)
    Q_PROPERTY(bool selected READ selected NOTIFY changed)

public:
    QNote(ENoteId inId, EOctaveId inOctaveId, const std::string& inName, int inFreq);

    QString getName() const;

protected:
    void selectChanged() override;

signals:
    void changed();

};
