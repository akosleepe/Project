#ifndef EDIT_USER_HPP
#define EDIT_USER_HPP

#include <QDialog>
#include "user.h"

namespace Ui {
class edit_user;
}

class edit_user : public QDialog
{
    Q_OBJECT

public:
    explicit edit_user(QWidget *parent = nullptr);
    ~edit_user();
    void setUser(user*);

public slots:
    void accept();
    void reject();
private:
    Ui::edit_user *ui;
    user* m_user;
};

#endif // EDIT_USER_HPP
