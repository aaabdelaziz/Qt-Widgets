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

void Dialog::on_btnOrder_clicked()
{
    // Build Our Order

    // Get Options first
    QString ice_cream = getOption(ui->grpIceCream);    // For Ice Cream Group
    QString toppings = getOption(ui->grpToppings);     // For Toppings Group
    QString syrup = getOption(ui->grpSyrup);           // For Syrup Group
    QString size = getOption(ui->grpSize);             // For Size Group

    // Concatenate Order options
    QString order;
    order += "You have ordered Ice Cream with Options: \r\n";
    order += "Size: "     + size +       " \r\n";
    order += "Flavor: "   + ice_cream +  " \r\n";
    order += "toppings: " + toppings +   " \r\n";
    order += "Syrup: "    + syrup +      " \r\n";


    // Show the total selected Options
    QMessageBox::information(this, "Order", order);
    accept();
}


void Dialog::on_btnCancel_clicked()
{
    QMessageBox::critical(this,"WHY !!","Do not you want Ice Cream !");
    reject();

}

QString Dialog::getOption(QObject *obj)
{
    // Find the Radio Button for options
    QString value = "None";
    QList<QRadioButton*> list = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);

    // Loop on all radio buttons, get the checked ones
    for(QRadioButton *rd : list)
    {
        if(rd->isChecked())
        {
            value = rd->text();
            break;
        }
    }
    return value;
}

