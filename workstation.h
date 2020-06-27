#ifndef WORKSTATION_H
#define WORKSTATION_H

#include "tastierapesata.h"
#include "absynth.h"
#include "tastiera.h"

class Workstation : virtual public TastieraPesata, virtual public Absynth
{
public:
    Workstation(QString nome,
                double prezzo,
                bool custodia = false,
                int tasti = 73,
                bool gambe = false,
                bool pedale = false,
                tipoPesatura pesatura = semipasata,
                int polifonia = 16);
    ~Workstation();
    virtual double getPrice();
    virtual QString print();
};

#endif // WORKSTATION_H
