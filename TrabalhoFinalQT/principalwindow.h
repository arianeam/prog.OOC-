#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QDialog>

namespace Ui {
class principalwindow;
}

class principalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit principalwindow(QWidget *parent = nullptr);
    ~principalwindow();

private:
    Ui::principalwindow *ui;
};

#endif // PRINCIPALWINDOW_H
