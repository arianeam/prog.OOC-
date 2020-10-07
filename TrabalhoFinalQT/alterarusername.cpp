#include "alterarusername.h"
#include "ui_alterarusername.h"

alterarusername::alterarusername(QWidget *parent, Usuario* us) :
    QDialog(parent),
    ui(new Ui::alterarusername)
{
    user = us;

    ui->setupUi(this);

    ui->SaveBtn->setDisabled(true);

    ui->aviso3_label->setText("Insira o nome de usuário atual e a senha");

    connect(ui->CancelBtn,SIGNAL(clicked()),this,SLOT(close()));

}

alterarusername::~alterarusername()
{
    delete ui;
}

void alterarusername::on_Senha_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString senha = ui->Senha_lineEdit->text();
        QString username = ui->useratual_lineEdit->text();

        if(user->logar(username,senha)>0){

            ui->aviso4_label->setText("Insira o novo nome de usuário");

        }else{

            ui->aviso4_label->setText("Senha incorreta!");
            ui->SaveBtn->setDisabled(true);
        }
    }

}

void alterarusername::on_novouser_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString novo_username = ui->novouser_lineEdit->text();

        if(novo_username.size()>=3){

            ui->aviso5_label->setText("Confirme o novo nome de usuário");

        }else{

            ui->aviso5_label->setText("O nome de usuário deve conter pelo menos 3 caractres!");
            ui->SaveBtn->setDisabled(true);
        }
    }
}


void alterarusername::on_confirmaruser_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString confirmar_username = ui->confirmaruser_lineEdit->text();
        QString novo_username = ui->novouser_lineEdit->text();

        if(confirmar_username==novo_username){

            ui->SaveBtn->setEnabled(true);
            ui->aviso6_label->setText("Salve as alterações");

        }else{

            ui->SaveBtn->setDisabled(true);
        }
    }
}

void alterarusername::on_SaveBtn_clicked()
{
    QString novo_username = ui->confirmaruser_lineEdit->text();
    QString username_antigo = ui->useratual_lineEdit->text();
    QString senha = ui->Senha_lineEdit->text();

    QSqlQuery query;

    if(user->logar(username_antigo,senha)>0){

        if(user->update_username(novo_username)){

            QMessageBox::information(this,"","Nome de usuário alterado com sucesso!");
            ui->useratual_lineEdit->clear();
            ui->Senha_lineEdit->clear();
            ui->novouser_lineEdit->clear();
            ui->confirmaruser_lineEdit->clear();
            ui->useratual_lineEdit->setFocus();

        }else{

            QMessageBox::warning(this,"ERRO","Erro ao alterar nome de usuário!");

            ui->SaveBtn->setDisabled(true);
            ui->useratual_lineEdit->clear();
            ui->Senha_lineEdit->clear();
            ui->novouser_lineEdit->clear();
            ui->confirmaruser_lineEdit->clear();
            ui->useratual_lineEdit->setFocus();

        }
    }else{
        ui->SaveBtn->setDisabled(true);
        QMessageBox::warning(this,"","Login inválido!");
        ui->useratual_lineEdit->clear();
        ui->Senha_lineEdit->clear();
        ui->novouser_lineEdit->clear();
        ui->confirmaruser_lineEdit->clear();
        ui->useratual_lineEdit->setFocus();
    }

}

void alterarusername::on_useratual_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString username = ui->useratual_lineEdit->text();

        if(user->select_username(username)>0){

            ui->Senha_lineEdit->setEnabled(true);
            ui->aviso3_label->setText("Insira a senha");

        }else{

            ui->aviso3_label->setText("Nome de usuário inválido");
            ui->SaveBtn->setDisabled(true);
            ui->Senha_lineEdit->clear();
            ui->novouser_lineEdit->clear();
            ui->confirmaruser_lineEdit->clear();
        }
    }
}
