#include "tastiera.h"


Tastiera::Tastiera(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , _tasti(tasti)
    , _gambe(gambe)
{

}

Tastiera::~Tastiera()
{

}

void Tastiera::setGambe(bool gambe)
{
    _gambe = gambe;
}
