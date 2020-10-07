#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "loginwindow.h"
#include <QVector>
#include <Livro.h>

namespace Ui {
class addwindow;
}

class addwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addwindow(QWidget *parent = nullptr, Livro* l = NULL);
    ~addwindow();
    Livro* livro;

private slots:

    void on_gravarBtn_clicked();

    void on_obralineEdit_textChanged(const QString &arg1);

private:
    Ui::addwindow *ui;
};

#endif // ADDWINDOW_H
