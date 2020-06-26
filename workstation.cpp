#include "workstation.h"

Workstation::Workstation(QString nome,
                         double prezzo,
                         bool custodia,
                         int tasti,
                         bool gambe,
                         bool pedale,
                         TastieraPesata::tipoPesatura pesatura,
                         int polifonia)
                         : TastieraPesata(nome, prezzo, custodia, tasti, gambe, pedale, pesatura),
                           Absynth(nome, prezzo, custodia, tasti, gambe, polifonia),
                           Tastiera(nome,prezzo,custodia,tasti, gambe)
{

}

Workstation::~Workstation()
{

}

double Workstation::getPrice()
{
    return _prezzo + 25*_gambe+20*_pedale+100*_case;
}
