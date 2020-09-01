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

    void addMode();
    void editMode();
    void detailMode();

    void showBatteria(QStringList& det);
    void showChitarraElettrica(QStringList& det);
    void showChitarraAcustica(QStringList& det);
    void showPiano(QStringList& det);
    void showSynth(QStringList& det);
    void showWorkstation(QStringList& det);

    void setSynthVisible();
    void setPianoVisible();
    void setWorkstationVisible();

    void errorDialog(const char* err) const;

public slots:
    void on_buttonBox_clicked(QAbstractButton * button);
    void on_addComponentePushButton_pressed();

private slots:
    void on_batteriaRadioButton_clicked();

    void on_chitarraRadioButton_clicked();
    void on_acusticaRadioButton_clicked();
    void on_elettricaRadioButton_clicked();

    void on_tastieraRadioButton_clicked();
    void on_pianoRadioButton_clicked();
    void on_workstationRadioButton_clicked();
    void on_synthRadioButton_clicked();

private:
    Ui::AddDialog *ui;

    void handleRadioButtonStrumento();
    void handleTipoChitarra();

    unsigned int componenteList = 0;

    QVBoxLayout* layoutScroll;

};

#endif // ADDDIALOG_H
