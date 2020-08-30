#include "chitarraelettrica.h"
#include <QDebug>

QStringList ChitarraElettrica::tipiAmp = QStringList()
        << "nessuno"
        << "piccolo"
        << "medio"
        << "grande"
        << "vintage";

QStringList ChitarraElettrica::tipiPickup = QStringList()
        << "humbucker"
        << "singlecoil"
        << "p90";


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
    //init
    QString ret = "ChitarraElettrica|";
    //parti di oggetto
    ret += getNome() +"|" + QString::number(getPrice(), 'f', 2);
    //parti di strumento
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");
    //parti di chitarra
    ret += "|"+ QString::number(getScala()) +"|"+ Chitarra::tipiCorde[getCorde()] +"|"+ Chitarra::tipiLegno[getLegno()];
    //parti di chitarra elettrica
    ret += "|" + tipiAmp[getAmp()]+"|"+tipiPickup[getPickup()];
    return ret;
}

ChitarraElettrica::tipoPickup ChitarraElettrica::pickupStringToEnum(QString input)
{
    tipoPickup pickup;
    if(input == "humbucker") {
        pickup = tipoPickup::humbucker;
    } else if(input == "singlecoil") {
        pickup = tipoPickup::singlecoil;
    } else if(input == "p90") {
        pickup = tipoPickup::p90;
    }
    return pickup;

}

ChitarraElettrica::tipoAmp ChitarraElettrica::ampStringToEnum(QString input)
{
    tipoAmp amp;
    if(input == "nessuno") {
        amp = tipoAmp::nessuno;
    } else if(input == "piccolo") {
        amp = tipoAmp::piccolo;
    } else if(input == "medio") {
        amp = tipoAmp::medio;
    } else if(input == "grande") {
        amp = tipoAmp::grande;
    } else if(input == "vintage") {
        amp = tipoAmp::vintage;
    }
}
