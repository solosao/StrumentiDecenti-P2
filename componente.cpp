#include "componente.h"

Componente::Componente(
        QString nome,
        double prezzo,
        Componente::tipoScelta tipo)
    : Oggetto(nome, prezzo)
    , _tipo(tipo){

}

Componente::~Componente()
{

}

QString Componente::print() const
{ //metodo polimorfo

    QString ret;

    switch(_tipo) {
        case piatto: ret = "Piatto|"; break;
        case tamburo: ret = "Tamburo|"; break;
    }

    return ret + getNome()+"|" + QString::number(getPrice(), 'f', 2);
}

double Componente::getPrice() const
{
    return getInitPrice();
}
