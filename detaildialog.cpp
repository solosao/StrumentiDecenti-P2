#include "detaildialog.h"
#include "ui_detaildialog.h"
#include "componentewidget.h"

DetailDialog::DetailDialog(Oggetto* oggetto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    ui->setupUi(this);
    QStringList dettagli = oggetto->print().split("|");
    QString type = dettagli[0];
    ui->nameLabel->setText(dettagli[1]);
    ui->priceLabel->setText(dettagli[2]);

    if(dettagli[3]=="Case")
        ui->caseCheckBox->setCheckState(Qt::CheckState::Checked);
    ui->caseCheckBox->setEnabled(false);

    hideAll();

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

DetailDialog::~DetailDialog()
{
    delete ui;
}

void DetailDialog::hideAll()
{
    ui->batteriaGroupBox->setVisible(false);
    ui->chitarraGroupBox->setVisible(false);
    ui->tastieraGroupBox->setVisible(false);
}

void DetailDialog::hideChitarraElettrica()
{
    ui->labelElettrica1->setVisible(false);
    ui->labelElettrica2->setVisible(false);
    ui->ampLabel->setVisible(false);
    ui->pickupLabel->setVisible(false);
}

void DetailDialog::hideChitarraAcustica()
{
    ui->labelAcustica1->hide();
    ui->labelAcustica2->hide();
    ui->labelAcustica3->hide();
    ui->labelAcustica4->hide();
    ui->corpoLabel->hide();
    ui->tunerCheckBox->hide();
    ui->eqCheckBox->hide();
    ui->cutawayCheckBox->hide();
}

void DetailDialog::hideSynth()
{
    ui->labelSynth1->hide();
    ui->labelSynth2->hide();
}

void DetailDialog::hidePiano()
{
    ui->labelPiano1->hide();
    ui->labelPiano2->hide();
}

void DetailDialog::showBatteria(QStringList det)
{
    ui->batteriaGroupBox->setVisible(true);

    QWidget *widget = new QWidget(this);
    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setWidgetResizable(true);

    QVBoxLayout* layoutScroll = new QVBoxLayout();
    widget->setLayout( layoutScroll );

    for(int i = 0; i < 4; i++) det.removeFirst();
    int numComp = det.length()/3;    

    for(int i = 0; i < numComp; i++) {

        ComponenteWidget* componente = new ComponenteWidget(this);
        componente->setNome(det[i*3 + 1]);
        componente->setPrezzo((det[i*3 + 2]).toFloat());
        componente->setTipo(det[i*3]);
        componente->editableValues(false);


        layoutScroll->addWidget(componente);

        QSpacerItem* verticalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutScroll->addItem(verticalSpacer);
    }
}

void DetailDialog::showChitarraElettrica(QStringList det)
{
    ui->chitarraGroupBox->setVisible(true);
    hideChitarraAcustica();

    //parti di chitarra
    ui->tipoChitarraLabel->setText("Elettrica");
    ui->scalaLabel->setText(det[4]);
    ui->cordeLabel->setText(det[5]);
    ui->legnoLabel->setText(det[6]);
    //parti di chitarra elettrica
    ui->ampLabel->setText(det[7]);
    ui->pickupLabel->setText(det[8]);
}

void DetailDialog::showChitarraAcustica(QStringList det)
{
    ui->chitarraGroupBox->setVisible(true);
    hideChitarraElettrica();

    //parti di chitarra
    ui->tipoChitarraLabel->setText("Acustica");
    ui->scalaLabel->setText(det[4]);
    ui->cordeLabel->setText(det[5]);
    ui->legnoLabel->setText(det[6]);
    //parti di chitarra acustica
    ui->corpoLabel->setText(det[7]);
    ui->tunerCheckBox->setChecked(det[8]=="Tuner");
    ui->tunerCheckBox->setEnabled(false);
    ui->eqCheckBox->setChecked(det[9]=="Eq");
    ui->eqCheckBox->setEnabled(false);
    ui->cutawayCheckBox->setChecked(det[10]=="Cutaway");
    ui->cutawayCheckBox->setEnabled(false);
}

void DetailDialog::showPiano(QStringList det)
{
    ui->tastieraGroupBox->setVisible(true);
    hideSynth();

    //parti di tastiera
    ui->tipoTastieraLabel->setText(det[0]);
    ui->tastiLabel->setText(det[4]);
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    ui->gambeCheckBox->setEnabled(false);
    //parti di tastiera pesata
    ui->pedaleCheckBox->setChecked(det[6]=="Pedale");
    ui->pedaleCheckBox->setEnabled(false);
    ui->pesaturaLabel->setText(det[7]);
}

void DetailDialog::showSynth(QStringList det)
{
    ui->tastieraGroupBox->setVisible(true);
    hidePiano();

    //parti di tastiera
    ui->tipoTastieraLabel->setText(det[0]);
    ui->tastiLabel->setText(det[4]);
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    ui->gambeCheckBox->setEnabled(false);
    //parti di absynth
    ui->polifoniaLabel->setText(det[6]);
    //parti di synth
    ui->analogLabel->setText(det[7]);
}

void DetailDialog::showWorkstation(QStringList det)
{
    ui->tastieraGroupBox->setVisible(true);
    ui->tipoTastieraLabel->setText(det[0]);
    ui->tastiLabel->setText(det[4]);
    ui->gambeCheckBox->setChecked(det[5]=="Gambe");
    ui->gambeCheckBox->setEnabled(false);
    //parti di absynth
    ui->polifoniaLabel->setText(det[6]);
    //parti di tastiera pesata
    ui->pedaleCheckBox->setChecked(det[7]=="Pedale");
    ui->pedaleCheckBox->setEnabled(false);
    ui->pesaturaLabel->setText(det[8]);

    ui->analogLabel->setText("Digital");
}
