#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include "batteria.h"
#include "chitarraelettrica.h"
#include <QDebug>
#include "chitarraacustica.h"
#include "piano.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    //connessione manuale al metodo da chiamare
    connect(ui->resetPushButton, &QPushButton::pressed, this, &StrumentiDecenti::onResetPressed);

    Componente* prova = new Componente("Piatto Sabian", 16.20, Componente::piatto);
    Componente* tamb = new Componente("timpano", 100.8, Componente::tamburo);

    Batteria vera("Nintendo", 3);
    vera.addComponente(prova);
    vera.addComponente(tamb);

    qDebug()<< vera.print();

    vera.removeComponente(1);
    qDebug()<< vera.print();

    ChitarraElettrica* bellissima = new ChitarraElettrica("straziocaster", 666);
    qDebug()<< bellissima->print();

    ChitarraAcustica* caustic = new ChitarraAcustica("pippocaster", 333);
    qDebug()<< caustic->print();

    Piano* kosendorker = new Piano("emporial", 1000, false, 88, true);
    qDebug()<< kosendorker->print();
    //price : 1130
}

StrumentiDecenti::~StrumentiDecenti()
{
    delete ui;
}

//connessione automatica
void StrumentiDecenti::on_searchPushButton_pressed()
{
    qDebug()<<Q_FUNC_INFO;
}

//connessione manuale ->
void StrumentiDecenti::onResetPressed()
{
    qDebug()<<Q_FUNC_INFO;
}

