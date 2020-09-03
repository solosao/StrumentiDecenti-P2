#include "adddialog.h"
#include "ui_adddialog.h"
#include "componente.h"
#include "batteria.h"
#include "chitarra.h"
#include "chitarraelettrica.h"
#include "chitarraacustica.h"
#include "tastiera.h"
#include "tastierapesata.h"
#include "piano.h"
#include "workstation.h"
#include "synth.h"
#include "componentewidget.h"
#include <QDialogButtonBox>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    handleRadioButtonStrumento();
    handleTipoChitarra();
    ui->tastieraLayout->setVisible(false);

    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    ui->scrollArea->setWidgetResizable(true);

    layoutScroll = new QVBoxLayout();
    widget->setLayout( layoutScroll );

    //init ComboBox
    ui->legnoComboBox->addItems(Chitarra::tipiLegno);
    ui->cordeComboBox->addItems(Chitarra::tipiCorde);
    ui->ampComboBox->addItems(ChitarraElettrica::tipiAmp);
    ui->pickupComboBox->addItems(ChitarraElettrica::tipiPickup);
    ui->corpoComboBox->addItems(ChitarraAcustica::tipiCorpo);
    ui->pesaturaComboBox->addItems(TastieraPesata::tipiPesatura);

}

AddDialog::~AddDialog()
{
    delete ui;
}

