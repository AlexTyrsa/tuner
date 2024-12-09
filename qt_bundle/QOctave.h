#pragma once

#include "../octave/COctave.h"
#include "QNote.h"

#include <QObject>
#include <QQmlListProperty>

class QOctave : public QObject,
                public COctave
{
    Q_OBJECT

public:
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(int id READ id CONSTANT)
    Q_PROPERTY(bool selected READ selected NOTIFY changed)
    Q_PROPERTY(QNote* selectedNote READ selNote NOTIFY changed)
    Q_PROPERTY(QQmlListProperty<QNote> notes READ getItemsQML CONSTANT)

public:
    QOctave(EOctaveId inId, const std::string& inName);

    QString getName() const;
    QNote* selNote() const;

    QQmlListProperty<QNote> getItemsQML();

protected:
    virtual void stateChanged();

signals:
    void changed();

private:
    static qsizetype itemsCount(QQmlListProperty<QNote>* inProperty);
    static QNote* itemAt(QQmlListProperty<QNote>* inProperty, qsizetype inIndex);

};
