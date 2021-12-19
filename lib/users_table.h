#ifndef USERS_TABLE_H
#define USERS_TABLE_H

#include <QWidget>

namespace Ui {
class users_table;
}

class users_table : public QWidget
{
    Q_OBJECT

public:
    explicit users_table(QWidget *parent = nullptr);
    ~users_table();

private:
    Ui::users_table *ui;
};

#endif // USERS_TABLE_H
