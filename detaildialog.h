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

    void hideAll();
    void hideChitarraElettrica();
    void hideChitarraAcustica();
    void hideSynth();
    void hidePiano();
    void showBatteria(QStringList det);
    void showChitarraElettrica(QStringList det);
    void showChitarraAcustica(QStringList det);
    void showPiano(QStringList det);
    void showSynth(QStringList det);
    void showWorkstation(QStringList det);
};

#endif // DETAILDIALOG_H
