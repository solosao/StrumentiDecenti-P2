#include "absynth.h"

Absynth::Absynth(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe,
        int polifonia)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , Tastiera(nome, prezzo, custodia, tasti, gambe)
    , _polifonia(polifonia)
{

}

Absynth::~Absynth()
{

}

int Absynth::getPolifonia() const
{
    return _polifonia;
}
