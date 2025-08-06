#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Set the checable button to true by default
    ui->btnCheckable->setChecked(true);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnCheckable_clicked()
{
    qDebug() << "Checkable Button Status" << ui->btnCheckable->isChecked();
}


void Dialog::on_btnIsChecked_clicked()
{
    QString message;
    if(ui->btnCheckable->isChecked())
    {
        message = "Yes it's checked";
    }
    else
    {
        message = "No it's not checked";

    }
    QMessageBox::information(this,"Checked",message);
}


void Dialog::on_btnAutoRepeat_clicked()
{
    // if the AutoRepeat is false, it means to deactivate, and will deal with one time execution for the button signal no matter you still hold it.
    // the logic is executed after mouse release.
    qInfo() << "Auto Repeat button is Clicked" ;
}

void Dialog::on_btnToggle2_clicked()
{
    bool value = !ui->btnDefault->isDefault();
    ui->btnDefault->setDefault(value);

    // SHow the default value
    qDebug() << " Repeat" << ui->btnDefault->isDefault();

}


void Dialog::on_btnDefault_clicked()
{
    qInfo() << "Default button is Clicked" ;
}


void Dialog::on_btnToggleAutoRepeat_clicked()
{
    // Get the complement value of current AutoRepeat button, to set the toggle button field AutoRepeat.
    // if the AutoRepeat is true, it means to activate the hold press option to execute logic as long as button is still hold pressed. and logic will be always executed.
    // if the AutoRepeat is false, it means to deactivate, and will deal with one time execution for the button signal no matter you still hold it.

    bool value = !ui->btnAutoRepeat->autoRepeat();
    ui->btnAutoRepeat->setAutoRepeat(value);

    // SHow the auto repeat value
    qDebug() << " Repeat: " << ui->btnAutoRepeat->autoRepeat();

}

