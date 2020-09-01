#ifndef OGGETTO_H
#define OGGETTO_H
#include <QString>
#include <typeinfo>
#include <exception>

class Oggetto {
public:
    Oggetto(QString nome, double prezzo);
    virtual ~Oggetto();

    QString getNome() const;

    // metodi polimorfi
    virtual QString print() const = 0;
    virtual double getPrice() const = 0;
    double getInitPrice() const;

private:
    QString _nome;
    double _prezzo;

};

#endif // OGGETTO_H
