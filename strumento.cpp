#include "strumento.h"


Strumento::Strumento(
        QString nome,
        double prezzo,
        bool custodia)
    : Oggetto(nome, prezzo)
    , _case(custodia)
{

}

Strumento::~Strumento()
{

}

void Strumento::setCase(bool custodia)
{
    _case = custodia;
}

bool Strumento::getCase() const
{
    return _case;
}
