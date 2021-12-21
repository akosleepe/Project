#ifndef ROUTE_TABLE_H
#define ROUTE_TABLE_H

#include <QDialog>
#include <QStandardItemModel>
#include "route.h"
#include "user.h"

namespace Ui {
class route_table;
}

class route_table : public QDialog
{
    Q_OBJECT

public:
    explicit route_table(QWidget *parent = nullptr);
    ~route_table();
    void setRoutes(std::vector<route>*);
    void setUsers(std::vector<user>*);
    void addColumns();
    void addRows();
    void setIndex(int);
    void checkRole(int);
    void setUser(user);
    bool checkStatus(route*);
private slots:

    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

    void on_takeButton_clicked();

private:
    Ui::route_table *ui;
    std::vector<route>* m_routes;
    std::vector<user> m_users;
    QStandardItemModel *tblr;
    user m_user;
};

#endif // ROUTE_TABLE_H
