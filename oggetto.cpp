#include "oggetto.h"

Oggetto::Oggetto(QString nome, double prezzo): _nome(nome), _prezzo(prezzo) {
    if(nome.isEmpty())
    throw(std::runtime_error("Name cannot be empty"));
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

