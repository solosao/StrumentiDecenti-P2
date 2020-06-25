#ifndef CHITARRAACUSTICA_H
#define CHITARRAACUSTICA_H
#include "chitarra.h"


class ChitarraAcustica : public Chitarra
{
public:
    enum tipoCorpo {
        acustico,
        semiacustico,
        classico,
        banjo
    };

    static const QString tipiCorpo[];

    ChitarraAcustica(QString nome,
                     double prezzo,
                     tipoLegno legno = mogano,
                     int scala = 648,
                     tipoCorpo corpo = acustico,
                     bool amplificata = false,
                     bool eq = false,
                     bool cutaway = false,
                     tipoCorde corde = sottili,
                     bool custodia = false);
    ~ChitarraAcustica();

    virtual double getPrice();
    virtual QString print();


private:
    const tipoCorpo _corpo;
    const bool _amplificata;
    const bool _eq;
    const bool _cutaway;
};

#endif // CHITARRAACUSTICA_H
