#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QSqlDatabase bd_acervo = QSqlDatabase::addDatabase("QSQLITE");
    bd_acervo.setDatabaseName("C:/Users/PICHAU/Documents/programas_QT/acervo_livros/acervo.db");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

