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

private:
    Ui::AddDialog *ui;

};

#endif // ADDDIALOG_H
