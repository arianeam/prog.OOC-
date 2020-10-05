#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include "alterarsenha.h"
#include "alterarusername.h"
#include "Banco_de_dados.h"
#include "Usuario.h"

namespace Ui {
class configwindow;
}

class configwindow : public QDialog
{
    Q_OBJECT

public:
    explicit configwindow(QWidget *parent = nullptr, Usuario* us = NULL);
    ~configwindow();

    Usuario* user;

private slots:
    void on_alterarSenhaBtn_clicked();

    void on_alterarUsernameBtn_clicked();

private:
    Ui::configwindow *ui;

};

#endif // CONFIGWINDOW_H
