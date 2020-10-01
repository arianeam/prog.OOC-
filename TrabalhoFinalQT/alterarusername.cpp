#include "alterarusername.h"
#include "ui_alterarusername.h"

alterarusername::alterarusername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterarusername)
{
    ui->setupUi(this);

    ui->novouser_lineEdit->setDisabled(true);
    ui->confirmaruser_lineEdit->setDisabled(true);
    ui->SaveBtn->setDisabled(true);
    ui->Senha_lineEdit->setDisabled(true);
    ui->aviso3_label->setText("Insira o nome de usuário atual e a senha");

    connect(ui->Senha_lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_Senha_lineEdit_textChanged(const QString &)));

    connect(ui->novouser_lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_novouser_lineEdit_textChanged(const QString &)));

    connect(ui->confirmaruser_lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_confirmaruser_lineEdit_textChanged(const QString &)));

    connect(ui->useratual_lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_useratual_lineEdit_textChanged(const QString &)));

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

        QSqlQuery query;
        query.prepare("select * from tb_login where senha='"+senha+"' and login='"+username+"'");

        if(query.exec()){

            int cont = 0;

            while(query.next())
            {
                cont++;
            }

            if(cont>0){
                ui->novouser_lineEdit->setEnabled(true);
                ui->aviso4_label->setText("Insira o novo nome de usuário");
            }else{

                ui->novouser_lineEdit->setDisabled(true);
                ui->aviso4_label->setText("Senha incorreta!");
                ui->SaveBtn->setDisabled(true);
            }
        }
    }
}

void alterarusername::on_novouser_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString novo_username = ui->novouser_lineEdit->text();

        if(novo_username.size()>=3){

            ui->confirmaruser_lineEdit->setEnabled(true);
            ui->aviso5_label->setText("Confirme o novo nome de usuário");
        }else{

            ui->confirmaruser_lineEdit->setDisabled(true);
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

void alterarusername::on_CancelBtn_clicked()
{
    this->close();
}

void alterarusername::on_SaveBtn_clicked()
{
    QString novo_username = ui->confirmaruser_lineEdit->text();
    QString username_antigo = ui->useratual_lineEdit->text();
    QString senha = ui->Senha_lineEdit->text();

    QSqlQuery query;

    query.prepare("update tb_login set login='"+novo_username+"' where login='"+username_antigo+"' and senha='"+senha+"'");

    if(query.exec()){

        QMessageBox::information(this,"","Nome de usuário alterado com suceso!");
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao alterar nome de usuário!");

    }
}

void alterarusername::on_useratual_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){

        QString username = ui->useratual_lineEdit->text();

        QSqlQuery query;
        query.prepare("select * from tb_login where login='"+username+"'");

        if(query.exec()){

            int cont = 0;

            while(query.next())
            {
                cont++;
            }

            if(cont>0){

                ui->Senha_lineEdit->setEnabled(true);
                ui->aviso3_label->setText("Insira a senha");

             }else{

                ui->aviso3_label->setText("Nome de usuário inválido");
                ui->SaveBtn->setDisabled(true);
                ui->Senha_lineEdit->clear();
                ui->novouser_lineEdit->clear();
                ui->confirmaruser_lineEdit->clear();
                cont = 0;
            }
        }
    }
}
