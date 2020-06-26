#include "piano.h"


Piano::Piano(QString nome,
             double prezzo,
             bool custodia,
             int tasti,
             bool gambe,
             bool pedale,
             TastieraPesata::tipoPesatura pesatura)
             : TastieraPesata(nome, prezzo, custodia, tasti, gambe, pedale, pesatura)
{

}

Piano::~Piano()
{

}

QString Piano::print()
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2)+ QString::number(_tasti) + tipiPesatura[_pesatura];
    if(_pedale) ret.append("pedale");
    if(_gambe) ret.append("gambe");
    return ret;
}

double Piano::getPrice()
{
    return _prezzo+_pedale*30+_gambe*100;
}
