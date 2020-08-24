#include "detaildialog.h"
#include "ui_detaildialog.h"

DetailDialog::DetailDialog(Oggetto* oggetto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    ui->setupUi(this);
    QString dettagli = oggetto->print();
    ui->nameLabel->setText(dettagli);
}

DetailDialog::~DetailDialog()
{
    delete ui;
}
