#ifndef CHITARRA_H
#define CHITARRA_H

#include "strumento.h"

class Chitarra : public Strumento
{
public:
    enum tipoLegno {
        acero,
        mogano,
        frassino,
        ciliegio
    };

    enum tipoCorde {
        sottili,
        spesse,
        premium
    };

    static const QString tipiCorde[];
    static const QString tipiLegno[];

    Chitarra(QString nome,
             double prezzo,
             tipoLegno legno,
             int scala,
             tipoCorde corde = sottili,
             bool custodia = false);

    ~Chitarra();
    virtual void setCorde(tipoCorde);

protected:
    const tipoLegno _legno;
    const int _scala;
    tipoCorde _corde;


};

#endif // CHITARRA_H
