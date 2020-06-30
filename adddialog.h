#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QAbstractButton>
#include <QDialog>

#include "oggetto.h"

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

public slots:
    void on_buttonBox_clicked(QAbstractButton * button);

private slots:
    void on_batteriaRadioButton_clicked();

    void on_chitarraRadioButton_clicked();

    void on_tastieraRadioButton_clicked();

private:
    Ui::AddDialog *ui;

    void handleRadioButtonStrumento();

};

#endif // ADDDIALOG_H
