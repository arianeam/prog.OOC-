#include "loginwindow.h"
#include "ui_loginwindow.h"

 static QSqlDatabase bd_acervo = QSqlDatabase::addDatabase("QSQLITE");

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    bd_acervo.setDatabaseName("C:/Users/PICHAU/Documents/programas_QT/acervo_livros/acervo.db");

    if(!bd_acervo.open())
    {

      ui->statuslabel->setText("Erro ao abrir o banco de dados!");

    }else{
         ui->statuslabel->setText("Banco de dados aberto com sucesso!");
    }

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{
    QString username = ui->loginlineEdit->text();
    QString senha = ui->senhalineEdit->text();

    if(!bd_acervo.isOpen()){
        qDebug()<<"Banco de dados não foi aberto!";
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from tb_login where login='"+username+"' and senha='"+senha+"'")){

        int cont = 0;
        while(query.next())
        {
            cont++;
        }

        if(cont>0){
            this->close();
            principalwindow p;
            p.setModal(true);
            p.exec();
        }else{
            ui->statuslabel->setText("Login inválido!");
            ui->senhalineEdit->clear();
            ui->loginlineEdit->clear();
            ui->loginlineEdit->setFocus();
        }
    }
}
