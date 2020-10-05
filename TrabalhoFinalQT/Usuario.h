#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include <Banco_de_dados.h>

class Usuario{

public:

    QString username;
    QString senha;

    int logar(QString u, QString s){
        QSqlQuery query;
        query.prepare("select * from tb_login where login='"+u+"' and senha='"+s+"'");

        if(query.exec()){

            int cont = 0;

            while(query.next())
            {
                cont++;
            }
            username = u;
            senha = s;
            return cont;
        }else{

            return 0;
        }
}

   bool update_senha (QString novo){

           QSqlQuery query;
           query.prepare("update tb_login set senha='"+novo+"' where senha='"+Usuario::senha+"' and login='"+Usuario::username+"'");

           if(query.exec()){
            return true;
           }else{
               return false;
           }

    }


   bool update_username (QString novo){

           QSqlQuery query;
           query.prepare("update tb_login set login='"+novo+"' where senha='"+Usuario::senha+"' and login='"+Usuario::username+"'");

           if(query.exec()){
            return true;
           }else{
               return false;
           }

    }

};

#endif // USUARIO_H
