#include "chitarraacustica.h"

const QString tipiCorpi[] = {"acustico", "semiacustico", "classico", "banjo"};

ChitarraAcustica::ChitarraAcustica(
        QString nome,
        double prezzo,
        tipoLegno legno,
        int scala,
        tipoCorpo corpo,
        bool amplificata,
        bool eq,
        bool cutaway,
        tipoCorde corde,
        bool custodia)
    : Oggetto(nome, prezzo)
    , Chitarra(nome, prezzo, legno, scala, corde, custodia)
    , _corpo(corpo)
    , _amplificata(amplificata)
    , _eq(eq)
    , _cutaway(cutaway)
{

}

ChitarraAcustica::~ChitarraAcustica()
{

}

double ChitarraAcustica::getPrice()
{
//    int ret = _prezzo;
    return _prezzo + _amplificata*50 + _eq*20;
}

QString ChitarraAcustica::print()
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2) + Chitarra::tipiCorde[_corde] + Chitarra::tipiLegno[_legno] + tipiCorpi[_corpo];
    return ret;
}
