#include "chitarraacustica.h"

const QString tipiCorpi[] = {"acustico", "semiacustico", "classico", "banjo"};

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

double ChitarraAcustica::getPrice()
{
//    int ret = _prezzo;
    return getInitPrice() + getTuner()*50 + getEq()*20;
}

QString ChitarraAcustica::print()
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2) + Chitarra::tipiCorde[getCorde()] + Chitarra::tipiLegno[getLegno()] + tipiCorpi[getCorpo()];
    return ret;
}
