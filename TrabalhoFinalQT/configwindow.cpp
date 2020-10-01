#include "configwindow.h"
#include "ui_configwindow.h"

configwindow::configwindow(QWidget *parent, login* l) :
    QDialog(parent),
    ui(new Ui::configwindow)
{
    Login = l;
    ui->setupUi(this);
}

configwindow::~configwindow()
{
    delete ui;
}

void configwindow::on_alterarSenhaBtn_clicked()
{
      QString senha = Login->get_senha();
      alterarSenha a;
      a.exec();
}
