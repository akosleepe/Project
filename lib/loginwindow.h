#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "user.h"
#include "route.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

public slots:
    void authorization();
    void about();
    void exit();

private:
    void load_users();
    void load_routes();
    void save_users();
    void save_routes();

    int role = -1;
    int index = -1;
    Ui::MainWindow *log;
    std::vector<user> m_users;
    std::vector<route> m_routes;
};
#endif // LOGINWINDOW_H
