#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"
#include "componente.h"
#include "batteria.h"
#include "chitarraelettrica.h"
#include <QDebug>
#include <QPair>
#include "chitarraacustica.h"
#include "piano.h"
#include "adddialog.h"
#include "QVector"

#include "strumentowidget.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent): QMainWindow(parent), ui(new Ui::StrumentiDecenti){
    ui->setupUi(this);

    //connessione manuale al metodo da chiamare
    connect(ui->resetPushButton, &QPushButton::pressed, this, &StrumentiDecenti::onResetPressed);

    //inizializzo view
    syncBoxed();
    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    ui->scrollArea->setWidgetResizable(true);

    layoutScroll = new QVBoxLayout();
    widget->setLayout( layoutScroll );

    verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
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
    qDebug()<<Q_FUNC_INFO;
}

//connessione manuale ->
void StrumentiDecenti::onResetPressed()
{
    qDebug()<<Q_FUNC_INFO;
}

void StrumentiDecenti::on_priceSlider_valueChanged(int value)
{
    qDebug()<<Q_FUNC_INFO<<value; //macro per debuggare metodo chiamato
    if(ui->priceSpinBox->value() != value) {
        ui->priceSpinBox->setValue(value);
    }
}

void StrumentiDecenti::on_priceSpinBox_valueChanged(int value)
{
    if(ui->priceSlider->value() != value) {
        ui->priceSlider->setValue(value);
    }
    qDebug()<<Q_FUNC_INFO;
}

void StrumentiDecenti::on_batteriaCheckBox_toggled(bool)
{

}

void StrumentiDecenti::on_chitarraCheckBox_toggled(bool toggled)
{
    Q_UNUSED(toggled)
    syncBoxed();
}

void StrumentiDecenti::on_tastieraCheckBox_toggled(bool toggled)
{
    Q_UNUSED(toggled)
    syncBoxed();
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
        try {
            Oggetto* ret = dialog.buildItem();
            qDebug()<<"OK";
            qDebug()<<ret->print();

            layoutScroll->removeItem(verticalSpacer);

            StrumentoWidget* nuovoOggetto = new StrumentoWidget(ret, this);
            nuovoOggetto->initStrumentoWidget(ret);
            connect(nuovoOggetto, &StrumentoWidget::deleteRequest, this, &StrumentiDecenti::deleteStrumento);
            layoutScroll->addWidget( nuovoOggetto );

            list.insert(nuovoOggetto, ret);

            layoutScroll->addItem(verticalSpacer);

        } catch (std::runtime_error& e) {
            QDialog* err = new QDialog(this);
            QLabel* errLabel = new QLabel(err);
            errLabel->setText(e.what());
            QVBoxLayout* errLayout = new QVBoxLayout();
            errLayout->addWidget(errLabel);
            err->setLayout(errLayout);
            err->resize(300,100);
            err->show();
        }


    }
}

void StrumentiDecenti::syncBoxed()
{
    ui->chitarraGroupBox->setVisible(ui->chitarraCheckBox->isChecked());
    ui->tastieraGroupBox->setVisible(ui->tastieraCheckBox->isChecked());

    ui->filtriGroupBox->setVisible(ui->chitarraCheckBox->isChecked() || ui->tastieraCheckBox->isChecked());
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

