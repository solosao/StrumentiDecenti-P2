#ifndef CHITARRA_H
#define CHITARRA_H

#include "strumento.h"
#include <QStringList>


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

private:
    const tipoLegno _legno;
    const int _scala;
    tipoCorde _corde;


};

#endif // CHITARRA_H
