#ifndef TASTIERAPESATA_H
#define TASTIERAPESATA_H

#include "tastiera.h"
#include <QStringList>


class TastieraPesata : virtual public Tastiera
{
public:
    enum tipoPesatura {
        semipesata = 0,
        pesata = 1,
        realwood = 2
    };

    static QStringList tipiPesatura;


    static void initTastieraPesata();


    TastieraPesata(
            QString nome,
            double prezzo,
            bool custodia = false,
            int tasti = 49,
            bool gambe = false,
            bool pedale = false,
            tipoPesatura pesatura = pesata);
    ~TastieraPesata();

    bool getPedale() const;
    tipoPesatura getPesatura() const;
    void setPedale(bool pedale);

    //enum utils
    static tipoPesatura pesaturaStringToEnum(QString);

private:
    bool _pedale;
    const tipoPesatura _pesatura;

};

#endif // TASTIERAPESATA_H
