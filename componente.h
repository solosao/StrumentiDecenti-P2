#ifndef COMPONENTE_H
#define COMPONENTE_H
#include "oggetto.h"

class Componente : public Oggetto
{
public:
    enum tipoScelta {
        piatto,
        tamburo
    };

    Componente(QString, double, tipoScelta);
    ~Componente();

    QString print() const override;
    double getPrice() const override;
    QString getLabels() const override;


private:
    const tipoScelta _tipo;
};

#endif // COMPONENTE_H
