#ifndef ADDDRIVER_H
#define ADDDRIVER_H

#include <QDialog>

namespace Ui {
class adddriver;
}

class adddriver : public QDialog
{
    Q_OBJECT

public:
    explicit adddriver(QWidget *parent = nullptr);
    ~adddriver();

private:
    Ui::adddriver *ui;
};

#endif // ADDDRIVER_H
