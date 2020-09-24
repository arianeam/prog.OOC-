#include "editwindow.h"
#include "ui_editwindow.h"

editwindow::editwindow(QWidget *parent, QString id) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
}

editwindow::~editwindow()
{
    delete ui;
}
