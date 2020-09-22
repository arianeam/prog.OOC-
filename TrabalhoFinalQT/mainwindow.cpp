#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <configwindow.h>

Mainwindow::Mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::on_addBtn_clicked()
{
    addwindow a;
    a.setModal(true);
    a.exec();
}
