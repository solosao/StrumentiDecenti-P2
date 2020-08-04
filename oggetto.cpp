#include "oggetto.h"

Oggetto::Oggetto(QString nome, double prezzo): _nome(nome), _prezzo(prezzo) {

}

Oggetto::~Oggetto() {

}

QString Oggetto::getNome() const{
    return _nome;
}

double Oggetto::getInitPrice() const
{
    return _prezzo;
}

