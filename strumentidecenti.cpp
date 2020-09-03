#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include "batteria.h"
#include "chitarraelettrica.h"
#include <QPair>
#include <QString>
#include "chitarraacustica.h"
#include "piano.h"
#include "workstation.h"
#include "synth.h"
#include "adddialog.h"
#include "QVector"

#include "strumentowidget.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    // init connect
    connect(ui->batteriaCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncBoxed);
    connect(ui->chitarraCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncBoxed);
    connect(ui->tastieraCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncBoxed);
    connect(ui->elettricaCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncBoxed);
    connect(ui->acusticaCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncBoxed);

    connect(ui->synthCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncTastieraFilter);
    connect(ui->workstationCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncTastieraFilter);
    connect(ui->pianoCheckBox, &QCheckBox::toggled, this, &StrumentiDecenti::syncTastieraFilter);

    //init view
    syncBoxed();

    //init ScrollArea
    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    ui->scrollArea->setWidgetResizable(true);

    layoutScroll = new QVBoxLayout();
    widget->setLayout( layoutScroll );

    verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    //init ComboBox
    ui->legnoComboBox->addItems(Chitarra::tipiLegno);
    ui->cordeComboBox->addItems(Chitarra::tipiCorde);
    ui->ampComboBox->addItems(ChitarraElettrica::tipiAmp);
    ui->pickupComboBox->addItems(ChitarraElettrica::tipiPickup);
    ui->corpoComboBox->addItems(ChitarraAcustica::tipiCorpo);
    ui->pesaturaComboBox->addItems(TastieraPesata::tipiPesatura);

}

StrumentiDecenti::~StrumentiDecenti()
{
    delete layoutScroll;
    delete verticalSpacer;
    delete ui;
}

//connessione automatica
void StrumentiDecenti::on_searchPushButton_pressed()
{

    QList<StrumentoWidget*> search = list.keys();

    if(search.count() > 0) {
        foreach(auto &x,search) {
            //Nome
            QString nome = list[x]->getNome();

            if(nome.contains(ui->searchLineEdit->text(), Qt::CaseInsensitive)) {
                x->show();
            } else {
                x->hide();
            }

            //Prezzo

            double price = list[x]->getPrice();
            if(ui->priceSpinBox->value() > 0) {
                if(price == ui->priceSpinBox->value()) {
                    x->show();
                } else {
                    x->hide();
                }
            }


            //Tipo
            if(ui->chitarraCheckBox->isChecked()) {
                if(dynamic_cast<Chitarra*>(list[x])) x->show();
                else x->hide();

                searchChitarra(x);
            }
            if(ui->batteriaCheckBox->isChecked()) {
                if(dynamic_cast<Batteria*>(list[x])) x->show();
                else x->hide();
            }
            if(ui->tastieraCheckBox->isChecked()) {
                if(dynamic_cast<Tastiera*>(list[x])) x->show();
                else x->hide();

                searchTastiera(x);

            }

            //Custodia
            if(ui->custodiaCheckBox->isChecked()) {
                if(!list[x]->print().contains("NoCase")) x->show();
                else x->hide();
            }

        }
    }
}

void StrumentiDecenti::on_resetPushButton_pressed()
{
    ui->searchLineEdit->clear();
    ui->priceSpinBox->setValue(0);
    ui->scalaSpinBox->setValue(0);
    ui->tastiSpinBox->setValue(0);
    ui->polifoniaSpinBox->setValue(0);

    QList<QComboBox*> combobox;
    combobox<<ui->cordeComboBox
            <<ui->ampComboBox
            <<ui->corpoComboBox
            <<ui->legnoComboBox
            <<ui->pickupComboBox
            <<ui->pesaturaComboBox;

    foreach(auto &x, combobox) {
        x->setCurrentIndex(0);
    }

    QList<QCheckBox*> checkbox;
    checkbox<<ui->batteriaCheckBox
            <<ui->chitarraCheckBox
            <<ui->tastieraCheckBox
            <<ui->custodiaCheckBox
            <<ui->acusticaCheckBox
            <<ui->elettricaCheckBox
            <<ui->eqCheckBox
            <<ui->gambeCheckBox
            <<ui->pianoCheckBox
            <<ui->synthCheckBox
            <<ui->tunerCheckBox
            <<ui->analogCheckBox
            <<ui->pedaleCheckBox
            <<ui->cutawayCheckBox
            <<ui->workstationCheckBox;

    foreach(auto &x, checkbox) {
        x->setChecked(false);
    }


}

void StrumentiDecenti::on_priceSlider_valueChanged(int value)
{
    if(ui->priceSpinBox->value() != value) {
        ui->priceSpinBox->setValue(value);
    }
}

void StrumentiDecenti::on_priceSpinBox_valueChanged(int value)
{
    if(ui->priceSlider->value() != value) {
        ui->priceSlider->setValue(value);
    }
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
        if(!dialog.isValid().isEmpty()) {
            dialog.errorDialog(dialog.isValid());
        } else {
            Oggetto* ret = dialog.buildItem();

            layoutScroll->removeItem(verticalSpacer);

            StrumentoWidget* nuovoOggetto = new StrumentoWidget(ret, this);
            nuovoOggetto->initStrumentoWidget(ret);
            connect(nuovoOggetto, &StrumentoWidget::deleteRequest, this, &StrumentiDecenti::deleteStrumento);
            layoutScroll->addWidget( nuovoOggetto );

            list.insert(nuovoOggetto, ret);

            layoutScroll->addItem(verticalSpacer);
        }
    }
}

