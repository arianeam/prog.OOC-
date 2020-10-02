#include "alterarsenha.h"
#include "ui_alterarsenha.h"

alterarSenha::alterarSenha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterarSenha)
{
    ui->setupUi(this);

    ui->novaSenhalineEdit->setDisabled(true);
    ui->confirmarlineEdit->setDisabled(true);
    ui->saveBtn->setDisabled(true);
    ui->senhaAtuallineEdit->setDisabled(true);
    ui->aviso7_label->setText("Insira o nome de usuário e senha atual");

    connect(ui->cancelBtn,SIGNAL(clicked()),this,SLOT(close()));
}

alterarSenha::~alterarSenha()
{
    delete ui;
}


void alterarSenha::on_senhaAtuallineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QString senha = ui->senhaAtuallineEdit->text();
        QString username = ui->usernamelineEdit->text();

        QSqlQuery query;
        query.prepare("select * from tb_login where senha='"+senha+"' and login='"+username+"'");

        if(query.exec()){

            int cont = 0;

            while(query.next())
            {
                cont++;
            }

            if(cont>0){
                ui->novaSenhalineEdit->setEnabled(true);
                ui->avisolabel->setText("Insira nova senha");
            }else{

                ui->novaSenhalineEdit->setDisabled(true);
                ui->avisolabel->setText("Senha incorreta!");
                ui->saveBtn->setDisabled(true);
            }
        }
    }
}

void alterarSenha::on_novaSenhalineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString nova_senha = ui->novaSenhalineEdit->text();

        if(nova_senha.size()>=5){
            ui->confirmarlineEdit->setEnabled(true);
            ui->avisolabel_2->setText("Confirme a nova senha");
        }else{

            ui->confirmarlineEdit->setDisabled(true);
            ui->avisolabel_2->setText("A senha deve conter pelo menos 5 caracteres!");
            ui->saveBtn->setDisabled(true);
        }
    }
}


void alterarSenha::on_confirmarlineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString nova_senha = ui->novaSenhalineEdit->text();
        QString confirmar_senha = ui->confirmarlineEdit->text();

        if(confirmar_senha==nova_senha){

            ui->avisolabel_2->setText("Salve as alterações!");
            ui->saveBtn->setEnabled(true);

        }else{

            ui->avisolabel_2->setText("Confirme a nova senha!");
            ui->saveBtn->setDisabled(true);
            ui->saveBtn->setDisabled(true);

        }
    }

}


void alterarSenha::on_saveBtn_clicked()
{
    QString nova_senha = ui->confirmarlineEdit->text();
    QString senha_antiga = ui->senhaAtuallineEdit->text();
    QString username = ui->usernamelineEdit->text();

    QSqlQuery query;

    query.prepare("update tb_login set senha='"+nova_senha+"' where senha='"+senha_antiga+"' and login='"+username+"'");

    if(query.exec()){

        QMessageBox::information(this,"","Senha alterada com suceso!");
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao alterar senha!");

    }
}

void alterarSenha::on_usernamelineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString username = ui->usernamelineEdit->text();

        QSqlQuery query;
        query.prepare("select * from tb_login where login='"+username+"'");

        if(query.exec()){

            int cont = 0;

            while(query.next())
            {
                cont++;
            }

            if(cont>0){

                ui->senhaAtuallineEdit->setEnabled(true);
                ui->aviso7_label->setText("Insira a senha");


             }else{

                ui->aviso7_label->setText("Nome de usuário inválido");
                ui->saveBtn->setDisabled(true);
                ui->senhaAtuallineEdit->clear();
                ui->novaSenhalineEdit->clear();
                ui->confirmarlineEdit->clear();
                cont = 0;
            }
        }
    }
}
