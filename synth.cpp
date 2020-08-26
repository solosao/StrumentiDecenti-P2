#include "synth.h"


Synth::Synth(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe,
        int polifonia,
        bool analog)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , Tastiera(nome, prezzo, custodia, tasti, gambe)
    , Absynth(nome, prezzo, custodia, tasti, gambe, polifonia)
    , _analog(analog)
{

}

Synth::~Synth()
{

}

bool Synth::getAnalog() const
{
    return _analog;
}

QString Synth::print() const
{
    QString ret = getNome()+QString::number(getPrice(), 'f', 2)+ QString::number(getTasti())+ QString::number(getPolifonia());
    if(getCase()) ret.append("case");
    if(getGambe()) ret.append("gambe");
    if(getAnalog()) ret.append("analog");
    return ret;
}

double Synth::getPrice() const
{
    return getInitPrice() + getGambe()*25 + getGambe()*50;
}
