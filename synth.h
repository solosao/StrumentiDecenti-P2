#ifndef SYNTH_H
#define SYNTH_H

#include "absynth.h"

class Synth : public Absynth
{
public:
    Synth(QString nome, double prezzo, bool custodia = false, int tasti = 37, bool gambe = false, int polifonia = 1, bool analog = true);
    ~Synth();

    virtual QString print();
    virtual double getPrice();

private:
    const bool _analog;
};

#endif // SYNTH_H
