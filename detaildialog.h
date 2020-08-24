#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>
#include <oggetto.h>

namespace Ui {
class DetailDialog;
}

class DetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailDialog(Oggetto* oggetto, QWidget *parent = nullptr);
    ~DetailDialog();

private:
    Ui::DetailDialog *ui;
};

#endif // DETAILDIALOG_H
