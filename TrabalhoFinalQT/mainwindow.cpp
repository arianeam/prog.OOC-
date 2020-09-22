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

