#include "chitarraacustica.h"
#include <QStringList>

QStringList ChitarraAcustica::tipiCorpo = QStringList()
        << "acustico"
        << "semiacustico"
        << "classico"
        << "banjo";

ChitarraAcustica::ChitarraAcustica(
        QString nome,
        double prezzo,
        tipoLegno legno,
        int scala,
        tipoCorpo corpo,
        bool tuner,
        bool eq,
        bool cutaway,
        tipoCorde corde,
        bool custodia)
    : Oggetto(nome, prezzo)
    , Chitarra(nome, prezzo, legno, scala, corde, custodia)
    , _corpo(corpo)
    , _tuner(tuner)
    , _eq(eq)
    , _cutaway(cutaway)
{

}

ChitarraAcustica::~ChitarraAcustica()
{

}

ChitarraAcustica::tipoCorpo ChitarraAcustica::getCorpo() const
{
    return _corpo;
}

bool ChitarraAcustica::getTuner() const
{
    return _tuner;
}

bool ChitarraAcustica::getEq() const
{
    return _eq;
}

bool ChitarraAcustica::getCutaway() const
{
    return _cutaway;
}

double ChitarraAcustica::getPrice() const
{
//    int ret = _prezzo;
    return getInitPrice() + getTuner()*50 + getEq()*20;
}

QString ChitarraAcustica::print() const
{
    // init
    QString ret = "ChitarraAcustica|";
    // parti di oggetto
    ret += getNome() +"|" + QString::number(getPrice(), 'f', 2);
    //parti di strumento
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");
    //parti di chitarra
    ret += "|"+ QString::number(getScala()) +"|"+ Chitarra::tipiCorde[getCorde()] +"|"+ Chitarra::tipiLegno[getLegno()];
    //parti di chitarra acustica
    ret += "|" + tipiCorpo[getCorpo()];
    if(getTuner()) ret.append("|Tuner"); else ret.append("|NoTuner");
    if(getEq()) ret.append("|Eq"); else ret.append("|NoEq");
    if(getCutaway()) ret.append("|Cutaway"); else ret.append("|NoCutaway");

    return ret;
}
