#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include <QDebug>

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    Componente prova("Piatto Sabian", 16.20, Componente::piatto);
    qDebug()<< prova.print();
}

StrumentiDecenti::~StrumentiDecenti()
{
    delete ui;
}

