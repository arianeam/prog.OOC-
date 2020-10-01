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

    connect(ui->senhaAtuallineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_senhaAtuallineEdit_textChanged(const QString &)));

    connect(ui->novaSenhalineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_novaSenhalineEdit_textChanged(const QString &)));

    connect(ui->confirmarlineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_confirmarlineEdit_textChanged(const QString &)));
}

alterarSenha::~alterarSenha()
{
    delete ui;
}


void alterarSenha::on_senhaAtuallineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QString senha = ui->senhaAtuallineEdit->text();

        QSqlQuery query;
        query.prepare("select * from tb_login where senha='"+senha+"'");

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
            ui->avisolabel_2->setText("A senha deve ter pelo menos 5 caracteres!");
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

        }
    }

}

void alterarSenha::on_cancelBtn_clicked()
{
    this->close();
}

void alterarSenha::on_saveBtn_clicked()
{
    QString nova_senha = ui->confirmarlineEdit->text();
    QString senha_antiga = ui->senhaAtuallineEdit->text();

    QSqlQuery query;

    query.prepare("update tb_login set senha='"+nova_senha+"' where senha='"+senha_antiga+"'");

    if(query.exec()){

        QMessageBox::information(this,"","Senha alterada com suceso!");
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao alterar senha!");

    }
}
