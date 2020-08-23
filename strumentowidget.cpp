#include "strumentowidget.h"
#include "ui_strumentowidget.h"

#include "QString"

StrumentoWidget::StrumentoWidget(Oggetto *oggetto, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StrumentoWidget)
    , oggetto(oggetto)
{
    ui->setupUi(this);

    ui->nomeLabel->setText(oggetto->getNome());
    QString price = QString::number(oggetto->getPrice(), 'f', 2) + "€";
    ui->prezzoLabel->setText(price);


}

StrumentoWidget::~StrumentoWidget()
{
    delete ui;
}