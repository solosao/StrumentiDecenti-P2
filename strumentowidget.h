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
    void initStrumentoWidget(Oggetto* ogg);

public slots:
    void on_detailPushButton_pressed();
    void on_deletePushButton_pressed();
    void on_editPushButton_pressed();

private:
    Ui::StrumentoWidget *ui;

    Oggetto* oggetto;


signals:
//    void initStrumentoWidget(Oggetto *ogg);
    void removeOggetto(Oggetto*);
    void editOggetto(Oggetto*);
    void deleteRequest();
};

#endif // STRUMENTOWIDGET_H
