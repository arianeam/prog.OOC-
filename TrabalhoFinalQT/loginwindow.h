#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QFileInfo>
#include "mainwindow.h"
#include <QTimer>
#include <QMessageBox>
#include "Banco_de_dados.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE


class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    Banco_de_dados bd;

private slots:
    void on_loginBtn_clicked();
    void enableloginBtn();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
