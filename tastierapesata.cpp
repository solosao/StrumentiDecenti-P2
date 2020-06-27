#include "tastierapesata.h"

const QString TastieraPesata::tipiPesatura[] = {"semipesata", "pesata", "realwood"};

TastieraPesata::TastieraPesata(
        QString nome,
        double prezzo,
        bool custodia,
        int tasti,
        bool gambe,
        bool pedale,
        TastieraPesata::tipoPesatura pesatura)
    : Oggetto(nome, prezzo)
    , Strumento(nome, prezzo, custodia)
    , Tastiera(nome, prezzo, custodia, tasti, gambe)
    , _pedale(pedale)
    , _pesatura(pesatura)
{

}

TastieraPesata::~TastieraPesata()
{

}

void TastieraPesata::setPedale(bool pedale)
{
    _pedale = pedale;
}