void StrumentiDecenti::syncBoxed()
{
    ui->chitarraGroupBox->setVisible(ui->chitarraCheckBox->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraCheckBox->isChecked());
    ui->filtriGroupBox->setVisible(ui->chitarraCheckBox->isChecked() ||
                                   ui->tastieraCheckBox->isChecked() ||
                                   ui->batteriaCheckBox->isChecked());

    ui->acusticaGroupBox->setVisible(ui->acusticaCheckBox->isChecked());
    ui->elettricaGroupBox->setVisible(ui->elettricaCheckBox->isChecked());

    syncTastieraFilter();
}

void StrumentiDecenti::syncTastieraFilter()
{
    ui->polifoniaLabel->setVisible(ui->synthCheckBox->isChecked() ||
                                   ui->workstationCheckBox->isChecked());
    ui->polifoniaSpinBox->setVisible(ui->synthCheckBox->isChecked() ||
                                     ui->workstationCheckBox->isChecked());
    ui->analogLabel->setVisible(ui->synthCheckBox->isChecked());
    ui->analogCheckBox->setVisible(ui->synthCheckBox->isChecked());
    ui->pesaturaLabel->setVisible(ui->workstationCheckBox->isChecked() ||
                                  ui->pianoCheckBox->isChecked());
    ui->pesaturaComboBox->setVisible(ui->workstationCheckBox->isChecked() ||
                                     ui->pianoCheckBox->isChecked());
    ui->pedaleLabel->setVisible(ui->workstationCheckBox->isChecked() ||
                                ui->pianoCheckBox->isChecked());
    ui->pedaleCheckBox->setVisible(ui->workstationCheckBox->isChecked() ||
                                   ui->pianoCheckBox->isChecked());
}

void StrumentiDecenti::deleteStrumento()
{
    if(StrumentoWidget* temp = dynamic_cast<StrumentoWidget*>(sender())) {
        if(list.contains(temp)) {
            delete list[temp];
            list.remove(temp);
            temp->deleteLater();
        }
    }

}

void StrumentiDecenti::searchChitarra(StrumentoWidget* const search)
{
    if(dynamic_cast<Chitarra*>(list[search])) {
        QStringList print = list[search]->print().split('|');
        if(ui->scalaSpinBox->value() > 0 && ui->scalaSpinBox->value() == print[4].toFloat())
            search->show();
        else
            search->hide();
        if(ui->cordeComboBox->currentText() == print[5])
            search->show();
        else
            search->hide();
        if(ui->legnoComboBox->currentText() == print[6])
            search->show();
        else
            search->hide();

        if(dynamic_cast<ChitarraAcustica*>(list[search])) {
            if(ui->corpoComboBox->currentText() == print[7])
                search->show();
            else
                search->hide();
            if(ui->tunerCheckBox->isChecked()) {
                if(print[8] != ("NoTuner")) search->show();
                else search->hide();
            } else {
                if(print[8] == ("NoTuner")) search->show();
                else search->hide();
            }

            if(ui->eqCheckBox->isChecked()) {
                if(print[8] != ("NoEq")) search->show();
                else search->hide();
            } else {
                if(print[8] == ("NoEq")) search->show();
                else search->hide();
            }

            if(ui->cutawayCheckBox->isChecked()) {
                if(print[8] != ("NoCutaway")) search->show();
                else search->hide();
            } else {
                if(print[8] == ("NoCutaway")) search->show();
                else search->hide();
            }
        }else if(dynamic_cast<ChitarraElettrica*>(list[search])) {
            if(ui->ampComboBox->currentText() == print[7])
                search->show();
            else
                search->hide();

            if(ui->pickupComboBox->currentText() == print[7])
                search->show();
            else
                search->hide();
        }
    }


}

void StrumentiDecenti::searchTastiera(StrumentoWidget * const search)
{
    QStringList print = list[search]->print().split('|');
    if(dynamic_cast<Tastiera*>(list[search])) {
        if(ui->tastiSpinBox->value() > 0 && ui->tastiSpinBox->value() == print[4].toInt())
            search->show();
        else
            search->hide();
        if(ui->gambeCheckBox->isChecked()) {
            if(print[8] != ("NoGambe")) search->show();
            else search->hide();
        } else {
            if(print[8] == ("NoGambe")) search->show();
            else search->hide();
        }

        if(dynamic_cast<Piano*>(list[search])) {
            if(ui->pedaleCheckBox->isChecked()) {
                if(print[8] != ("NoPedale")) search->show();
                else search->hide();
            } else {
                if(print[8] == ("NoPedale")) search->show();
                else search->hide();
            }
            if(ui->pesaturaComboBox->currentText() == print[7])
                search->show();
            else
                search->hide();

        } else if(dynamic_cast<Workstation*>(list[search])) {
             if(ui->polifoniaSpinBox->value() > 0 && ui->polifoniaSpinBox->value() == print[6].toInt())
                 search->show();
             else
                 search->hide();
             if(ui->pedaleCheckBox->isChecked()) {
                 if(print[7] != ("NoPedale")) search->show();
                 else search->hide();
             } else {
                 if(print[7] == ("NoPedale")) search->show();
                 else search->hide();
             }
             if(ui->pesaturaComboBox->currentText() == print[87])
                 search->show();
             else
                 search->hide();
        } else if(dynamic_cast<Synth*>(list[search])) {
            if(ui->polifoniaSpinBox->value() > 0 && ui->polifoniaSpinBox->value() == print[6].toInt())
                search->show();
            else
                search->hide();
            if(ui->analogCheckBox->isChecked()) {
                if(print[7] != ("NoAnalog")) search->show();
                else search->hide();
            } else {
                if(print[7] == ("NoAnalog")) search->show();
                else search->hide();
            }
        }
    }

}

