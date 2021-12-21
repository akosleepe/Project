

#include <QMessageBox>
#include <QFile>
#include <QSaveFile>

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"
#include "dispatchermainwindow.h"
#include "ui_dispatchermainwindow.h"
#include "config.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , log(new Ui::MainWindow)
{
    log->setupUi(this);

    load_users();
    load_routes();

    user admin;
    admin.setName(config::nameAdmin);
    admin.setLogin(config::loginAdmin);
    admin.setDriverExp(config::driverExp);
    admin.setNumber(config::number);
    admin.setRole(2);
    admin.setPassword(config::passwordAdmin);
    m_users.push_back(admin);

}

LoginWindow::~LoginWindow()
{
    delete log;
}

void LoginWindow::save_users()
{
    QSaveFile outf(config::fileUsers);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_users.size(); i++)
    {
        if (m_users[i].getRole() != 2)
            ost << m_users[i];
    }
    outf.commit();
}

void LoginWindow::load_routes()
{
    QFile inf(config::fileRoutes);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_routes.clear();
    while (!ist.atEnd())
    {
        route c;
        ist >> c;
        m_routes.push_back(c);
    }
}

void LoginWindow::load_users()
{
    QFile inf(config::fileUsers);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_users.clear();
    while (!ist.atEnd())
    {
        user u;
        ist >> u;
        m_users.push_back(u);
    }
}

void LoginWindow::authorization()
{

        bool try_auth = true;
        QString login =  log->login->text();
        QString password =  log->pass->text();

        for (size_t i = 0; i < m_users.size(); i++)
        {
            if ((m_users[i].getLogin() == login) && (m_users[i].getPassword() == password))
            {
                role = m_users[i].getRole();
                index = i;
            }
        }



      if (try_auth)
    {
        if (role > 0)
        {
            QMessageBox::information(0, config::applicationName, "You'r succeful authorisation.");
            dispatcherMainWindow *dmw = new dispatcherMainWindow;
            dmw->setUsers(m_users);
            dmw->setRoutes(m_routes);
            dmw->setIndex(index);
            dmw->show();
            this->close();
        }
        else if (role == 0)
        {
            QMessageBox::information(0, config::applicationName, "You'r succeful authorisation.");
            clientMainWindow *cmw = new clientMainWindow;
            cmw->setUsers(m_users);
            cmw->setRoutes(m_routes);
            cmw->setIndexUser(index);
            cmw->show();
            this->close();
        }
        else
        {
            QMessageBox::information(0, config::applicationName, "User not finding.\nTry again.");

        }
    }

}

void LoginWindow::about()
{
    QMessageBox about(this);
    about.setIcon(QMessageBox::Information);
    about.setWindowTitle(QString("About %1").arg("Call Center"));
    about.setText(QString("%1<br>"
        "Author: <a href=\"mailto:leolastleo@gmail.com\">Lastovskiy Leonid Vitalievich</a><br>"
        "Github: <a href=\"https://github.com/akosleepe/Project\">https://github.com/akosleepe/Project</a><br>"
        "Icons by <a href=\"http://tango.freedesktop.org/"
        "Tango_Desktop_Project\">The Tango! Desktop Project</a><br>"
        "Version %1: %2<br> Version QT: %3")
                  .arg(config::applicationName).arg(config::applicationVersion).arg(qVersion()));
    about.exec();
}
void LoginWindow::exit()
{
    LoginWindow::close();
}
