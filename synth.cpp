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
    //init
    QString ret = "Synth|";
    //parti di oggetto
    ret += getNome() +"|" + QString::number(getPrice(), 'f', 2);
    //parti di strumento
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");
    //parti di tastiera
    ret+= "|"+QString::number(getTasti());
    if(getGambe()) ret.append("|Gambe"); else ret.append("|NoGambe");
    //parti di absynth
    ret+= "|"+QString::number(getPolifonia());
    //parti di synth
    if(getAnalog()) ret.append("|Analog"); else ret.append("|Digital");

    return ret;
}

double Synth::getPrice() const
{
    return getInitPrice() + getGambe()*25 + getGambe()*50;
}
