#include "alterarsenha.h"
#include "ui_alterarsenha.h"

alterarSenha::alterarSenha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterarSenha)
{
    ui->setupUi(this);

    ui->novaSenhalineEdit->setDisabled(true);
    ui->confirmarlineEdit->setDisabled(true);


   /* if(senha_atual==senha)
    {
        ui->novaSenhalineEdit->setEnabled(true);

    }else{

        ui->avisolabel->setText("Senha incorreta!");
    }*/

}

alterarSenha::~alterarSenha()
{
    delete ui;
}




