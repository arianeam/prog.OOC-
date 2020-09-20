#include "principalwindow.h"
#include "ui_principalwindow.h"

principalwindow::principalwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::principalwindow)
{
    ui->setupUi(this);
}

principalwindow::~principalwindow()
{
    delete ui;
}
