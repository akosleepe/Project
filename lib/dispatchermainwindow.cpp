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
#include "users_table.h"

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

void dispatcherMainWindow::on_routeButton_clicked()
{

}


void dispatcherMainWindow::on_driverButton_clicked()
{
    users_table ut;
    ut.setUsers(&m_users);
    ut.exec();
    save_users();
}

/*
void dispatcherMainWindow::exportUsersCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Users As"), QString("Users-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);
    ost << QString("ФИО;Логин;Пароль;Номер телефона;Стаж;\n").toUtf8();
    for (size_t i = 0; i < m_users.size(); i++)
    {
        QString line;
        if (m_users[i].getRole() == 2)
            continue;
        else if (m_users[i].getRole() == 1)
            line = line + config::nameManagers + ";";
        else
            line = line + QString("%1").arg(m_users[i].getName()) + ";";
        line = line + QString("%1").arg(m_users[i].getPassword()) + ";";
        line = line + QString("%1").arg(m_users[i].getNumber()) + ";";
        line = line + QString("%1").arg(m_users[i].getInn()) + ";";
        line = line + QString("%1").arg(m_users[i].getBankNum()) + ";";
        line = line + QString("%1").arg(m_users[i].getCity()) + ";\n";
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void dispatcherMainWindow::importUsersCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Users", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    m_users.clear();
    int count_manager = 0;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
        {
            first_str = false;
        }
        else
        {
            user m_user;
            QStringList list;
            for (QString item : line.split(";"))
            {
                list.push_back(item);
            }
            m_user.setPassword(list[1]);
            m_user.setNumber(list[2]);
            m_user.setInn(list[3]);
            m_user.setBankNum(list[4]);
            m_user.setCity(list[5]);
            if (list[0] == config::nameManagers)
            {
                count_manager++;
                m_user.setName(QString("%1 %2").arg(config::nameManagers).arg(count_manager));
                m_user.setRole(1);
            }
            else
            {
                m_user.setName(list[0]);
                m_user.setRole(0);
            }

            m_users.push_back(m_user);
        }
    }
    file.close();
}

void dispatcherMainWindow::exportCallsCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save History Calls As"), QString("Calls-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);
    ost << QString("Имя звонящего;Номер звонящего;Адрес звонящего;Имя вызываемого;Номер вызываемого;"
                   "Адрес вызываемого;Время начала разговора;Время конца разговора;Длительность\n").toUtf8();
    for (size_t i = 0; i < m_calls.size(); i++)
    {
        QString line;
        line = line + QString("%1").arg(m_calls[i].getNameCalled()) + ";";
        line = line + QString("%1").arg(m_calls[i].getNumCalled()) + ";";
        line = line + QString("%1").arg(m_calls[i].getCityCalled()) + ";";
        line = line + QString("%1").arg(m_calls[i].getNameCalling()) + ";";
        line = line + QString("%1").arg(m_calls[i].getNumCalling()) + ";";
        line = line + QString("%1").arg(m_calls[i].getCityCalling()) + ";";
        line = line + QString("%1").arg(m_calls[i].getStartCall().toString("dd MMM yyyy HH:mm:ss")) + ";";
        line = line + QString("%1").arg(m_calls[i].getEndCall().toString("dd MMM yyyy HH:mm:ss")) + ";";

        QTime time = m_calls[i].getEndCall().time();
        time = time.addSecs(-60 * m_calls[i].getStartCall().time().minute());
        time = time.addSecs(-1 * m_calls[i].getStartCall().time().second());
        time = time.addSecs(-3600 * m_calls[i].getStartCall().time().hour());

        line = line + QString("%1").arg(time.toString()) + ";\n";
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void dispatcherMainWindow::importCallsCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open History Calls", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    m_calls.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
        {
            first_str = false;
        }
        else
        {
            call m_call;
            QStringList list;
            for (QString item : line.split(";"))
            {
                list.push_back(item);
            }
            m_call.setNameCalled(list[0]);
            m_call.setNumCalled(list[1]);
            m_call.setCityCalled(list[2]);
            m_call.setNameCalling(list[3]);
            m_call.setNumCalling(list[4]);
            m_call.setCityCalling(list[5]);
            m_call.setStartCall(list[6]);
            m_call.setEndCall(list[7]);
            m_calls.push_back(m_call);
        }
    }
    file.close();
}

void dispatcherMainWindow::on_callHistoryButton_clicked()
{
    if (m_calls.empty())
    {
        QMessageBox::information(0, config::applicationName, "У вас нет истории звонков.");
        return;
    }
    callhistory ch;
    ch.setIndex(index);
    ch.setCalls(m_calls);
    ch.setRole(role);
    ch.exec();
}

void dispatcherMainWindow::exit()
{
    managerMainWindow::close();
}

*/
