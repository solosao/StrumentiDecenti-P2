#include "strumentowidget.h"
#include "ui_strumentowidget.h"
#include "adddialog.h"
#include <QDebug>
#include "QString"

StrumentoWidget::StrumentoWidget(Oggetto *oggetto, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StrumentoWidget)
    , oggetto(oggetto)
{
    ui->setupUi(this);
//    initStrumentoWidget(oggetto);

}

StrumentoWidget::~StrumentoWidget()
{
    delete ui;
}

void StrumentoWidget::on_detailPushButton_pressed()
{
    DetailDialog dialog(oggetto, this);
    dialog.exec();
}

void StrumentoWidget::on_deletePushButton_pressed()
{
    emit deleteRequest();
}

void StrumentoWidget::on_editPushButton_pressed()
{
    AddDialog dialog(this); //this perchè è figlia della main window
    //dialog.editLock(); //i bottoni vengono lockati ma non scritti quindi per ora non e' il caso
    dialog.showOggetto(oggetto);

    /*
     * apertura dialog con dialog.exec()
     * attendo che ritorni e controllo con enum di QDialog.
     * In questo modo la dialog è "bloccante" la mainWindow non è utilizzabile
    */


    if(dialog.exec() == QDialog::Accepted) {
        qDebug()<<"OK";
        Oggetto* ret = dialog.buildItem();
        oggetto = ret;
        qDebug()<<ret->print();
    }

//    initStrumentoWidget(oggetto);
}

//void StrumentoWidget::initStrumentoWidget(Oggetto *ogg)
//{
//    ui->nomeLabel->setText(ogg->getNome());
//    QString price = QString::number(ogg->getPrice(), 'f', 2) + "€";
//    ui->prezzoLabel->setText(price);
//}
