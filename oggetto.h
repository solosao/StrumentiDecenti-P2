#ifndef OGGETTO_H
#define OGGETTO_H
#include <QString>


class Oggetto {
public:
    Oggetto(QString nome, double prezzo);
    virtual ~Oggetto();

    // metodi poliformi
    virtual QString print() = 0;
    virtual QString getNome();
    virtual double getPrice();

protected:
    QString _nome;
    double _prezzo;

};

#endif // OGGETTO_H
