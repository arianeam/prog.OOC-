#include "configwindow.h"
#include "ui_configwindow.h"

configwindow::configwindow(QWidget *parent, Usuario* us) :
    QDialog(parent),
    ui(new Ui::configwindow)
{
    user = us;
    ui->setupUi(this);
}

configwindow::~configwindow()
{
    delete ui;
}

void configwindow::on_alterarSenhaBtn_clicked()
{
    alterarSenha a(this, user);
    a.exec();
}

void configwindow::on_alterarUsernameBtn_clicked()
{
    alterarusername a(this,user);
    a.exec();
}
