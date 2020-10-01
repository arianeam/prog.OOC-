#include "alterarsenha.h"
#include "ui_alterarsenha.h"

alterarSenha::alterarSenha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterarSenha)
{
    ui->setupUi(this);

    ui->novaSenhalineEdit->setDisabled(true);
    ui->confirmarlineEdit->setDisabled(true);


}

alterarSenha::~alterarSenha()
{
    delete ui;
}


