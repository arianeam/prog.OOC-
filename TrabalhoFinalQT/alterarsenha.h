#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

#include <QDialog>

namespace Ui {
class alterarSenha;
}

class alterarSenha : public QDialog
{
    Q_OBJECT

public:
    explicit alterarSenha(QWidget *parent = nullptr);
    ~alterarSenha();

private:
    Ui::alterarSenha *ui;
};

#endif // ALTERARSENHA_H
