#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(QWidget *parent, Livro* l) :
    QDialog(parent),
    ui(new Ui::addwindow)
{
    livro = l;
    ui->setupUi(this);

    ui->gravarBtn->setDisabled(true);

    connect(ui->cancelarBtn,SIGNAL(clicked()),this,SLOT(close()));
}

addwindow::~addwindow()
{
    delete ui;
}


void addwindow::on_gravarBtn_clicked()
{

     livro->obra = ui->obralineEdit->text();
     livro->autor = ui->autorlineEdit->text();
     livro->edicao = ui->edicaolineEdit->text();
     livro->quantidade = ui->qntdlineEdit->text();
     livro->secao = ui->secaolineEdit->text();
     livro->prateleira = ui->prateleiralineEdit->text();


    if(livro->insert_livro()){
        QMessageBox::information(this,"","Dados inseridos com sucesso!");

        ui->obralineEdit->clear();
        ui->autorlineEdit->clear();
        ui->edicaolineEdit->clear();
        ui->qntdlineEdit->clear();
        ui->secaolineEdit->clear();
        ui->prateleiralineEdit->clear();
        ui->obralineEdit->setFocus();


    }else{

        QMessageBox::warning(this,"ERRO","Erro ao inserir dados!");

    }

}


void addwindow::on_obralineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){

        ui->gravarBtn->setDisabled(true);
        ui->obralabel_2->setText("Campo obrigatório!");

    }else{

        ui->gravarBtn->setEnabled(true);
    }


}


