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
    QString ret = getNome() + QString::number(getPrice(), 'f', 2)+ QString::number(getTasti()) + tipiPesatura[getPesatura()];
    if(getPedale()) ret.append("pedale");
    if(getGambe()) ret.append("gambe");
    return ret;
}

double Piano::getPrice() const
{
    return getInitPrice()+getPedale()*30+getGambe()*100;
}
