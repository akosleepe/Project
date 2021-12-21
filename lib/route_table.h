#ifndef ROUTE_TABLE_H
#define ROUTE_TABLE_H

#include <QDialog>
#include <QStandardItemModel>
#include "route.h"

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
    void addColumns();
    void addRows();
    bool checkStatus(route*);

private slots:

    void on_addButton_clicked();
   // void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::route_table *ui;
    std::vector<route>* m_routes;
    QStandardItemModel *tblr;
};

#endif // ROUTE_TABLE_H
