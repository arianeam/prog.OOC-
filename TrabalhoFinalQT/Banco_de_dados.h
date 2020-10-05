#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H
#include <QtSql>

class Banco_de_dados{

public:
    QSqlDatabase bd_acervo;

    Banco_de_dados(){

        bd_acervo = QSqlDatabase::addDatabase("QSQLITE");
    }

    void fechar_bd(){

        bd_acervo.close();
    }

    bool abrir_bd(){

        QString local = qApp->applicationDirPath();
        QString bd = local + "/acervo.db";
        bd_acervo.setDatabaseName(bd);

        if(bd_acervo.open())
        {
            return true;

        }else{
            return false;
        }
    }

    bool bd_status(){
        if(!bd_acervo.isOpen()){

            return false;

        }else{

            return true;
        }
    }
};

#endif // BANCO_DE_DADOS_H
