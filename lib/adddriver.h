#ifndef ADDDRIVER_H
#define ADDDRIVER_H

#include <QDialog>

#include "user.h"

namespace Ui {
class adddriver;
}

class adddriver : public QDialog
{
    Q_OBJECT

public:
    explicit adddriver(QWidget *parent = nullptr);
    ~adddriver();
    void setName(QString);
    void setLogin(QString);
    void setPassword(QString);
    void setNumber(QString);
    void setDriverExp(QString);
    void setUser(user*);

public slots:
    void accept();
    void reject();

private:
    user *m_user;
    Ui::adddriver *ui;
};

#endif // ADDDRIVER_H
