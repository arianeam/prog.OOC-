#include "editwindow.h"
#include "ui_editwindow.h"

static QString id_acervo;

editwindow::editwindow(QWidget *parent, QString id) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    id_acervo = id;

    QSqlQuery query;
    query.prepare("select * from tb_acervo where id='"+id+"'");

    if(query.exec()){
        query.first();
        ui->idtxt->setText(id);
        ui->ObraLineEdit->setText(query.value(1).toString());
        ui->AutorLineEdit->setText(query.value(2).toString());
        ui->EdLineEdit->setText(query.value(3).toString());
        ui->QntdLineEdit->setText(query.value(4).toString());
        ui->SecaoLineEdit->setText(query.value(5).toString());
        ui->PratLineEdit->setText(query.value(6).toString());
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao editar item!");

    }
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::on_GravarBtn_clicked()
{
    QString obra = ui->ObraLineEdit->text();
    QString autor = ui->AutorLineEdit->text();
    QString edicao = ui->EdLineEdit->text();
    QString quantidade = ui->QntdLineEdit->text();
    QString secao = ui->SecaoLineEdit->text();
    QString prateleira = ui->PratLineEdit->text();

    QSqlQuery query;
    query.prepare("update tb_acervo set obra='"+obra+"',autor='"+autor+"',"
                  "edicao='"+edicao+"',quantidade='"+quantidade+"',secao='"+secao+"', prateleira='"+prateleira+"'"
                   "where id='"+id_acervo+"'");

    if(query.exec()){

        QMessageBox::information(this,"","Item gravado com sucesso!");
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao gravar item!");
    }
}
