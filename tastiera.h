#ifndef TASTIERA_H
#define TASTIERA_H

#include "strumento.h"


class Tastiera : virtual public Strumento
{
public:
    Tastiera(
            QString nome,
            double prezzo,
            bool custodia = false,
            int tasti = 49,
            bool gambe = false);
    ~Tastiera();

    int getTasti() const;
    bool getGambe() const;

    void setGambe(bool gambe);


private:
    const int _tasti;
    bool _gambe;
};

#endif // TASTIERA_H
