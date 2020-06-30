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

int Tastiera::getTasti() const
{
    return _tasti;
}

bool Tastiera::getGambe() const
{
    return _gambe;
}

void Tastiera::setGambe(bool gambe)
{
    _gambe = gambe;
}