Oggetto *AddDialog::buildItem() const
{
//    Oggetto* ret = Q_NULLPTR;


    if(ui->batteriaRadioButton->isChecked()) {
        Batteria* item = new Batteria(ui->nameLineEdit->text(), ui->priceSpinBox->value(), ui->custodiaCheckBox->isChecked());
        for (int i=0; i < layoutScroll->count(); ++i){
            if(ComponenteWidget* temp = dynamic_cast<ComponenteWidget*>(layoutScroll->itemAt(i)->widget())){
                item->addComponente(new Componente(temp->getNome(), temp->getPrezzo(), temp->getTipo()));
            }
        }
        return item;
    } else if(ui->chitarraRadioButton->isChecked()) {

        if(ui->acusticaRadioButton->isChecked()) {
            ChitarraAcustica* item = new ChitarraAcustica(
                        ui->nameLineEdit->text(),
                        ui->priceSpinBox->value(),
                        Chitarra::legnoStringToEnum(ui->legnoComboBox->currentText()),
                        ui->scalaSpinBox->value(),
                        ChitarraAcustica::corpoStringToEnum(ui->corpoComboBox->currentText()),
                        ui->tunerCheckBox->isChecked(),
                        ui->eqCheckBox->isChecked(),
                        ui->cutawayCheckBox->isChecked(),
                        Chitarra::cordeStringToEnum(ui->cordeComboBox->currentText()),
                        ui->custodiaCheckBox->isChecked());

            return item;
        } else if (ui->elettricaRadioButton->isChecked()) {
            ChitarraElettrica* item = new ChitarraElettrica(ui->nameLineEdit->text(),
                                                            ui->priceSpinBox->value(),
                                                            Chitarra::legnoStringToEnum(ui->legnoComboBox->currentText()),
                                                            ui->scalaSpinBox->value(),
                                                            ChitarraElettrica::tipoPickup(ui->pickupComboBox->currentIndex()),
                                                            ChitarraElettrica::tipoAmp(ui->ampComboBox->currentIndex()),
                                                            Chitarra::cordeStringToEnum(ui->cordeComboBox->currentText()),
                                                            ui->custodiaCheckBox->isChecked());
        return item;
        } else {
            return NULL;
        }
    } else if(ui->tastieraRadioButton->isChecked()) {
        if(ui->pianoRadioButton->isChecked()) {
            Piano* item = new Piano(ui->nameLineEdit->text(),
                                    ui->priceSpinBox->value(),
                                    ui->custodiaCheckBox->isChecked(),
                                    ui->tastiSpinBox->value(),
                                    ui->gambeCheckBox->isChecked(),
                                    ui->pedaleCheckBox->isChecked(),
                                    TastieraPesata::pesaturaStringToEnum(ui->pesaturaComboBox->currentText()));
            return item;
        } else if(ui->workstationRadioButton->isChecked()) {
            Workstation* item = new Workstation(ui->nameLineEdit->text(),
                                                ui->priceSpinBox->value(),
                                                ui->custodiaCheckBox->isChecked(),
                                                ui->tastiSpinBox->value(),
                                                ui->gambeCheckBox->isChecked(),
                                                ui->pedaleCheckBox->isChecked(),
                                                TastieraPesata::pesaturaStringToEnum(ui->pesaturaComboBox->currentText()),
                                                ui->polifoniaSpinBox->value());
            return item;
        } else if(ui->synthRadioButton->isChecked()) {
            Synth* item = new Synth(ui->nameLineEdit->text(),
                                    ui->priceSpinBox->value(),
                                    ui->custodiaCheckBox->isChecked(),
                                    ui->tastiSpinBox->value(),
                                    ui->gambeCheckBox->isChecked(),
                                    ui->polifoniaSpinBox->value());
            return item;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }

}

void AddDialog::showOggetto(Oggetto *ogg)
{
    QStringList dettagli = ogg->print().split('|');
    QString type = dettagli[0];
    ui->nameLineEdit->setText(dettagli[1]);
    ui->priceSpinBox->setValue(ogg->getInitPrice()  );
    ui->totalPriceLabel->setNum(ogg->getPrice());
    ui->custodiaCheckBox->setChecked(dettagli[3]=="Case");

    QStringList typeList = {"Batteria", "ChitarraElettrica", "ChitarraAcustica","Piano","Workstation","Synth"};
    switch (typeList.indexOf(type)) {
    case 0:{
        showBatteria(dettagli);
        break;
    }
    case 1:{
        showChitarraElettrica(dettagli);
        break;
    }
    case 2:{
        showChitarraAcustica(dettagli);
        break;
    }
    case 3:{
        showPiano(dettagli);
        break;
    }
    case 4:{
        showWorkstation(dettagli);
        break;
    }
    case 5:{
        showSynth(dettagli);
        break;
    }
    }

}

void AddDialog::addMode()
{
    ui->nameLineEdit->setText("Strumento");
    ui->totalLabel->setVisible(false);
    ui->totalPriceLabel->setVisible(false);
}

void AddDialog::editMode()
{
    ui->totalLabel->setVisible(false);
    ui->totalPriceLabel->setVisible(false);
    ui->batteriaRadioButton->setEnabled(false);
    ui->chitarraRadioButton->setEnabled(false);
    ui->tastieraRadioButton->setEnabled(false);
}

void AddDialog::detailMode()
{
    ui->buttonBox->setVisible(false);
    ui->nameLineEdit->setEnabled(false);
    ui->priceSpinBox->setEnabled(false);
    ui->custodiaCheckBox->setEnabled(false);
    ui->batteriaRadioButton->setEnabled(false);
    ui->chitarraRadioButton->setEnabled(false);
    ui->tastieraRadioButton->setEnabled(false);
    //batteria
    ui->addComponentePushButton->setVisible(false);
    //chitarra
    ui->scalaSpinBox->setEnabled(false);
    ui->legnoComboBox->setEnabled(false);
    ui->cordeComboBox->setEnabled(false);
    ui->acusticaRadioButton->setEnabled(false);
    ui->elettricaRadioButton->setEnabled(false);
    //acustica
    ui->corpoComboBox->setEnabled(false);
    ui->eqCheckBox->setEnabled(false);
    ui->tunerCheckBox->setEnabled(false);
    ui->cutawayCheckBox->setEnabled(false);
    //elettrica
    ui->pickupComboBox->setEnabled(false);
    ui->ampComboBox->setEnabled(false);
    //tastiera
    ui->tastiSpinBox->setEnabled(false);
    ui->gambeCheckBox->setEnabled(false);
    ui->pianoRadioButton->setEnabled(false);
    ui->synthRadioButton->setEnabled(false);
    ui->workstationRadioButton->setEnabled(false);
    //piano
    ui->pesaturaComboBox->setEnabled(false);
    ui->pedaleCheckBox->setEnabled(false);
    //synth
    ui->polifoniaSpinBox->setEnabled(false);
    ui->analogCheckBox->setEnabled(false);
}

void AddDialog::showBatteria(QStringList& det)
{
    ui->batteriaRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    for(int i = 0; i < 4; i++) det.removeFirst();
    int numComp = det.length()/3;

    for(int i = 0; i < numComp; i++) {

        ComponenteWidget* componente = new ComponenteWidget(this);
        componente->setNome(det[i*3 + 1]);
        componente->setPrezzo((det[i*3 + 2]).toFloat());
        componente->setTipo(det[i*3]);

        componente->editableValues(ui->nameLineEdit->isEnabled());

        layoutScroll->addWidget(componente);

        QSpacerItem* verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutScroll->addItem(verticalSpacer);
    }
}

void AddDialog::showChitarraElettrica(QStringList& det)
{
    ui->chitarraRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    ui->elettricaRadioButton->setChecked(true);
    handleTipoChitarra();
    //parti di chitarra
    ui->scalaSpinBox->setValue(det[4].toFloat());
    ui->cordeComboBox->setCurrentText(det[5]);
    ui->legnoComboBox->setCurrentText(det[6]);
    //parti di chitarra elettrica
    ui->ampComboBox->setCurrentText(det[7]);
    ui->pickupComboBox->setCurrentText(det[8]);
}

void AddDialog::showChitarraAcustica(QStringList& det)
{
    ui->chitarraRadioButton->setChecked(true);
    ui->acusticaRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    handleTipoChitarra();
    //parti di chitarra
    ui->scalaSpinBox->setValue(det[4].toFloat());
    ui->cordeComboBox->setCurrentText(det[5]);
    ui->legnoComboBox->setCurrentText(det[6]);
    //parti di chitarra scustica
    ui->corpoComboBox->setCurrentText(det[7]);
    ui->tunerCheckBox->setChecked(det[8]=="Tuner");
    ui->eqCheckBox->setChecked(det[9]=="Eq");
    ui->cutawayCheckBox->setChecked(det[10]=="Cutaway");
}

void AddDialog::showPiano(QStringList& det)
{
    ui->tastieraRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    ui->pianoRadioButton->setChecked(true);
    setPianoVisible();
    //parti di tastiera
    ui->tastiSpinBox->setValue(det[4].toInt());
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    //parti di tastiera pesata
    ui->pedaleCheckBox->setChecked(det[6]=="Pedale");
    ui->pesaturaComboBox->setCurrentText(det[7]);
}

void AddDialog::showSynth(QStringList& det)
{
    ui->tastieraRadioButton->setChecked(true);
    ui->synthRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    setSynthVisible();
    //parti di tastiera
    ui->tastiSpinBox->setValue(det[4].toInt());
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    //parti di absynth
    ui->polifoniaSpinBox->setValue(det[6].toInt());
    //parti di synth
    ui->analogCheckBox->setChecked(det[7]=="Analog");
}

void AddDialog::showWorkstation(QStringList& det)
{
    ui->tastieraRadioButton->setChecked(true);
    ui->workstationRadioButton->setChecked(true);
    handleRadioButtonStrumento();
    setWorkstationVisible();
    //parti di tastiera
    ui->tastiSpinBox->setValue(det[4].toInt());
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    //parti di absynth
    ui->polifoniaSpinBox->setValue(det[6].toInt());
    //parti di tastiera pesata
    ui->pedaleCheckBox->setChecked(det[7]=="Pedale");
    ui->pesaturaComboBox->setCurrentText(det[8]);

}

void AddDialog::setSynthVisible()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(true);
    ui->polifoniaSpinBox->setVisible(true);
    ui->analogLabel->setVisible(true);
    ui->analogCheckBox->setVisible(true);
    ui->pesaturaLabel->setVisible(false);
    ui->pesaturaComboBox->setVisible(false);
    ui->pedaleLabel->setVisible(false);
    ui->pedaleCheckBox->setVisible(false);
}

