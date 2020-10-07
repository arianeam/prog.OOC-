#ifndef LIVRO_H
#define LIVRO_H
#include <QString>
#include <QVector>
#include <QtSql>

class Livro{

public:
    QString obra;
    QString autor;
    QString edicao;
    QString quantidade;
    QString secao;
    QString prateleira;
    QString Id;    
    QSqlQuery Query;

    bool insert_livro(){

        Query.prepare("insert into tb_acervo (obra,autor,edicao,quantidade,secao,prateleira) values"
                      "('"+obra+"','"+autor+"','"+edicao+"','"+QString::number(quantidade.toInt())+"','"+secao+"','"+prateleira+"')");

        if(Query.exec()){
            return true;
        }else{

            return false;
        }
    }

    bool update_livro(QString id){

        Query.prepare("update tb_acervo set obra='"+obra+"',autor='"+autor+"',"
       "edicao='"+edicao+"',quantidade='"+QString::number(quantidade.toInt())+"',secao='"+secao+"', prateleira='"+prateleira+"'"
       "where id='"+id+"'");

        if(Query.exec()){
            return true;
        }else{

            return false;
        }

    }

    bool select_livro(QString id){

        Query.prepare("select * from tb_acervo where id='"+QString::number(id.toInt())+"'");

        if(Query.exec()){

            Query.next();
            obra = Query.value(1).toString();
            autor = Query.value(2).toString();
            edicao = Query.value(3).toString();
            quantidade = Query.value(4).toString();
            secao = Query.value(5).toString();
            prateleira = Query.value(6).toString();

            return true;

        }else{

            return false;
        }
    }


    bool pesquisar_query(QString pesquisar){

        Query.prepare("select * from tb_acervo where id like '%"+pesquisar+"%' or obra like '%"+pesquisar+"%' or autor like'%"+pesquisar+"%'"
                     "or edicao like'%"+pesquisar+"%' or quantidade like '%"+pesquisar+"%' or secao like '%"+pesquisar+"%' or prateleira like '%"+pesquisar+"%'");

        if(Query.exec()){

            return true;

        }else{
            return false;
        }
    }

    bool excluir_query(QString id){

        Query.prepare("delete from tb_acervo where id='"+QString::number(id.toInt())+"'");

        if(Query.exec()){

            return true;
        }else{

            return false;
        }
    }


    bool select_todos(){

        Query.prepare("select * from tb_acervo");
        if(Query.exec()){
            return true;
        }else{

            return false;
        }
    }

};

#endif // LIVRO_H
