#include "batteria.h"

Batteria::Batteria(
        QString nome,
        double prezzo,
        bool custodia)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
{

}

Batteria::~Batteria()
{

    while(!_componenti.isEmpty()) {
        delete _componenti.takeFirst();
    }
}

QString Batteria::print() const
{
    QString ret = "batteria|" + getNome()+ '|' + QString::number(getPrice(), 'f', 2);
    if(getCase()) ret.append("|Case"); else ret.append("|NoCase");

    //iteratori
    for(auto iter = _componenti.begin(); iter != _componenti.end(); iter++) {
        ret.append("|"+(*iter)->print());
    }
//    for(int i = 0; i < _componenti.size(); ++i) {
//        ret.append(_componenti[i]->print());
//    }

    return ret;
}

double Batteria::getPrice() const
{
    double price = getInitPrice();
    for(auto iter = _componenti.begin(); iter != _componenti.end(); iter++) {
        price += (*iter)->getPrice();
    }
    return price;
}

QString Batteria::getLabels() const
{
    return "";
}

void Batteria::addComponente(Componente* toadd)
{
    _componenti.push_back(toadd);
}

void Batteria::removeComponente(int index)
{
    _componenti.remove(index);
}
