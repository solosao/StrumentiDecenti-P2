#ifndef PIANO_H
#define PIANO_H

#include "tastierapesata.h"

class Piano : public TastieraPesata
{
public:
    Piano(QString nome, double prezzo, bool custodia = false, int tasti = 88, bool gambe = false, bool pedale = true, tipoPesatura pesatura = pesata);
    ~Piano();

    QString print() const override;
    double getPrice() const override;
};

#endif // PIANO_H
