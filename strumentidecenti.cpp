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
#include "QVector"

#include "strumentowidget.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    //connessione manuale al metodo da chiamare
    connect(ui->resetPushButton, &QPushButton::pressed, this, &StrumentiDecenti::onResetPressed);

    //inizializzo view
    syncBoxed();
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
    dialog.addMode();
    dialog.resize(400,600);

    /*
     * apertura dialog con dialog.exec()
     * attendo che ritorni e controllo con enum di QDialog.
     * In questo modo la dialog è "bloccante" la mainWindow non è utilizzabile
    */

    if(dialog.exec() == QDialog::Accepted) {
        qDebug()<<"OK";
        Oggetto* ret = dialog.buildItem();
        qDebug()<<ret->print();
        list.append(ret);

        QWidget *widget = new QWidget();
        ui->scrollArea->setWidget( widget );
        ui->scrollArea->setWidgetResizable(true);

        QVBoxLayout *layout = new QVBoxLayout();
        widget->setLayout( layout );

        foreach(auto &x,list) {
            qDebug()<<x->print();
            StrumentoWidget* nuovoOggetto = new StrumentoWidget(x, this);
            layout->addWidget( nuovoOggetto );
        }

        //add spacer
        QSpacerItem* verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layout->addItem(verticalSpacer);
    }
}

void StrumentiDecenti::syncBoxed()
{
    ui->chitarraGroupBox->setVisible(ui->chitarraCheckBox->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraCheckBox->isChecked());

    ui->filtriGroupBox->setVisible(ui->chitarraCheckBox->isChecked() || ui->tastieraCheckBox->isChecked());
}

