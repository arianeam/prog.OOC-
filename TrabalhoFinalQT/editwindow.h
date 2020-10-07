#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QVector>
#include "Livro.h"


namespace Ui {
class editwindow;
}

class editwindow : public QDialog
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr, QString id = NULL, Livro* l = NULL);
    ~editwindow();

    Livro* livro;
    QString id_acervo;

private slots:
    void on_GravarBtn_clicked();

    void on_ObraLineEdit_textChanged(const QString &arg1);

private:
    Ui::editwindow *ui;
};

#endif // EDITWINDOW_H
