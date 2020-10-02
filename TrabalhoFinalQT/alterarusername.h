#ifndef ALTERARUSERNAME_H
#define ALTERARUSERNAME_H

#include <QDialog>
#include "loginwindow.h"

namespace Ui {
class alterarusername;
}

class alterarusername : public QDialog
{
    Q_OBJECT

public:
    explicit alterarusername(QWidget *parent = nullptr);
    ~alterarusername();

private slots:

    void on_Senha_lineEdit_textChanged(const QString &arg1);

    void on_novouser_lineEdit_textChanged(const QString &arg1);

    void on_confirmaruser_lineEdit_textChanged(const QString &arg1);

    void on_SaveBtn_clicked();

    void on_useratual_lineEdit_textChanged(const QString &arg1);

private:
    Ui::alterarusername *ui;
};

#endif // ALTERARUSERNAME_H
