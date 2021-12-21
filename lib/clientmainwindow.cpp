#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"
#include "routehistory.h"
#include "route_table.h"
#include "config.h"

#include <QSaveFile>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QFile>
clientMainWindow::clientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientMainWindow)
{
    ui->setupUi(this);
}

void clientMainWindow::save_routes()
{
    QSaveFile outf(config::fileRoutes);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_routes.size(); i++)
    {
            ost << m_routes[i];
    }
    outf.commit();
}

void clientMainWindow::setIndexUser(int index_)
{
    index = index_;

    ui->nameUser->setText(m_users[index].getName());
    ui->numberUser->setText(m_users[index].getNumber());
}

clientMainWindow::~clientMainWindow()
{
    delete ui;
}


void clientMainWindow::on_routeHistoryButton_clicked()
{
    if (m_routes.empty())
    {
        QMessageBox::information(0, "Information", "У вас нет истории звонков.");
        return;
    }
    routehistory ch;
    ch.setIndex(index);
    ch.setRoutes(m_routes);
    ch.setUser(m_users[index]);
    ch.exec();
}

void clientMainWindow::on_routeButton_clicked()
{
    route_table rt;
    rt.checkRole(0);
    rt.setRoutes(&m_routes);
    rt.exec();
    save_routes();
}

void clientMainWindow::setUsers(std::vector<user> m_users_)
{
    m_users = m_users_;
}

void clientMainWindow::setRoutes(std::vector<route> m_routes_)
{
    m_routes = m_routes_;
}

void clientMainWindow::exit()
{
    clientMainWindow::close();
}
