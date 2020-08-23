#include "adddialog.h"
#include "ui_adddialog.h"
#include "componente.h"
#include "batteria.h"
#include "chitarra.h"
#include "chitarraelettrica.h"
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


    ui->ampComboBox->addItems(ChitarraElettrica::tipiAmp);

}

AddDialog::~AddDialog()
{
    delete ui;
}

Oggetto *AddDialog::buildItem()
{
//    Componente* prova = new Componente("Piatto Sabian", 16.20, Componente::piatto);
//    Componente* tamb = new Componente("timpano", 100.8, Componente::tamburo);

//    Batteria* vera = new Batteria("Nintendo", 3);
//    vera->addComponente(prova);
//    vera->addComponente(tamb);

//    return vera;

    Oggetto* ret = Q_NULLPTR;

    if(ui->batteriaRadioButton->isChecked()) {
        Batteria* item = new Batteria(ui->nameLineEdit->text(), ui->priceSpinBox->value());
        for (int i=0; i < layoutScroll->count(); ++i){
            if(ComponenteWidget* temp = dynamic_cast<ComponenteWidget*>(layoutScroll->itemAt(i)->widget())){
                item->addComponente(new Componente(temp->getNome(), temp->getPrezzo(), temp->getTipo()));
            }
        }
        ret = item;
    } else if(ui->chitarraRadioButton->isChecked()) {

    } else if(ui->tastieraRadioButton->isChecked()) {

    } else {
//        error
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
