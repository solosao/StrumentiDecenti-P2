#ifndef CHITARRA_H
#define CHITARRA_H

#include "strumento.h"
#include <QStringList>


class Chitarra : public Strumento
{
public:
    enum tipoLegno {
        acero = 0,
        mogano = 1,
        frassino = 2,
        ciliegio = 3
    };

    enum tipoCorde {
        sottili = 0,
        spesse = 1,
        premium = 2
    };

    static QStringList tipiCorde;
    static QStringList tipiLegno;

    Chitarra(QString nome,
             double prezzo,
             tipoLegno legno,
             int scala,
             tipoCorde corde = sottili,
             bool custodia = false);

    ~Chitarra();

    tipoLegno getLegno() const;
    int getScala() const;
    tipoCorde getCorde() const;

    virtual void setCorde(tipoCorde);

    static tipoLegno legnoStringToEnum(QString);
    static tipoCorde cordeStringToEnum(QString);

private:
    const tipoLegno _legno;
    const int _scala;
    tipoCorde _corde;


};

#endif // CHITARRA_H
