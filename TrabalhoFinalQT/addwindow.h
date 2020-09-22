#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <loginwindow.h>

namespace Ui {
class addwindow;
}

class addwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addwindow(QWidget *parent = nullptr);
    ~addwindow();

private slots:

    void on_gravarBtn_clicked();

private:
    Ui::addwindow *ui;
};

#endif // ADDWINDOW_H
