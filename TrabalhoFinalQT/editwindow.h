#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class editwindow;
}

class editwindow : public QDialog
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr, QString id = NULL);
    ~editwindow();

private:
    Ui::editwindow *ui;
};

#endif // EDITWINDOW_H
