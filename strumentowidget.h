#ifndef STRUMENTOWIDGET_H
#define STRUMENTOWIDGET_H

#include <QWidget>
#include <QPushButton>

#include <oggetto.h>

namespace Ui {
class StrumentoWidget;
}

class StrumentoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StrumentoWidget(Oggetto *oggetto, QWidget *parent = nullptr);
    ~StrumentoWidget();

private:
    Ui::StrumentoWidget *ui;

    Oggetto* oggetto;

    QPushButton *del;
    QPushButton *edit;

    signals:
    void removeOggetto(Oggetto*);
    void editOggetto(Oggetto*);
};

#endif // STRUMENTOWIDGET_H
