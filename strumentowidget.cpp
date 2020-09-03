#include "strumentowidget.h"
#include "ui_strumentowidget.h"
#include "adddialog.h"
#include <QString>

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
    AddDialog dialog(this);
    dialog.detailMode();
    dialog.resize(400,600);
    dialog.showOggetto(oggetto);

    dialog.exec();
}

void StrumentoWidget::on_deletePushButton_pressed()
{
    emit deleteRequest();
}

void StrumentoWidget::on_editPushButton_pressed()
{
    AddDialog dialog(this);
    dialog.editMode();
    dialog.resize(400,600);
    dialog.showOggetto(oggetto);

    try {
        if(dialog.exec() == QDialog::Accepted) {
            Oggetto* ret = dialog.buildItem();
            oggetto = ret;
        }

    } catch (std::runtime_error& e) {
        dialog.errorDialog(e.what());
    }


    initStrumentoWidget(oggetto);
}

void StrumentoWidget::initStrumentoWidget(Oggetto* ogg)
{
    ui->nomeLabel->setText(ogg->getNome());
    QString price = QString::number(ogg->getPrice(), 'f', 2) + "€";
    ui->prezzoLabel->setNum(ogg->getPrice());
}
