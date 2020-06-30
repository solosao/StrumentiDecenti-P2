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
    return dynamic_cast<Oggetto*>(this)->getPrice() + 25*getGambe()+20*getPedale()+100*getCase();
//    return 0;
}

QString Workstation::print()
{
    return QString(Q_FUNC_INFO);
}
