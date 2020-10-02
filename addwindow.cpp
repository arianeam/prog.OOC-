#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addwindow)
{
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
    QString obra = ui->obralineEdit->text();
    QString autor = ui->autorlineEdit->text();
    QString edicao = ui->edicaolineEdit->text();
    QString quantidade = ui->qntdlineEdit->text();
    QString secao = ui->secaolineEdit->text();
    QString prateleira = ui->prateleiralineEdit->text();

    QSqlQuery query;

    query.prepare("insert into tb_acervo (obra,autor,edicao,quantidade,secao,prateleira) values"
                  "('"+obra+"','"+autor+"','"+edicao+"','"+QString::number(quantidade.toInt())+"','"+secao+"','"+prateleira+"')");

    if(query.exec()){
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