void AddDialog::setPianoVisible()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(false);
    ui->polifoniaSpinBox->setVisible(false);
    ui->analogLabel->setVisible(false);
    ui->analogCheckBox->setVisible(false);
    ui->pesaturaLabel->setVisible(true);
    ui->pesaturaComboBox->setVisible(true);
    ui->pedaleLabel->setVisible(true);
    ui->pedaleCheckBox->setVisible(true);
}

void AddDialog::setWorkstationVisible()
{
    ui->tastieraLayout->setVisible(true);
    ui->polifoniaLabel->setVisible(true);
    ui->polifoniaSpinBox->setVisible(true);
    ui->analogLabel->setVisible(false);
    ui->analogCheckBox->setVisible(false);
    ui->pesaturaLabel->setVisible(true);
    ui->pesaturaComboBox->setVisible(true);
    ui->pedaleLabel->setVisible(true);
    ui->pedaleCheckBox->setVisible(true);
}

void AddDialog::errorDialog(const QString error) const
{
    QDialog* err = new QDialog();
    QLabel* titleLabel = new QLabel(err);
    titleLabel->setText("Impossibile creare strumento:");
    QLabel* errLabel = new QLabel(err);
    errLabel->setText(error);
    QVBoxLayout* errLayout = new QVBoxLayout();
    errLayout->addWidget(titleLabel);
    errLayout->addWidget(errLabel);
    err->setLayout(errLayout);
    err->resize(300,100);
    err->show();
}

