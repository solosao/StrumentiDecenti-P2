#ifndef PIANO_H
#define PIANO_H

#include "tastierapesata.h"

class Piano : public TastieraPesata
{
public:
    Piano(QString nome, double prezzo, bool custodia = false, int tasti = 88, bool gambe = false, bool pedale = true, tipoPesatura pesatura = pesata);
    ~Piano();

    virtual QString print();
    virtual double getPrice();
};

#endif // PIANO_H
