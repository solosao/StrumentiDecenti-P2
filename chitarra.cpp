#include "chitarra.h"

QStringList Chitarra::tipiLegno = QStringList()
        << "acero"
        << "mogano"
        << "frassino"
        << "ciliegio";
QStringList Chitarra::tipiCorde = QStringList()
        << "sottili"
        << "spesse"
        << "premium";


Chitarra::Chitarra(
        QString nome,
        double prezzo,
        Chitarra::tipoLegno legno,
        int scala,
        Chitarra::tipoCorde corde,
        bool custodia)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , _legno(legno)
    , _scala(scala)
    , _corde(corde)

{
}

Chitarra::~Chitarra()
{

}

Chitarra::tipoLegno Chitarra::getLegno() const
{
    return _legno;
}

int Chitarra::getScala() const
{
    return _scala;
}

Chitarra::tipoCorde Chitarra::getCorde() const
{
    return  _corde;
}

void Chitarra::setCorde(Chitarra::tipoCorde corde)
{
    _corde = corde;
}

Chitarra::tipoLegno Chitarra::legnoStringToEnum(QString input)
{
    Chitarra::tipoLegno legno;

    if(input == "acero") {
        legno = Chitarra::tipoLegno::acero;
    } else if(input == "mogano") {
        legno = Chitarra::tipoLegno::mogano;
    } else if(input == "frassino") {
        legno = Chitarra::tipoLegno::frassino;
    } else if(input == "ciliegio") {
        legno = Chitarra::tipoLegno::ciliegio;
    }

    return legno;
}

Chitarra::tipoCorde Chitarra::cordeStringToEnum(QString input)
{
    Chitarra::tipoCorde corde;

    if(input == "sottili") {
        corde = Chitarra::tipoCorde::sottili;
    } else if(input == "spesse") {
        corde = Chitarra::tipoCorde::spesse;
    } else if(input == "premium") {
        corde = Chitarra::tipoCorde::premium;
    }

    return corde;
}
