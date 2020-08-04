#include "chitarraelettrica.h"
#include <QDebug>

const QString ChitarraElettrica::tipiAmp[] = {"nessuno", "piccolo", "medio", "grande", "vintage"};
const QString ChitarraElettrica::tipiPickup[] = {"humbucker", "singlecoil", "p90"};

ChitarraElettrica::ChitarraElettrica(
        QString nome,
        double prezzo,
        Chitarra::tipoLegno legno,
        int scala,
        ChitarraElettrica::tipoPickup pickup,
        ChitarraElettrica::tipoAmp amp,
        Chitarra::tipoCorde corde,
        bool custodia)
    : Oggetto(nome, prezzo)
    , Chitarra(nome, prezzo, legno, scala, corde, custodia)
    , _pickup(pickup)
    , _amp(amp)
{

}

ChitarraElettrica::~ChitarraElettrica()
{

}

ChitarraElettrica::tipoAmp ChitarraElettrica::getAmp() const
{
    return _amp;
}

ChitarraElettrica::tipoPickup ChitarraElettrica::getPickup() const
{
    return _pickup;
}

void ChitarraElettrica::setAmp(ChitarraElettrica::tipoAmp amp)
{
    _amp = amp;
}

double ChitarraElettrica::getPrice() const
{
    return getInitPrice()+getPickup()*30+getAmp()*200;
}

QString ChitarraElettrica::print() const
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2) + tipiAmp[getAmp()]+tipiPickup[getPickup()]+tipiCorde[getCorde()]+tipiLegno[getLegno()];
    return ret;
}
