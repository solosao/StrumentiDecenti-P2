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
    QString ret = getNome() + QString::number(getPrice(), 'f', 2) /*+ Chitarra::tipiCorde[getCorde()] + Chitarra::tipiLegno[getLegno()] + tipiCorpo[getCorpo()]*/;
    return ret;
}

QString ChitarraAcustica::getLabels() const
{
    return "Custodia|Legno|Scala|Corpo|Tuner|Eq|Cutaway|Corde";
}
