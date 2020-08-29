#include "piano.h"


Piano::Piano(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe,
        bool pedale,
        TastieraPesata::tipoPesatura pesatura)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , Tastiera(nome, prezzo, custodia, tasti, gambe)
    , TastieraPesata(nome, prezzo, custodia, tasti, gambe, pedale, pesatura)
{

}

Piano::~Piano()
{

}

QString Piano::print() const
{
    //init
    QString ret = "Piano|";
    //parti di oggetto
    ret += getNome() +"|" + QString::number(getPrice(), 'f', 2);
    //parti di strumento
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");
    //parti di tastiera
    ret+= "|"+QString::number(getTasti());
    if(getGambe()) ret.append("|Gambe"); else ret.append("|NoGambe");
    //parti di tastiera pesata
    if(getPedale()) ret.append("|Pedale"); else ret.append("|NoPedale");
    ret +="|"+tipiPesatura[getPesatura()];

    return ret;
}

double Piano::getPrice() const
{
    return getInitPrice()+getPedale()*30+getGambe()*100;
}
