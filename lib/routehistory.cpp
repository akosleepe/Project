#include <QStandardItemModel>
#include "routehistory.h"
#include "ui_routehistory.h"

routehistory::routehistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::routehistory)
{
    ui->setupUi(this);
    addColumns();
}

void routehistory::setRole(int role_)
{
    role = role_;

    //if (role > 0)
        //addRowsForManager();
}
void routehistory::setIndex(int index_)
{
    index = index_;
}

void routehistory::setUser(user m_user_)
{
    m_user = m_user_;

    //addRowsForClient();
}

void routehistory::setRoutes(std::vector<route> m_routes_)
{
    m_routes = m_routes_;
}

void routehistory::addColumns()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(9);
    tbl->setHorizontalHeaderLabels(QStringList() << "Город загрузки" << "Город выгрузки" << "Дата загрузки"
                                   << "Вес груза" << "Объём груза" << "Тип груза"
                                   << "Стоимость превозки" << "Начало рейса" << "Конец рейса");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(tbl);
}

/*void routehistory::addRowsForClient()
{
    for (size_t i = 0; i < m_routes.size(); i++)
    {
        if ( ( m_routes[i].getNameCalled() == m_user.getName() )
                || ( m_routes[i].getNameCalling() == m_user.getName() ) )
        {
                QList<QStandardItem *> standardItemsList;
                standardItemsList.append(new QStandardItem(m_calls[i].getNameCalled()));
                standardItemsList.append(new QStandardItem(m_calls[i].getNumCalled()));
                standardItemsList.append(new QStandardItem(m_calls[i].getCityCalled()));
                standardItemsList.append(new QStandardItem(m_calls[i].getNameCalling()));
                standardItemsList.append(new QStandardItem(m_calls[i].getNumCalling()));
                standardItemsList.append(new QStandardItem(m_calls[i].getCityCalling()));
                standardItemsList.append(new QStandardItem(m_calls[i].getStartCall().toString("dd MMM yyyy HH:mm:ss")));
                standardItemsList.append(new QStandardItem(m_calls[i].getEndCall().toString("dd MMM yyyy HH:mm:ss")));

                QTime time = m_calls[i].getEndCall().time();
                time = time.addSecs(-60 * m_calls[i].getStartCall().time().minute());
                time = time.addSecs(-1 * m_calls[i].getStartCall().time().second());
                time = time.addSecs(-3600 * m_calls[i].getStartCall().time().hour());
                standardItemsList.append(new QStandardItem(time.toString()));
                tbl->insertRow(tbl->rowCount(), standardItemsList);
        }

    }
}

void routehistory::addRowsForManager()
{
    for (size_t i = 0; i < m_calls.size(); i++)
    {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(m_calls[i].getNameCalled()));
        standardItemsList.append(new QStandardItem(m_calls[i].getNumCalled()));
        standardItemsList.append(new QStandardItem(m_calls[i].getCityCalled()));
        standardItemsList.append(new QStandardItem(m_calls[i].getNameCalling()));
        standardItemsList.append(new QStandardItem(m_calls[i].getNumCalling()));
        standardItemsList.append(new QStandardItem(m_calls[i].getCityCalling()));
        standardItemsList.append(new QStandardItem(m_calls[i].getStartCall().toString()));
        standardItemsList.append(new QStandardItem(m_calls[i].getEndCall().toString()));

        QTime time = m_calls[i].getEndCall().time();
        time = time.addSecs(-60 * m_calls[i].getStartCall().time().minute());
        time = time.addSecs(-1 * m_calls[i].getStartCall().time().second());
        time = time.addSecs(-3600 * m_calls[i].getStartCall().time().hour());
        standardItemsList.append(new QStandardItem(time.toString()));
        tbl->insertRow(tbl->rowCount(), standardItemsList);
    }*/
routehistory::~routehistory()
{
    delete ui;
}
