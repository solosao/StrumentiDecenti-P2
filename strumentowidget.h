#ifndef STRUMENTOWIDGET_H
#define STRUMENTOWIDGET_H

#include <QWidget>
#include <QPushButton>

#include <oggetto.h>
#include "detaildialog.h"

namespace Ui {
class StrumentoWidget;
}

class StrumentoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StrumentoWidget(Oggetto *oggetto, QWidget *parent = nullptr);
    ~StrumentoWidget();

public slots:
    void on_detailPushButton_pressed();
    void on_deletePushButton_pressed();
    void on_editPushButton_pressed();

private:
    Ui::StrumentoWidget *ui;

    Oggetto* oggetto;

    QPushButton *del;
    QPushButton *edit;

    void initStrumentoWidget(Oggetto *ogg);

    signals:
    void removeOggetto(Oggetto*);
    void editOggetto(Oggetto*);
};

#endif // STRUMENTOWIDGET_H
