#ifndef BATTERIA_H
#define BATTERIA_H

#include "strumento.h"
#include "componente.h"
#include <QVector>

class Batteria : public Strumento
{
public:
    Batteria(QString nome, double prezzo, bool custodia = false);
    ~Batteria();

    QString print() const override;
    double getPrice() const override;
    void addComponente(Componente*);
    void removeComponente(int);

private:
    QVector<Componente*> _componenti;
};

#endif // BATTERIA_H
