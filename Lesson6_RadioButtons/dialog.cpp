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
    order += "You have ordered Ice Cream with Options:\n";
    order += "-----------------------------\n";
    order += QString("1. %1 %2\t\n").arg(QString("Size:").leftJustified(0), size);
    order += QString("2. %1 %2\t\n").arg(QString("Flavor:").leftJustified(0), ice_cream);
    order += QString("3. %1 %2\t\n").arg(QString("Toppings:").leftJustified(0), toppings);
    order += QString("4. %1 %2\t\n").arg(QString("Syrup:").leftJustified(0), syrup);
    order += "-----------------------------\n";

    // Show the total selected Options
    //QMessageBox::information(this, "Order", order);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Order");
    msgBox.setTextFormat(Qt::PlainText);  // Ensures left alignment
    msgBox.setText(order);
    msgBox.exec();

    accept();
}


void Dialog::on_btnCancel_clicked()
{
    // QMessageBox::critical(this,"WHY !!","Do not you want Ice Cream 😢 !"); // Option 1
    /*  // Option 2
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("WHY !!");
        msgBox.setText("Do not you want Ice Cream 😢 !");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    */

    // Check if Image is loaded
    QPixmap pix(":/icons/warning.png");
    qDebug() << "Is pix valid? " << !pix.isNull();

    // Show the message
    QMessageBox msgBox;
    msgBox.setIconPixmap(QPixmap(":/icons/red_warning.png")); // Option 3 to use your Icon,
    msgBox.setText("Do not you want Ice Cream 😢 !");
    msgBox.exec();

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

