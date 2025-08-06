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

void Dialog::on_btnOk_clicked()
{
    QString topping;
    // QObjectList boxes = this->children();                        //Create Object list boxes to point to all checkboxes
    QList<QCheckBox*> boxes = this->findChildren<QCheckBox*>();  //Get the CheckBoxes Only from all the Childrens

    // Loop on all child checkboxes
    for(QCheckBox* box : boxes)
    {
        qDebug() << "A check box is selected";
        // Check if the check box is existed and is checked, add the checkbox name to the toppings
        if(box->isChecked())
            // get the box text name
            topping += box->text() + "\r\n";
    }

    //Create user message to show selected toppings
    QMessageBox::information(this, "Toppings", "Toppings to include\r\n" + topping);

}

