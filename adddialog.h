#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QAbstractButton>
#include <QDialog>
#include <QList>
#include <QVBoxLayout>

#include "oggetto.h"
#include "componente.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    Oggetto* buildItem();
    void showOggetto(Oggetto* ogg);
    void editLock();
    void detailLock();

public slots:
    void on_buttonBox_clicked(QAbstractButton * button);
    void on_addComponentePushButton_pressed();

private slots:
    void on_batteriaRadioButton_clicked();

    void on_chitarraRadioButton_clicked();
    void on_acusticaRadioButton_clicked();
    void on_elettricaRadioButton_clicked();

    void on_tastieraRadioButton_clicked();

private:
    Ui::AddDialog *ui;

    void handleRadioButtonStrumento();
    void handleTipoChitarra();

    unsigned int componenteList = 0;

    QVBoxLayout* layoutScroll;

};

#endif // ADDDIALOG_H
