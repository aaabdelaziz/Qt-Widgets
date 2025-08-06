#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Third Method, Connect the btn UI with the signal clicked not the slot, this will call the slot directly
    connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::dostuff);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dostuff()
{
    // First Method, create my slot manually here
    qInfo() << "Clicked " << QDateTime::currentDateTime().toString();
    //accept() //will close
}

void Dialog::on_btnEditor_clicked()
{
    // Second Method, create slot from the UI automatically generate here
    qDebug() << " Extra Stuff !!";
    dostuff();
}

