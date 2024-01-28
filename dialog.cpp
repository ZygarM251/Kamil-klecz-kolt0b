#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getWiek(){
    return ui->spinBox->value();
}
QString Dialog::getRanga(){
    return ui->comboBox->currentText();
}
QString Dialog::getNazwisko(){
    return ui->lineEdit_Nazwisko->text();
}
