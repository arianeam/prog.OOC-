#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

#include <QDialog>
#include "loginwindow.h"

namespace Ui {
class alterarSenha;
}

class alterarSenha : public QDialog
{
    Q_OBJECT

public:
    explicit alterarSenha(QWidget *parent = nullptr);
    ~alterarSenha();

private slots:

private:
    Ui::alterarSenha *ui;
};

#endif // ALTERARSENHA_H
