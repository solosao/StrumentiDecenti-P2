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

    QString tipo;

    switch(_tipo) {
        case piatto: tipo = "PIATTO"; break;
        case tamburo: tipo = "TAMBURO"; break;
    }

    return getNome()+"|" + QString::number(getPrice(), 'f', 2)+"|" + tipo;
}

double Componente::getPrice() const
{
    return getInitPrice();
}
