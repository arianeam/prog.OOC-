#include "editwindow.h"
#include "ui_editwindow.h"

editwindow::editwindow(QWidget *parent, QString id, Livro* l) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    livro = l;

    ui->setupUi(this);

    ui->GravarBtn->setDisabled(true);

    id_acervo = id;

    if(livro->select_livro(id)){

        ui->idtxt->setText(id);
        ui->ObraLineEdit->setText(livro->obra);
        ui->AutorLineEdit->setText(livro->autor);
        ui->EdLineEdit->setText(livro->edicao);
        ui->QntdLineEdit->setText(livro->quantidade);
        ui->SecaoLineEdit->setText(livro->secao);
        ui->PratLineEdit->setText(livro->prateleira);

    }else{

        QMessageBox::warning(this,"ERRO","Erro ao editar item!");

    }

    connect(ui->CancelarBtn,SIGNAL(clicked()),this,SLOT(close()));
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::on_GravarBtn_clicked()
{
    livro->obra = ui->ObraLineEdit->text();
    livro->autor = ui->AutorLineEdit->text();
    livro->edicao = ui->EdLineEdit->text();
    livro->quantidade = ui->QntdLineEdit->text();
    livro->secao = ui->SecaoLineEdit->text();
    livro->prateleira = ui->PratLineEdit->text();

    if(livro->update_livro(id_acervo)){

        QMessageBox::information(this,"","Item gravado com sucesso!");
    }else{

        QMessageBox::warning(this,"ERRO","Erro ao gravar item!");
    }
}

void editwindow::on_ObraLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){

        ui->GravarBtn->setDisabled(true);
        ui->obra_label->setText("Campo obrigatório!");
    }else{

        ui->GravarBtn->setEnabled(true);
    }
}
