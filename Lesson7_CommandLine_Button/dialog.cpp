#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Ok","Closing");
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    QMessageBox::information(this,"Cancel","Closing");
    reject();
}


void Dialog::on_buttonBox_helpRequested()
{
    QMessageBox::information(this,"HELP","This is to choose which Job type you want, select the corresponding Option\n");

}

void Dialog::selectOption(QObject *sender)
{
    qInfo() << "Select Option buttion is pressed with Obj Name: "
            << sender->objectName() + "\n";

    // Get the pressed button name
    QCommandLinkButton* btn = qobject_cast<QCommandLinkButton*>(sender);
    qInfo() << btn->description() + " Job is Selected";

    // if button name not exist, don't do anything
    if(!btn) return;


    // Show the button info
    ui->lblText->setText(btn->description() + " Job is Selected");
    QMessageBox::information(this,
                            btn->description() + " Job is Selected",
                            btn->text() + " is Selected");

}

void Dialog::on_commandLinkButton_clicked()
{
    selectOption(sender());
}

void Dialog::on_commandLinkButton_2_clicked()
{
    selectOption(sender());
}

void Dialog::on_commandLinkButton_3_clicked()
{
    selectOption(sender());
}

