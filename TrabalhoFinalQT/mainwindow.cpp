#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

Mainwindow::Mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);

}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::on_addBtn_clicked()
{
    addwindow a;
    a.setModal(true);
    a.exec();
}

void Mainwindow::on_listarBtn_clicked()
{
    QSqlQuery query;
    query.prepare("select * from tb_acervo");

    if(query.exec()){

        ui->tableWidget->clear();

        int linha = 0;
        ui->tableWidget->setColumnCount(7);

        while(query.next())
        {
            ui->tableWidget->insertRow(linha);
            ui->tableWidget->setItem(linha,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(linha,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(linha,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(linha,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(linha,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setRowHeight(linha,15);
            linha++;
        }

       QStringList cabecalho = {"Id", "Obra", "Autor", "Edição", "Quantidade", "Seção", "Prateleira"};
       ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
       ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
       ui->tableWidget->verticalHeader()->setVisible(false);

    }else{

        QMessageBox::warning(this,"ERRO","Erro ao listar acervo!");

    }
}

void Mainwindow::on_pesquisaBtn_clicked()
{
    QSqlQuery query;

    QString pesquisar = ui->pesquisarlineEdit->text();

    query.prepare("select * from tb_acervo where id like '%"+pesquisar+"%' or obra like '%"+pesquisar+"%' or autor like'%"+pesquisar+"%'"
                  "or edicao like'%"+pesquisar+"%' or quantidade like '%"+pesquisar+"%' or secao like '%"+pesquisar+"%' or prateleira like '%"+pesquisar+"%'");

    if(query.exec()){

        ui->tableWidget->clear();

        int linha = 0;
        ui->tableWidget->setColumnCount(7);

        while(query.next())
        {
            ui->tableWidget->insertRow(linha);
            ui->tableWidget->setItem(linha,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(linha,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(linha,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(linha,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(linha,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setRowHeight(linha,15);

            linha++;
        }

        QStringList cabecalho = {"Id", "Obra", "Autor", "Edição", "Quantidade", "Seção", "Prateleira"};
        ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->verticalHeader()->setVisible(false);

    }else{

        QMessageBox::warning(this,"ERRO","Erro ao efetuar pesquisa!");

    }
}

void Mainwindow::on_excluirBtn_clicked()
{

}
