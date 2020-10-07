#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

Mainwindow::Mainwindow(QWidget *parent, Banco_de_dados* b, Usuario* us) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{

    bd = b;
    user = us;
    ui->setupUi(this);

    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->excluirBtn->setDisabled(true);

    ui->tableWidget->setColumnCount(7);
    int linha = 0;

    if(livro.select_todos()){
        while(livro.Query.next()){

            insere_linha(linha);
            linha++;
        }
        formato_tabela();

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar banco de dados!");
    }
}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::on_addBtn_clicked()
{
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->excluirBtn->setDisabled(true);

    addwindow a(this, &livro);
    a.exec();

    ui->tableWidget->setRowCount(0);
    int linha = 0;

    if(livro.select_todos()){
        while(livro.Query.next()){

            ui->tableWidget->removeRow(linha);
            linha++;
        }

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }

    linha = 0;
    ui->editarBtn->setDisabled(true);

    ui->tableWidget->setColumnCount(7);

    if(livro.select_todos()){
        while(livro.Query.next()){

            insere_linha(linha);
            linha++;
        }
        formato_tabela();

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }

}

void Mainwindow::on_listarBtn_clicked()
{
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);
    ui->excluirBtn->setDisabled(true);

    ui->tableWidget->setRowCount(0);

    int linha = 0;
    QString id;

    if(livro.select_todos()){
        while(livro.Query.next()){

            ui->tableWidget->removeRow(linha);
            linha++;
        }
    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }

    linha = 0;

    ui->editarBtn->setDisabled(true);

    ui->tableWidget->setColumnCount(7);

    if(livro.select_todos()){
        while(livro.Query.next()){

            insere_linha(linha);
            linha++;
        }
        formato_tabela();

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }
}

void Mainwindow::on_pesquisaBtn_clicked()
{
    ui->excluirBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);

    ui->tableWidget->setRowCount(0);

    int linha = 0;

    if(livro.select_todos()){
        while(livro.Query.next()){

            ui->tableWidget->removeRow(linha);
            linha++;
        }
    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }

    linha = 0;

    QString pesquisar = ui->pesquisarlineEdit->text();

    if(livro.pesquisar_query(pesquisar)){

        ui->tableWidget->setColumnCount(7);
            while(livro.Query.next()){

                insere_linha(linha);
                linha++;
            }
            formato_tabela();

        }else{
            QMessageBox::warning(this,"ERRO","Erro ao listar item!");
        }

}

void Mainwindow::on_excluirBtn_clicked()
{
    ui->pesquisaBtn->setDisabled(true);
    ui->editarBtn->setDisabled(true);

    int linha= ui->tableWidget->currentRow();
    QString id= ui->tableWidget->item(linha,0)->text();

    QMessageBox::StandardButton ret = QMessageBox::question(this,"","Deseja excluir item?");

    if(ret==QMessageBox::Yes){

        if(livro.excluir_query(id)){

            ui->tableWidget->removeRow(linha);

            QMessageBox::information(this,"","Item excluído com sucesso!");

        }else{

            QMessageBox::warning(this,"ERRO","Erro ao excluir item!");
        }
    }
}

void Mainwindow::on_sairBtn_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::question(this,"","Deseja sair?");

    if(ret==QMessageBox::Yes){

        bd->fechar_bd();
        this->close();
    }
}

void Mainwindow::on_editarBtn_clicked()
{
    int linha= ui->tableWidget->currentRow();
    QString id= ui->tableWidget->item(linha,0)->text();
    editwindow e(this, id, &livro);
    e.exec();

    ui->tableWidget->setRowCount(0);
    linha = 0;

    if(livro.select_todos()){
        while(livro.Query.next()){

            ui->tableWidget->removeRow(linha);
            linha++;
        }

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar item!");
    }

    linha = 0;

    if(livro.select_todos()){
        while(livro.Query.next()){

            insere_linha(linha);
            linha++;
        }
        formato_tabela();

    }else{
        QMessageBox::warning(this,"ERRO","Erro ao listar banco de dados!");
    }
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

void Mainwindow::on_configBtn_clicked()
{
    configwindow c(this,user);
    c.exec();
}

void Mainwindow::insere_linha(int linha){

    ui->tableWidget->insertRow(linha);
    ui->tableWidget->setItem(linha,0,new QTableWidgetItem(livro.Query.value(0).toString()));
    ui->tableWidget->setItem(linha,1,new QTableWidgetItem(livro.Query.value(1).toString()));
    ui->tableWidget->setItem(linha,2,new QTableWidgetItem(livro.Query.value(2).toString()));
    ui->tableWidget->setItem(linha,3,new QTableWidgetItem(livro.Query.value(3).toString()));
    ui->tableWidget->setItem(linha,4,new QTableWidgetItem(livro.Query.value(4).toString()));
    ui->tableWidget->setItem(linha,5,new QTableWidgetItem(livro.Query.value(5).toString()));
    ui->tableWidget->setItem(linha,6,new QTableWidgetItem(livro.Query.value(6).toString()));
    ui->tableWidget->setRowHeight(linha,15);

}

void Mainwindow::formato_tabela(){

    QStringList cabecalho = {"Id", "Obra", "Autor", "Edição", "Quantidade", "Seção", "Prateleira"};
    ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnWidth(0,30);
    ui->tableWidget->setColumnWidth(1,400);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(5,100);
    ui->tableWidget->setColumnWidth(5,100);

}
