#ifndef COMPONENTEWIDGET_H
#define COMPONENTEWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "componente.h"

namespace Ui {
class ComponenteWidget;
}

class ComponenteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComponenteWidget(QWidget *parent = nullptr);
    ~ComponenteWidget();

    //getter
    QString getNome();
    double getPrezzo();
    Componente::tipoScelta getTipo();

    void setNome(QString name);
    void setPrezzo(double prezzo);
    void setTipo(QString tipo);

    void editableValues(bool b);

public slots:
    void on_deletePushButton_released();

private:
    Ui::ComponenteWidget *ui;
};

#endif // COMPONENTEWIDGET_H
