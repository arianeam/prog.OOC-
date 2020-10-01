#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include "alterarsenha.h"

namespace Ui {
class configwindow;
}

class configwindow : public QDialog
{
    Q_OBJECT

public:
    explicit configwindow(QWidget *parent = nullptr);
    ~configwindow();

private slots:
    void on_alterarSenhaBtn_clicked();

private:
    Ui::configwindow *ui;
};

#endif // CONFIGWINDOW_H
