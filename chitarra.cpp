#include "chitarra.h"
#include <QStringList>

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
