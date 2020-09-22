#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <configwindow.h>
#include <addwindow.h>

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();

private slots:

    void on_addBtn_clicked();

private:
    Ui::Mainwindow *ui;
};

#endif // MAINWINDOW_H
