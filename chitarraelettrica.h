#ifndef CHITARRAELETTRICA_H
#define CHITARRAELETTRICA_H

#include "chitarra.h"

class ChitarraElettrica : public Chitarra
{
public:
    enum tipoPickup {
        humbucker,
        singlecoil,
        p90
    };

    enum tipoAmp {
        nessuno,
        piccolo,
        medio,
        grande,
        vintage
    };

    static const QString tipiAmp[];
    static const QString tipiPickup[];

    ChitarraElettrica(QString nome,
                      double prezzo,
                      tipoLegno legno = mogano,
                      int scala = 648,
                      tipoPickup pickup = humbucker,
                      tipoAmp amp = vintage,
                      tipoCorde corde = sottili,
                      bool custodia = false);

    ~ChitarraElettrica();
    void setAmp(tipoAmp);
    virtual double getPrice();
    virtual QString print();

private:
    const tipoPickup _pickup;
    tipoAmp _amp;

};

#endif // CHITARRAELETTRICA_H