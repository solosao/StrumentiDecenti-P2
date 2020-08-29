#include "componentewidget.h"
#include "ui_componentewidget.h"

ComponenteWidget::ComponenteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponenteWidget)
{
    ui->setupUi(this);
}

ComponenteWidget::~ComponenteWidget()
{
    delete ui;
}

QString ComponenteWidget::getNome()
{
    return ui->nameLineEdit->text();
}

double ComponenteWidget::getPrezzo()
{
    return ui->priceSpinBox->value();
}

Componente::tipoScelta ComponenteWidget::getTipo()
{
    if(ui->piattoRadioButton->isChecked()) {
        return Componente::tipoScelta::piatto;
    } else if (ui->tamburoRadioButton->isChecked()) {
        return Componente::tipoScelta::tamburo;
    }
}

void ComponenteWidget::setNome(QString name)
{
    ui->nameLineEdit->setText(name);
}

void ComponenteWidget::setPrezzo(double prezzo)
{
    ui->priceSpinBox->setValue(prezzo);
}

void ComponenteWidget::setTipo(QString tipo)
{
    ui->piattoRadioButton->setChecked(tipo == "Piatto");
    ui->tamburoRadioButton->setChecked(tipo == "Tamburo");
}

void ComponenteWidget::editableValues(bool b)
{
    ui->nameLineEdit->setEnabled(b);
    ui->priceSpinBox->setEnabled(b);
    ui->piattoRadioButton->setEnabled(b);
    ui->tamburoRadioButton->setEnabled(b);
    ui->deletePushButton->setVisible(b);
}

void ComponenteWidget::on_deletePushButton_released()
{
    deleteLater();
}

