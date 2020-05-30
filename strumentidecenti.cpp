#include "strumentidecenti.h"
#include "ui_strumentidecenti.h"

StrumentiDecenti::StrumentiDecenti(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StrumentiDecenti)
{
    ui->setupUi(this);
}

StrumentiDecenti::~StrumentiDecenti()
{
    delete ui;
}

