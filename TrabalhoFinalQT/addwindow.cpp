#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addwindow)
{
    ui->setupUi(this);
}

addwindow::~addwindow()
{
    delete ui;
}

void addwindow::on_addbuttonBox_accepted()
{

}
