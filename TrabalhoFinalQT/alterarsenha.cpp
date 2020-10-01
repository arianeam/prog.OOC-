#include "alterarsenha.h"
#include "ui_alterarsenha.h"

alterarSenha::alterarSenha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterarSenha)
{
    ui->setupUi(this);

    ui->novaSenhalineEdit->setDisabled(true);
    ui->confirmarlineEdit->setDisabled(true);
    connect(ui->senhaAtuallineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_senhaAtuallineEdit_textChanged(const QString &)));

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
            }
        }
    }
}
