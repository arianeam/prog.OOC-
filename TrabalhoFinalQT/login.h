#ifndef LOGIN_H
#define LOGIN_H

#include <QString>


class login
{
public:
    login(){};
    QString senha;
    QString username;
    QString get_senha(){return senha;}
    QString get_username(){return username;}
    void set_senha(QString s) {senha = s;}
    void set_username(QString u) {username = u;}
};

#endif // LOGIN_H
