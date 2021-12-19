#ifndef DISPATCHERMAINWINDOW_H
#define DISPATCHERMAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "route.h"

namespace Ui {
class dispatcherMainWindow;
}

class dispatcherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit dispatcherMainWindow(QWidget *parent = nullptr);
    ~dispatcherMainWindow();
    void setUsers(std::vector<user>);
    void setRoute(std::vector<route>);
    void setIndex(int);

public slots:
    void exportUsersCSV();
    void importUsersCSV();
    void exportCallsCSV();
    void importCallsCSV();
    void exit();

private slots:
    void on_routeButton_clicked();

    void on_driverButton_clicked();


    void on_dispatcherButton_clicked();

private:
    void save_users();

    Ui::dispatcherMainWindow *ui;
    std::vector<user> m_users;
    std::vector<route> m_routes;

    int index;
    int role;
};

#endif // DISPATCHERMAINWINDOW_H
