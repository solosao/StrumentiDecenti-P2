#include "adddialog.h"
#include "ui_adddialog.h"
#include "componente.h"
#include "batteria.h"
#include "chitarra.h"
#include "chitarraelettrica.h"
#include "chitarraacustica.h"
#include "tastiera.h"
#include "tastierapesata.h"
#include "piano.h"
#include "workstation.h"
#include "synth.h"
#include "componentewidget.h"
#include <QDialogButtonBox>
#include <QDebug>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    handleRadioButtonStrumento();
    handleTipoChitarra();
    ui->tastieraLayout->setVisible(false);

    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    ui->scrollArea->setWidgetResizable(true);

    layoutScroll = new QVBoxLayout();
    widget->setLayout( layoutScroll );

    //init ComboBox
    ui->legnoComboBox->addItems(Chitarra::tipiLegno);
    ui->cordeComboBox->addItems(Chitarra::tipiCorde);
    ui->ampComboBox->addItems(ChitarraElettrica::tipiAmp);
    ui->pickupComboBox->addItems(ChitarraElettrica::tipiPickup);
    ui->corpoComboBox->addItems(ChitarraAcustica::tipiCorpo);
    ui->pesaturaComboBox->addItems(TastieraPesata::tipiPesatura);


}

AddDialog::~AddDialog()
{
    delete ui;
}

Oggetto *AddDialog::buildItem()
{
//    Oggetto* ret = Q_NULLPTR;

    if(ui->batteriaRadioButton->isChecked()) {
        Batteria* item = new Batteria(ui->nameLineEdit->text(), ui->priceSpinBox->value(), ui->custodiaCheckBox->isChecked());
        for (int i=0; i < layoutScroll->count(); ++i){
            if(ComponenteWidget* temp = dynamic_cast<ComponenteWidget*>(layoutScroll->itemAt(i)->widget())){
                item->addComponente(new Componente(temp->getNome(), temp->getPrezzo(), temp->getTipo()));
            }
        }
        return item;
    } else if(ui->chitarraRadioButton->isChecked()) {

        if(ui->acusticaRadioButton->isChecked()) {

            ChitarraAcustica* item = new ChitarraAcustica(ui->nameLineEdit->text(),
                                                          ui->priceSpinBox->value(),
                                                          Chitarra::legnoStringToEnum(ui->legnoComboBox->currentText()),
                                                          ui->scalaSpinBox->value(),
                                                          ChitarraAcustica::corpoStringToEnum(ui->corpoComboBox->currentText()),
                                                          ui->tunerCheckBox->isChecked(),
                                                          ui->eqCheckBox->isChecked(),
                                                          ui->cutawayCheckBox->isChecked(),
                                                          Chitarra::cordeStringToEnum(ui->cordeComboBox->currentText()),
                                                          ui->custodiaCheckBox->isChecked());

            return item;
        } else if (ui->elettricaRadioButton->isChecked()) {
            ChitarraElettrica* item = new ChitarraElettrica(ui->nameLineEdit->text(),
                                                            ui->priceSpinBox->value(),
                                                            Chitarra::legnoStringToEnum(ui->legnoComboBox->currentText()),
                                                            ui->scalaSpinBox->value(),
                                                            ChitarraElettrica::pickupStringToEnum(ui->pickupComboBox->currentText()),
                                                            ChitarraElettrica::ampStringToEnum(ui->ampComboBox->currentText()),
                                                            Chitarra::cordeStringToEnum(ui->cordeComboBox->currentText()),
                                                            ui->custodiaCheckBox->isChecked());
        return item;
        } else {
            // error
        }
    } else if(ui->tastieraRadioButton->isChecked()) {
        if(ui->pianoRadioButton->isChecked()) {
            Piano* item = new Piano(ui->nameLineEdit->text(),
                                    ui->priceSpinBox->value(),
                                    ui->custodiaCheckBox->isChecked(),
                                    ui->tastiSpinBox->value(),
                                    ui->gambeCheckBox->isChecked(),
                                    ui->pedaleCheckBox->isChecked(),
                                    TastieraPesata::pesaturaStringToEnum(ui->pesaturaComboBox->currentText()));
            return item;
        } else if(ui->workstationRadioButton->isChecked()) {
            Workstation* item = new Workstation(ui->nameLineEdit->text(),
                                                ui->priceSpinBox->value(),
                                                ui->custodiaCheckBox->isChecked(),
                                                ui->tastiSpinBox->value(),
                                                ui->gambeCheckBox->isChecked(),
                                                ui->pedaleCheckBox->isChecked(),
                                                TastieraPesata::pesaturaStringToEnum(ui->pesaturaComboBox->currentText()),
                                                ui->polifoniaSpinBox->value());
            return item;
        } else if(ui->synthRadioButton->isChecked()) {
            Synth* item = new Synth(ui->nameLineEdit->text(),
                                    ui->priceSpinBox->value(),
                                    ui->custodiaCheckBox->isChecked(),
                                    ui->tastiSpinBox->value(),
                                    ui->gambeCheckBox->isChecked(),
                                    ui->polifoniaSpinBox->value());
            return item;
        } else {
            //error
        }
    } else {
        // error
    }

}

