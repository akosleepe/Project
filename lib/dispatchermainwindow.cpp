#include <QSaveFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QFileDialog>

#include "dispatchermainwindow.h"
#include "ui_dispatchermainwindow.h"
#include "config.h"

dispatcherMainWindow::dispatcherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dispatcherMainWindow)
{
    ui->setupUi(this);
}

dispatcherMainWindow::~dispatcherMainWindow()
{
    delete ui;
}

void dispatcherMainWindow::on_routeButton_clicked()
{

}


void dispatcherMainWindow::on_driverButton_clicked()
{

}

void dispatcherMainWindow::setUsers(std::vector<user> m_users_)
{
    m_users = m_users_;
}

void dispatcherMainWindow::setRoute(std::vector<route> m_routes_)
{
    m_routes = m_routes_;
}
void dispatcherMainWindow::setIndex(int index_)
{
    index = index_;

    role = m_users[index].getRole();

    if(role==1)
    {
        ui->actionImport_Users->setEnabled(false);
        ui->actionImport_Routes->setEnabled(false);
        ui->actionExport_Users->setEnabled(false);
        ui->actionExport_Routes->setEnabled(false);
    }
}

void dispatcherMainWindow::save_users()
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


void dispatcherMainWindow::on_dispatcherButton_clicked()
{

}

