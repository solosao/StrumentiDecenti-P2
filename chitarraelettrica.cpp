#include "chitarraelettrica.h"
#include <QDebug>

const QString ChitarraElettrica::tipiAmp[] = {"nessuno", "piccolo", "medio", "grande", "vintage"};
const QString ChitarraElettrica::tipiPickup[] = {"humbucker", "singlecoil", "p90"};
const QString ChitarraElettrica::tipiLegno[] = {"acero", "mogano", "frassino", "ciliegio"};
const QString ChitarraElettrica::tipiCorde[] = {"sottili", "spesse", "premium"};

ChitarraElettrica::ChitarraElettrica(QString nome,
                                     double prezzo,
                                     Chitarra::tipoLegno legno,
                                     int scala,
                                     ChitarraElettrica::tipoPickup pickup,
                                     ChitarraElettrica::tipoAmp amp,
                                     Chitarra::tipoCorde corde,
                                     bool custodia) : Chitarra(nome, prezzo, legno, scala, corde, custodia), _pickup(pickup), _amp(amp)
{

}

ChitarraElettrica::~ChitarraElettrica()
{

}

void ChitarraElettrica::setAmp(ChitarraElettrica::tipoAmp amp)
{
    _amp = amp;
}

double ChitarraElettrica::getPrice()
{
    return _prezzo+_pickup*30+_amp*200;
}

QString ChitarraElettrica::print()
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2) + tipiAmp[_amp]+tipiPickup[_pickup]+tipiCorde[_corde]+tipiLegno[_legno];
    return ret;
}
