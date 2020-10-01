#include "configwindow.h"
#include "ui_configwindow.h"

configwindow::configwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configwindow)
{
    ui->setupUi(this);
}

configwindow::~configwindow()
{
    delete ui;
}

void configwindow::on_alterarSenhaBtn_clicked()
{
      alterarSenha a;
      a.exec();
}
