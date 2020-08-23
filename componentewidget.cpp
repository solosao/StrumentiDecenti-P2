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

void ComponenteWidget::on_deletePushButton_released()
{
    deleteLater();
}

