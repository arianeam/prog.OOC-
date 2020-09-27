#include "loginwindow.h"
#include "ui_loginwindow.h"

static int errosLogin = 0;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    QString local = qApp->applicationDirPath();
    QString bd = local + "/acervo.db";
    bd_acervo.setDatabaseName(bd);

   // bd_acervo.setDatabaseName("C:/Users/PICHAU/Documents/programas_QT/acervo_livros/acervo.db");

    if(!bd_acervo.open())
    {
        QMessageBox::warning(this,"ERRO","Erro ao abrir banco de dados!");

    }

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginBtn_clicked()
{
    QString username = ui->loginlineEdit->text();
    QString senha = ui->senhalineEdit->text();

    if(!bd_acervo.isOpen()){
        QMessageBox::warning(this,"ERRO","Erro ao abrir banco de dados!");
        return;
    }

    QSqlQuery query;
    query.prepare("select * from tb_login where login='"+username+"' and senha='"+senha+"'");

    if(query.exec()){

        int cont = 0;

        while(query.next())
        {
            cont++;
        }

        if(cont>0){
            QMessageBox::information(this,"","Login efetuado com sucesso!");
            this->close();
            Mainwindow m;
            m.setModal(true);
            m.exec();
        }else{
            errosLogin++;
            QMessageBox::information(this,"","Login inválido!");
            ui->senhalineEdit->clear();
            ui->loginlineEdit->clear();
            ui->loginlineEdit->setFocus();
            if(errosLogin==5)
            {
                ui->statuslabel->setText("5 erros consecutivos! Aguarde 5 min! ");
                ui->loginBtn->setDisabled(true);
                QTimer::singleShot(300000,this, SLOT(enableloginBtn()));
                errosLogin = 0;

            }

        }

    }

}

void LoginWindow:: enableloginBtn(){

    ui->loginBtn->setEnabled(true);
}


