#include "tastierapesata.h"
#include "QStringList"


QStringList TastieraPesata::tipiPesatura = QStringList()

    << "semipesata"
    << "pesata"
    << "realwood";

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

bool TastieraPesata::getPedale() const
{
    return _pedale;
}

TastieraPesata::tipoPesatura TastieraPesata::getPesatura() const
{
    return _pesatura;
}

void TastieraPesata::setPedale(bool pedale)
{
    _pedale = pedale;
}

TastieraPesata::tipoPesatura TastieraPesata::pesaturaStringToEnum(QString input)
{
    tipoPesatura pesatura;
    if(input == "pesata") {
        pesatura = tipoPesatura::pesata;
    } else if(input == "semipesata") {
        pesatura = tipoPesatura::semipesata;
    } else if(input == "realwood") {
        pesatura = tipoPesatura::realwood;
    }
    return pesatura;
}
