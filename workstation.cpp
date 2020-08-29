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

double Workstation::getPrice() const
{
    return getInitPrice() + 25*getGambe()+20*getPedale()+100*getCase();
//    return 0;
}

QString Workstation::print() const
{
    //init
    QString ret = "Workstation|";
    //parti di oggetto
    ret += getNome() +"|" + QString::number(getPrice(), 'f', 2);
    //parti di strumento
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");
    //parti di tastiera
    ret+= "|"+QString::number(getTasti());
    if(getGambe()) ret.append("|Gambe"); else ret.append("|NoGambe");
    //parti di absynth
    ret+= "|"+QString::number(getPolifonia());
    //parti di tastiera pesata
    if(getPedale()) ret.append("|Pedale"); else ret.append("|NoPedale");
    ret +="|"+tipiPesatura[getPesatura()];

    return ret;
}
