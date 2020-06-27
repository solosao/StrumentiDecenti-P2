#ifndef ABSYNTH_H
#define ABSYNTH_H

#include "tastiera.h"

class Absynth : virtual public Tastiera
{
public:
    Absynth(QString nome,
            double prezzo,
            bool custodia = false,
            int tasti = 49,
            bool gambe = false,
            int polifonia = 1);
    ~Absynth();

protected:
    int _polifonia;
};

#endif // ABSYNTH_H
