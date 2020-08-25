#include "detaildialog.h"
#include "ui_detaildialog.h"

DetailDialog::DetailDialog(Oggetto* oggetto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    ui->setupUi(this);
    QStringList dettagli = oggetto->print().split("|");
    QString type = dettagli[0];
    ui->nameLabel->setText(dettagli[1]);
    ui->typeLabel->setText(type);
    ui->priceLabel->setText(dettagli[2]);
    if(dettagli[3]=="Case")
        ui->caseCheckBox->setCheckState(Qt::CheckState::Checked);
    ui->caseCheckBox->setEnabled(false);
    /*
    switch (type) {
        case "batteria":
        case "chitarraElettrica":
        case "chitarraAcustica":
        case "piano":
        case "workstation":
        case "synth":
    }
    */
}

DetailDialog::~DetailDialog()
{
    delete ui;
}
