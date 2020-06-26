#ifndef WORKSTATION_H
#define WORKSTATION_H

#include "tastierapesata.h"
#include "absynth.h"

class Workstation : public TastieraPesata, Absynth
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
