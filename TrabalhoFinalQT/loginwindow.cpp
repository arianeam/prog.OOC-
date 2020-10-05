#include "loginwindow.h"
#include "ui_loginwindow.h"

static int errosLogin = 0;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    if(!bd.abrir_bd()){
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

        if(user.logar(username,senha)>0){
            QMessageBox::information(this,"","Login efetuado com sucesso!");
            this->close();
            Mainwindow m(this,&bd, &user);
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

void LoginWindow:: enableloginBtn(){

    ui->loginBtn->setEnabled(true);
}


