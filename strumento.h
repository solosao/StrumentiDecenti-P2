#ifndef STRUMENTO_H
#define STRUMENTO_H

#include "oggetto.h"


class Strumento : virtual public Oggetto
{
public:
    Strumento(QString nome, double prezzo, bool custodia = false);
    ~Strumento();
    virtual void setCase(bool);
    bool getCase() const;

private:
    bool _case;
};

#endif // STRUMENTO_H
