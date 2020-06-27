#ifndef TASTIERAPESATA_H
#define TASTIERAPESATA_H

#include "tastiera.h"


class TastieraPesata : virtual public Tastiera
{
public:
    enum tipoPesatura {
        semipasata,
        pesata,
        realwood
    };

    static const QString tipiPesatura[];

    TastieraPesata(
            QString nome,
            double prezzo,
            bool custodia = false,
            int tasti = 49,
            bool gambe = false,
            bool pedale = false,
            tipoPesatura pesatura = pesata);
    ~TastieraPesata();
    void setPedale(bool pedale);

protected:
    bool _pedale;
    const tipoPesatura _pesatura;

};

#endif // TASTIERAPESATA_H