QString AddDialog::isValid() const
{
    if(ui->nameLineEdit->text().isEmpty()) return "Strumento senza nome";
    if (!(ui->batteriaRadioButton->isChecked() || ui->chitarraRadioButton->isChecked() ||ui->tastieraRadioButton->isChecked())) return "Tipo non selezionato";
    if(ui->batteriaRadioButton->isChecked()) {
        for (int i=0; i < layoutScroll->count(); ++i){
            if(ComponenteWidget* temp = dynamic_cast<ComponenteWidget*>(layoutScroll->itemAt(i)->widget())){
              if(temp->getNome().isEmpty()) return "Componente senza nome";
            }
        }

    }
    return "";
}

void AddDialog::on_buttonBox_clicked(QAbstractButton * button)
{
    switch (ui->buttonBox->buttonRole(button))
    {
    case QDialogButtonBox::ButtonRole::AcceptRole:
        accept();
        break;
    case QDialogButtonBox::ButtonRole::DestructiveRole:
    case QDialogButtonBox::ButtonRole::RejectRole:
        reject();
        break;
    default:
        break;
    }
}

void DeleteComponente() {

}

void AddDialog::on_addComponentePushButton_pressed()
{
    ComponenteWidget* componente = new ComponenteWidget(this);
    componente->setNome("Componente");
    componente->setTipo("Piatto");
    layoutScroll->addWidget( componente );

    QSpacerItem* verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    layoutScroll->addItem(verticalSpacer);
}

void AddDialog::on_batteriaRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_chitarraRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_acusticaRadioButton_clicked()
{
    handleTipoChitarra();
}

void AddDialog::on_elettricaRadioButton_clicked()
{
    handleTipoChitarra();
}

void AddDialog::handleTipoChitarra() {
    ui->acusticaFormLayout->setVisible(ui->acusticaRadioButton->isChecked());
    ui->elettricaFormLayout->setVisible(ui->elettricaRadioButton->isChecked());
}

void AddDialog::on_tastieraRadioButton_clicked()
{
    handleRadioButtonStrumento();
}

void AddDialog::on_pianoRadioButton_clicked()
{
    setPianoVisible();
}

void AddDialog::on_workstationRadioButton_clicked()
{
    setWorkstationVisible();
}

void AddDialog::on_synthRadioButton_clicked()
{
    setSynthVisible();
}

void AddDialog::handleRadioButtonStrumento()
{

    ui->batteriaGroupBox->setVisible(false);
    ui->chitarraGroupBox->setVisible(false);
    ui->tastieraGroupBox->setVisible(false);

    ui->batteriaGroupBox->setVisible(ui->batteriaRadioButton->isChecked());
    ui->chitarraGroupBox->setVisible(ui->chitarraRadioButton->isChecked());    
    ui->acusticaRadioButton->setChecked(true);
    handleTipoChitarra();
    ui->tastieraGroupBox->setVisible(ui->tastieraRadioButton->isChecked());
    ui->pianoRadioButton->setChecked(true);
    setPianoVisible();
}
