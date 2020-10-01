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

    void on_senhaAtuallineEdit_textChanged(const QString &arg1);

private:
    Ui::alterarSenha *ui;
};

#endif // ALTERARSENHA_H