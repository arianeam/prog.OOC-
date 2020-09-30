#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

Mainwindow::Mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);

    ui->pesquisaBtn->setDisabled(true);
    connect(ui->pesquisarlineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_pesquisarlineEdit_textChanged(const QString &)));

    ui->editarBtn->setDisabled(true);
    connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem *item)),
            this, SLOT(on_tableWidget_itemClicked(QTableWidgetItem *item)));

    ui->excluirBtn->setDisabled(true);
    connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem *item)),
            this, SLOT(on_tableWidget_itemClicked(QTableWidgetItem *item)));

    int linha = 0;
    QSqlQuery query;

    query.prepare("select * from tb_acervo");

    if(query.exec()){

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

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::on_addBtn_clicked()
{
    int linha = ui->tableWidget->rowCount();
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->excluirBtn->setDisabled(true);

    addwindow a;
    a.setModal(true);
    a.exec();

    QSqlQuery query;

    query.prepare("select * from tb_acervo");

    if(query.exec()){
        while(query.next()){

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
    }


}

void Mainwindow::on_listarBtn_clicked()
{
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->excluirBtn->setDisabled(true);
    int linha = 0;
    QSqlQuery query;

    query.prepare("select * from tb_acervo");
    ui->tableWidget->setRowCount(0);

    if(query.exec()){

        while(query.next())
        {
            ui->tableWidget->removeRow(linha);
            linha++;
        }
    }

    linha=0;
    if(query.exec()){

        ui->editarBtn->setDisabled(true);

        ui->tableWidget->clear();

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
    ui->excluirBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    int linha = 0;
    QSqlQuery query;

    query.prepare("select * from tb_acervo");
    ui->tableWidget->setRowCount(0);

    if(query.exec()){

        while(query.next())
        {
            ui->tableWidget->removeRow(linha);
            linha++;
        }
    }

    QString pesquisar = ui->pesquisarlineEdit->text();

    query.prepare("select * from tb_acervo where id like '%"+pesquisar+"%' or obra like '%"+pesquisar+"%' or autor like'%"+pesquisar+"%'"
                                                                                                                                     "or edicao like'%"+pesquisar+"%' or quantidade like '%"+QString::number(pesquisar.toInt())+"%' or secao like '%"+pesquisar+"%' or prateleira like '%"+pesquisar+"%'");

    if(query.exec()){

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
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    int linha= ui->tableWidget->currentRow();
    QString id= ui->tableWidget->item(linha,0)->text();
    QSqlQuery query;
    query.prepare("delete from tb_acervo where id='"+id+"'");

    QMessageBox::StandardButton ret = QMessageBox::question(this,"","Deseja excluir item:");


    if(ret==QMessageBox::Yes){
    if(query.exec()){

        ui->tableWidget->removeRow(linha);

        QMessageBox::information(this,"","Item excluído com sucesso!");

    }else{

        QMessageBox::warning(this,"ERRO","Erro ao excluir item!");
    }
    }

}

void Mainwindow::on_sairBtn_clicked()
{
    this->close();
}

void Mainwindow::on_editarBtn_clicked()
{
    int linha= ui->tableWidget->currentRow();
    QString id= ui->tableWidget->item(linha,0)->text();
    editwindow e(this, id);
    e.exec();

}

void Mainwindow::on_pesquisarlineEdit_textChanged(const QString &arg1)
{
    ui->excluirBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->pesquisaBtn->setEnabled(!arg1.isEmpty());
}

void Mainwindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->editarBtn->setEnabled(item->isSelected());
    ui->excluirBtn->setEnabled(item->isSelected());
}
