#ifndef STRUMENTIDECENTI_H
#define STRUMENTIDECENTI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StrumentiDecenti; }
QT_END_NAMESPACE

class StrumentiDecenti : public QMainWindow {
    Q_OBJECT

public:
    StrumentiDecenti(QWidget *parent = nullptr);
    ~StrumentiDecenti();

public slots:
    void on_searchPushButton_pressed();
    void onResetPressed();
    void on_priceSlider_valueChanged(int);
    void on_priceSpinBox_valueChanged(int);

    void on_batteriaCheckBox_toggled(bool);
    void on_chitarraCheckBox_toggled(bool);
    void on_tastieraCheckBox_toggled(bool);

    void on_addPushButton_pressed();

private:
    Ui::StrumentiDecenti *ui;

    void syncBoxed();
};
#endif // STRUMENTIDECENTI_H
