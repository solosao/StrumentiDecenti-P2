#include "synth.h"


Synth::Synth(QString nome,
             double prezzo,
             bool custodia,
             int tasti,
             bool gambe,
             int polifonia,
             bool analog)
             : Absynth(nome, prezzo, custodia, tasti, gambe, polifonia), _analog(analog)
{

}

Synth::~Synth()
{

}

QString Synth::print()
{
    QString ret = getNome()+QString::number(getPrice(), 'f', 2)+ QString::number(_tasti)+ QString::number(_polifonia);
    if(_case) ret.append("case");
    if(_gambe) ret.append("gambe");
    if(_analog) ret.append("analog");
    return ret;
}

double Synth::getPrice()
{
    return _prezzo + _gambe*25 + _case*50;
}
