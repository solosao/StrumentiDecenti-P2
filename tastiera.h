#ifndef TASTIERA_H
#define TASTIERA_H

#include "strumento.h"


class Tastiera : public Strumento
{
public:
    Tastiera(QString nome, double prezzo, bool custodia = false, int tasti = 49, bool gambe = false);
    ~Tastiera();
    void setGambe(bool gambe);

protected:
    const int _tasti;
    bool _gambe;
};

#endif // TASTIERA_H
