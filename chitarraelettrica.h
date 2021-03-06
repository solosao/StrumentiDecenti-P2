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

    static QStringList tipiAmp;
    static QStringList tipiPickup;

    static void initChitarraElettrica();

    ChitarraElettrica(QString nome,
                      double prezzo,
                      tipoLegno legno = mogano,
                      int scala = 648,
                      tipoPickup pickup = humbucker,
                      tipoAmp amp = vintage,
                      tipoCorde corde = sottili,
                      bool custodia = false);

    ~ChitarraElettrica();

    tipoAmp getAmp() const;
    tipoPickup getPickup() const;

    void setAmp(tipoAmp);
    double getPrice() const override;
    QString print() const override;

    //ENUM UTILS

    static tipoPickup pickupStringToEnum(QString);
    static tipoAmp ampStringToEnum(QString);



private:
    const tipoPickup _pickup;
    tipoAmp _amp;

};

#endif // CHITARRAELETTRICA_H
