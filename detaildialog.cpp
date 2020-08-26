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
    ui->priceLabel->setText(dettagli[2]);

    if(dettagli[3]=="Case")
        ui->caseCheckBox->setCheckState(Qt::CheckState::Checked);
    ui->caseCheckBox->setEnabled(false);

    ui->batteriaGroupBox->setVisible(false);
    ui->chitarraGroupBox->setVisible(false);
    ui->tastieraGroupBox->setVisible(false);

    QStringList typeList = {"Batteria", "ChitarraElettrica", "ChitarraAcustica","Piano","Workstation","Synth"};
    switch (typeList.indexOf(type)) {
    case 0:{
        ui->batteriaGroupBox->setVisible(true);
        break;
    }
    case 1:{
        ui->chitarraGroupBox->setVisible(true);
        break;
    }
    case 2:{
        ui->chitarraGroupBox->setVisible(true);
        break;
    }
    case 3:{
        ui->tastieraGroupBox->setVisible(true);
        break;
    }
    case 4:{
        ui->tastieraGroupBox->setVisible(true);
        break;
    }
    case 5:{
        ui->tastieraGroupBox->setVisible(true);
        break;
    }
    }

}

DetailDialog::~DetailDialog()
{
    delete ui;
}
