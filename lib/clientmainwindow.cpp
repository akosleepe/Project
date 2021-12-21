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
    for (size_t i = 0; i < m_routes.size(); i++)
    {
        if ( ( m_routes[i].getRouteId() == m_users[index].getId() )
             || ( m_routes[i].getStatus() == 1 ) )
        {
            ui->loadingCity->setText(m_routes[i].getLoadingCity());
            ui->unloadingCity->setText(m_routes[i].getUnloadingCity());
        }

    }

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

void clientMainWindow::startRouteTime()
{
    auto updateTimer = new QTimer;
    updateTimer->setInterval(500);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedValues()));
    updateTimer->start();
}

void clientMainWindow::on_startRouteButton_clicked()
{
    stop = false;
    ui->startRouteButton->setEnabled(false);
    ui->endRouteButton->setEnabled(true);
    startRouteTime();
}

void clientMainWindow::updateDisplayedValues()
{
    if (!stop)
    {
        QTime time = QTime::currentTime();
        time = time.addSecs(-3600 * m_route.getStartRoute().time().hour());
        time = time.addSecs(-60 * m_route.getStartRoute().time().minute());
        time = time.addSecs(-1 * m_route.getStartRoute().time().second());
        ui->routeTimeEdit->setTime(time);
    }
}

void clientMainWindow::on_endRouteButton_clicked()
{
    m_route.setEndRoute(QDateTime::currentDateTime());
    for (size_t i = 0; i < m_routes.size(); i++)
    {
        if ( ( m_routes[i].getRouteId() == m_users[index].getId() )
             || ( m_routes[i].getStatus() == 1 ) )
        {
            m_routes[i].setStatus(2);
        }

    }
    m_routes.push_back(m_route);
    save_routes();

    stop = true;
    ui->startRouteButton->setEnabled(true);
    ui->endRouteButton->setEnabled(false);
}


