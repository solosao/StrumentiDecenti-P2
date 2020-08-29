#include "adddialog.h"
#include "ui_adddialog.h"
#include "componente.h"
#include "batteria.h"
#include "chitarra.h"
#include "chitarraelettrica.h"
#include "chitarraacustica.h"
#include "tastiera.h"
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

}

AddDialog::~AddDialog()
{
    delete ui;
}

Oggetto *AddDialog::buildItem()
{
    Oggetto* ret = Q_NULLPTR;

    if(ui->batteriaRadioButton->isChecked()) {
        Batteria* item = new Batteria(ui->nameLineEdit->text(), ui->priceSpinBox->value(), ui->custodiaCheckBox->isChecked());
        for (int i=0; i < layoutScroll->count(); ++i){
            if(ComponenteWidget* temp = dynamic_cast<ComponenteWidget*>(layoutScroll->itemAt(i)->widget())){
                item->addComponente(new Componente(temp->getNome(), temp->getPrezzo(), temp->getTipo()));
            }
        }
        ret = item;
    } else if(ui->chitarraRadioButton->isChecked()) {

        //handle enum to string
        Chitarra::tipoLegno legno;

        if(ui->legnoComboBox->currentText() == "acero") {
            legno = Chitarra::tipoLegno::acero;
        } else if(ui->legnoComboBox->currentText() == "mogano") {
            legno = Chitarra::tipoLegno::mogano;
        } else if(ui->legnoComboBox->currentText() == "frassino") {
            legno = Chitarra::tipoLegno::frassino;
        } else if(ui->legnoComboBox->currentText() == "ciliegio") {
            legno = Chitarra::tipoLegno::ciliegio;
        }

        Chitarra::tipoCorde corde;

        if(ui->legnoComboBox->currentText() == "sottili") {
            corde = Chitarra::tipoCorde::sottili;
        } else if(ui->legnoComboBox->currentText() == "spesse") {
            corde = Chitarra::tipoCorde::spesse;
        } else if(ui->legnoComboBox->currentText() == "premium") {
            corde = Chitarra::tipoCorde::premium;
        }

        if(ui->acusticaRadioButton->isChecked()) {

            //handle enum to string
            ChitarraAcustica::tipoCorpo corpo;

            if(ui->corpoComboBox->currentText() == "acustico") {
                corpo = ChitarraAcustica::tipoCorpo::acustico;
            } else if(ui->corpoComboBox->currentText() == "semiacustico") {
                corpo = ChitarraAcustica::tipoCorpo::semiacustico;
            } else if(ui->corpoComboBox->currentText() == "classico") {
                corpo = ChitarraAcustica::tipoCorpo::classico;
            } else if(ui->corpoComboBox->currentText() == "banjo") {
                corpo = ChitarraAcustica::tipoCorpo::banjo;
            }

            ChitarraAcustica* item = new ChitarraAcustica(ui->nameLineEdit->text(),
                                                          ui->priceSpinBox->value(),
                                                          legno,
                                                          ui->scalaSpinBox->value(),
                                                          corpo,
                                                          ui->tunerCheckBox->isChecked(),
                                                          ui->eqCheckBox->isChecked(),
                                                          ui->cutawayCheckBox->isChecked(),
                                                          corde,
                                                          ui->custodiaCheckBox->isChecked());

          qDebug()<<item<<"acustica";
          qDebug()<<item->print();
            ret = item;
        } else if (ui->elettricaRadioButton->isChecked()) {

        } else {
            // error
        }
    } else if(ui->tastieraRadioButton->isChecked()) {

    } else {
        // error
    }



    return ret;

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

void AddDialog::handleRadioButtonStrumento()
{
    ui->batteriaGroupBox->setVisible(ui->batteriaRadioButton->isChecked());
    ui->chitarraGroupBox->setVisible(ui->chitarraRadioButton->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraRadioButton->isChecked());

}
