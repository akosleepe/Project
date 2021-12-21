#ifndef ROUTEHISTORY_H
#define ROUTEHISTORY_H

#include <QDialog>
#include <QStandardItemModel>
#include "route.h"
#include "user.h"

namespace Ui {
class routehistory;
}

class routehistory : public QDialog
{
    Q_OBJECT

public:
    explicit routehistory(QWidget *parent = nullptr);
    ~routehistory();
    void setRole(int);
    void setRoutes(std::vector<route>);
    void setIndex(int);
    void setUser(user);
    void addColumns();
    void addRowsForClient();
    void addRowsForManager();


private:
    Ui::routehistory *ui;
    QStandardItemModel *tbl;
    std::vector<route> m_routes;
    user m_user;
    int role = 0;
    int index = 0;
};

#endif // ROUTEHISTORY_H
