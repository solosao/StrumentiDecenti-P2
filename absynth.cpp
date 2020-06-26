#include "absynth.h"

Absynth::Absynth(QString nome,
                 double prezzo,
                 bool custodia,
                 int tasti,
                 bool gambe,
                 int polifonia)
                 : Tastiera(nome, prezzo, custodia, tasti, gambe), _polifonia(polifonia)
{

}

Absynth::~Absynth()
{

}