void AddDialog::on_buttonBox_clicked(QAbstractButton * button)
{
    switch (ui->buttonBox->buttonRole(button))
    {
    case QDialogButtonBox::ButtonRole::AcceptRole:
        accept();
        break;
    case QDialogButtonBox::ButtonRole::DestructiveRole:
    case QDialogButtonBox::ButtonRole::RejectRole:
        reject();
        break;
    default:
        break;
    }
}

void DeleteComponente() {

}

void AddDialog::on_addComponentePushButton_pressed()
{
    ComponenteWidget* componente = new ComponenteWidget(this);
    layoutScroll->addWidget( componente );

    QSpacerItem* verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    layoutScroll->addItem(verticalSpacer);
}

void AddDialog::on_batteriaRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_chitarraRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_acusticaRadioButton_clicked()
{
    handleTipoChitarra();
}

void AddDialog::on_elettricaRadioButton_clicked()
{
    handleTipoChitarra();
}

void AddDialog::handleTipoChitarra() {
    ui->acusticaFormLayout->setVisible(ui->acusticaRadioButton->isChecked());
    ui->elettricaFormLayout->setVisible(ui->elettricaRadioButton->isChecked());
}

void AddDialog::on_tastieraRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_pianoRadioButton_clicked()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(false);
    ui->polifoniaSpinBox->setVisible(false);
    ui->analogLabel->setVisible(false);
    ui->analogCheckBox->setVisible(false);
    ui->pesaturaLabel->setVisible(true);
    ui->pesaturaComboBox->setVisible(true);
    ui->pedaleLabel->setVisible(true);
    ui->pedaleCheckBox->setVisible(true);
}

void AddDialog::on_workstationRadioButton_clicked()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(true);
    ui->polifoniaSpinBox->setVisible(true);
    ui->analogLabel->setVisible(false);
    ui->analogCheckBox->setVisible(false);
    ui->pesaturaLabel->setVisible(true);
    ui->pesaturaComboBox->setVisible(true);
    ui->pedaleLabel->setVisible(true);
    ui->pedaleCheckBox->setVisible(true);
}

void AddDialog::on_synthRadioButton_clicked()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(true);
    ui->polifoniaSpinBox->setVisible(true);
    ui->analogLabel->setVisible(true);
    ui->analogCheckBox->setVisible(true);
    ui->pesaturaLabel->setVisible(false);
    ui->pesaturaComboBox->setVisible(false);
    ui->pedaleLabel->setVisible(false);
    ui->pedaleCheckBox->setVisible(false);
}

void AddDialog::handleRadioButtonStrumento()
{
    ui->batteriaGroupBox->setVisible(ui->batteriaRadioButton->isChecked());
    ui->chitarraGroupBox->setVisible(ui->chitarraRadioButton->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraRadioButton->isChecked());

}
