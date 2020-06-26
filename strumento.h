#ifndef STRUMENTO_H
#define STRUMENTO_H

#include "oggetto.h"


class Strumento : public Oggetto
{
public:
    Strumento(QString nome, double prezzo, bool custodia = false);
    ~Strumento();
    virtual void setCase(bool);

protected:
    bool _case;
};

#endif // STRUMENTO_H
