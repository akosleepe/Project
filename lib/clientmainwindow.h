#ifndef CLIENTMAINWINDOW_HPP
#define CLIENTMAINWINDOW_HPP

#include <QMainWindow>
#include "user.h"
#include "route.h"

namespace Ui {
class clientMainWindow;
}

class clientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientMainWindow(QWidget *parent = nullptr);
    ~clientMainWindow();
    void setUsers(std::vector<user>);
    void setRoute(std::vector<route>);
    void setIndexUser(int);

public slots:

private slots:

private:
    Ui::clientMainWindow *ui;
    std::vector<user> m_users;
    std::vector<route> m_routes;
    int index;
    route m_route;
    bool stop = false;

    void save_routes(route);
};

#endif // CLIENTMAINWINDOW_HPP
