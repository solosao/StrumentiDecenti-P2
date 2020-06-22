#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include "batteria.h"
#include <QDebug>

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    Componente* prova = new Componente("Piatto Sabian", 16.20, Componente::piatto);
    Componente* tamb = new Componente("timpano", 100.8, Componente::tamburo);

    Batteria vera("Nintendo", 3);
    vera.addComponente(prova);
    vera.addComponente(tamb);

    qDebug()<< vera.print();

    vera.removeComponente(1);
    qDebug()<< vera.print();
}

StrumentiDecenti::~StrumentiDecenti()
{
    delete ui;
}

