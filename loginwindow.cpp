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
    admin.setLogin(config::loginAdmin); // call center bank number
    admin.setDriverExp(config::driverExp); // call center city
    admin.setNumber(config::number); // call center number
    admin.setRole(2); // call center admin role
    admin.setPassword(config::passwordAdmin); // default password for admin
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
    QFile inf(config::fileCalls);
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
    QDialog *loginWindow = new QDialog;
    bool try_auth = false;
    if (loginWindow->exec() == QDialog::Accepted)
    {
        try_auth = true;
        QString login =  log->login->text();
        QString password =  log->pass->text();

        for (size_t i = 0; i < m_users.size(); i++)
        {
            if ((m_users[i].getName() == login) && (m_users[i].getPassword() == password))
            {
                role = m_users[i].getRole();
                index = i;
            }
        }

    }

      if (try_auth)
    {
        if (role > 0)
        {
            QMessageBox::information(0, config::applicationName, "You'r succeful authorisation.");
            dispatcherMainWindow *mmw = new dispatcherMainWindow;

            mmw->show();
            this->close();
        }
        else if (role == 0)
        {
            QMessageBox::information(0, config::applicationName, "You'r succeful authorisation.");
            clientMainWindow *cmw = new clientMainWindow;

            cmw->show();
            this->close();
        }
        else
        {
            QMessageBox::information(0, config::applicationName, "User not finding.\nTry again.");
            authorization();
        }
    }

}

/*void LoginWindow::on_pushButton_clicked()
{
    QString login = log->login->text();
    QString password = log->pass->text();
    if(login=="Len" && password == "123")
    {
        QMessageBox::information(this,"Login","Успешно");
        hide();
        MainWindow window;
        window.setModal(true);
        window.exec();

    }
    else{
        QMessageBox::warning(this,"Login","Не успешно");
    }
}*/
void LoginWindow::exit()
{
    LoginWindow::close();
}
