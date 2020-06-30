#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include "batteria.h"
#include "chitarraelettrica.h"
#include <QDebug>
#include <QPair>
#include "chitarraacustica.h"
#include "piano.h"
#include "adddialog.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    //connessione manuale al metodo da chiamare
    connect(ui->resetPushButton, &QPushButton::pressed, this, &StrumentiDecenti::onResetPressed);

    //inizializzo view
    syncBoxed();


    /*
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

    */

    //price : 1130

    //ci sarà un QList di oggetti
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

void StrumentiDecenti::on_priceSlider_valueChanged(int value)
{
    qDebug()<<Q_FUNC_INFO<<value; //macro per debuggare metodo chiamato
    if(ui->priceSpinBox->value() != value) {
        ui->priceSpinBox->setValue(value);
    }
}

void StrumentiDecenti::on_priceSpinBox_valueChanged(int value)
{
    if(ui->priceSlider->value() != value) {
        ui->priceSlider->setValue(value);
    }
    qDebug()<<Q_FUNC_INFO;
}

void StrumentiDecenti::on_batteriaCheckBox_toggled(bool)
{

}

void StrumentiDecenti::on_chitarraCheckBox_toggled(bool toggled)
{
    Q_UNUSED(toggled)
    syncBoxed();
}

void StrumentiDecenti::on_tastieraCheckBox_toggled(bool toggled)
{
    Q_UNUSED(toggled)
    syncBoxed();
}

void StrumentiDecenti::on_addPushButton_pressed()
{
    AddDialog dialog(this); //this perchè è figlia della main window

    /*
     * apertura dialog con dialog.exec()
     * attendo che ritorni e controllo con enum di QDialog.
     * In questo modo la dialog è "bloccante" la mainWindow non è utilizzabile
    */

    if(dialog.exec() == QDialog::Accepted) {
        qDebug()<<"OK";
        Oggetto* ret = dialog.buildItem();

        list.append(ret);

        foreach(auto &x,list)
            qDebug()<<x->print();

//        ui->strumentoTableView.
    }
}

void StrumentiDecenti::syncBoxed()
{
    ui->chitarraGroupBox->setVisible(ui->chitarraCheckBox->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraCheckBox->isChecked());

    ui->filtriGroupBox->setVisible(ui->chitarraCheckBox->isChecked() || ui->tastieraCheckBox->isChecked());
}

