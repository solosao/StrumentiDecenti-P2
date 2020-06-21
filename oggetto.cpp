#include "oggetto.h"

Oggetto::Oggetto(QString nome, double prezzo): _nome(nome), _prezzo(prezzo) {

}

Oggetto::~Oggetto() {

}

QString Oggetto::getNome() {
    return _nome;
}

double Oggetto::getPrice() {
    return _prezzo;
}
