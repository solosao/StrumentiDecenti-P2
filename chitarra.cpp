#include "chitarra.h"
const QString Chitarra::tipiLegno[] = {"acero", "mogano", "frassino", "ciliegio"};
const QString Chitarra::tipiCorde[] = {"sottili", "spesse", "premium"};


Chitarra::Chitarra(QString nome,
                   double prezzo,
                   Chitarra::tipoLegno legno,
                   int scala,
                   Chitarra::tipoCorde corde,
                   bool custodia) : Strumento(nome, prezzo, custodia), _legno(legno), _scala(scala), _corde(corde)

{
}

Chitarra::~Chitarra()
{

}

void Chitarra::setCorde(Chitarra::tipoCorde corde)
{
    _corde = corde;
}
