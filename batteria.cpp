#include "batteria.h"

Batteria::Batteria(QString nome, double prezzo, bool custodia) : Strumento(nome, prezzo, custodia)
{

}

Batteria::~Batteria()
{

}

QString Batteria::print()
{
    QString ret = getNome() + QString::number(getPrice(), 'f', 2);

    //iteratori
    for(auto iter = _componenti.begin(); iter != _componenti.end(); iter++) {
        ret.append((*iter)->print());
    }
//    for(int i = 0; i < _componenti.size(); ++i) {
//        ret.append(_componenti[i]->print());
//    }

    return ret;
}

double Batteria::getPrice()
{
    double price = _prezzo;
    for(int i = 0; i < _componenti.size(); ++i) {
        price += _componenti[i]->getPrice();
    }
    return price;
}

void Batteria::addComponente(Componente* toadd)
{
    _componenti.push_back(toadd);
}

void Batteria::removeComponente(int index)
{
    _componenti.remove(index);
}
