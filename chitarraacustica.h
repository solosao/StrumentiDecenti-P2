#ifndef CHITARRAACUSTICA_H
#define CHITARRAACUSTICA_H
#include "chitarra.h"


class ChitarraAcustica : public Chitarra
{
public:
    enum tipoCorpo {
        acustico,
        semiacustico,
        classico,
        banjo
    };

    static QStringList tipiCorpo;

    ChitarraAcustica(QString nome,
                     double prezzo,
                     tipoLegno legno = mogano,
                     int scala = 648,
                     tipoCorpo corpo = acustico,
                     bool tuner = false,
                     bool eq = false,
                     bool cutaway = false,
                     tipoCorde corde = sottili,
                     bool custodia = false);
    ~ChitarraAcustica();

    tipoCorpo getCorpo() const;
    bool getTuner() const;
    bool getEq() const;
    bool getCutaway() const;

    double getPrice() const override;
    QString print() const override;

    //ENUM TOOLS
    static tipoCorpo corpoStringToEnum(QString);

private:
    const tipoCorpo _corpo;
    const bool _tuner;
    const bool _eq;
    const bool _cutaway;
};

#endif // CHITARRAACUSTICA_H
