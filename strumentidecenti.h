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

private:
    Ui::StrumentiDecenti *ui;
};
#endif // STRUMENTIDECENTI_H
