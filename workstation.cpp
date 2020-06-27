#include "workstation.h"

Workstation::Workstation(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe,
        bool pedale,
        TastieraPesata::tipoPesatura pesatura,
        int polifonia)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , Tastiera(nome, prezzo, custodia, tasti, gambe)
    , TastieraPesata(nome, prezzo, custodia, tasti, gambe, pedale, pesatura)
    , Absynth(nome, prezzo, custodia, tasti, gambe, polifonia)
{

}

Workstation::~Workstation()
{

}

double Workstation::getPrice()
{
    return _prezzo + 25*_gambe+20*_pedale+100*_case;
//    return 0;
}

QString Workstation::print()
{
    return QString(Q_FUNC_INFO);
}
