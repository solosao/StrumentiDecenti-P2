#ifndef STRUMENTIDECENTI_H
#define STRUMENTIDECENTI_H

#include <QMainWindow>
#include <QMap>
#include <QVBoxLayout>

#include "strumento.h"
#include "strumentowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StrumentiDecenti; }
QT_END_NAMESPACE

class StrumentiDecenti : public QMainWindow {
    Q_OBJECT

public:
    StrumentiDecenti(QWidget *parent = nullptr);
    ~StrumentiDecenti();

public slots:
    void on_priceSlider_valueChanged(int);
    void on_priceSpinBox_valueChanged(int);

    void on_searchPushButton_pressed();
    void on_resetPushButton_pressed();


    void on_addPushButton_pressed();

private:
    Ui::StrumentiDecenti *ui;
    void syncBoxed();
    void syncTastieraFilter();

    Q_SLOT void deleteStrumento();

    QVBoxLayout* layoutScroll;
    QSpacerItem* verticalSpacer;

    QMap<StrumentoWidget*, Oggetto*> list;

    void searchChitarra(StrumentoWidget* const);
    void searchTastiera(StrumentoWidget* const);
};
#endif // STRUMENTIDECENTI_H
