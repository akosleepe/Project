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

}
void routehistory::setIndex(int index_)
{
    index = index_;
}

void routehistory::setUser(user m_user_)
{
    m_user = m_user_;

    addRowsForClient();
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

void routehistory::addRowsForClient()
{
    for (size_t i = 0; i < m_routes.size(); i++)
    {
        if ( ( m_routes[i].getRouteId() == m_user.getId() )
             || ( m_routes[i].getStatus() == 2 ) )
        {
                QList<QStandardItem *> standardItemsList;
                standardItemsList.append(new QStandardItem(m_routes[i].getLoadingCity()));
                standardItemsList.append(new QStandardItem(m_routes[i].getUnloadingCity()));
                standardItemsList.append(new QStandardItem(m_routes[i].getLoadingDate()));
                standardItemsList.append(new QStandardItem(m_routes[i].getCargoWeight()));
                standardItemsList.append(new QStandardItem(m_routes[i].getCargoVolume()));
                standardItemsList.append(new QStandardItem(m_routes[i].getCargoType()));
                standardItemsList.append(new QStandardItem(m_routes[i].getPrice()));
                standardItemsList.append(new QStandardItem(m_routes[i].getStartRoute().toString("dd MMM yyyy HH:mm:ss")));
                standardItemsList.append(new QStandardItem(m_routes[i].getEndRoute().toString("dd MMM yyyy HH:mm:ss")));

                QTime time = m_routes[i].getEndRoute().time();
                time = time.addSecs(-60 * m_routes[i].getStartRoute().time().minute());
                time = time.addSecs(-1 * m_routes[i].getStartRoute().time().second());
                time = time.addSecs(-3600 * m_routes[i].getStartRoute().time().hour());
                standardItemsList.append(new QStandardItem(time.toString()));
                tbl->insertRow(tbl->rowCount(), standardItemsList);
        }

    }
}

void routehistory::addRowsForManager()
{
    for (size_t i = 0; i < m_routes.size(); i++)
    {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(m_routes[i].getLoadingCity()));
        standardItemsList.append(new QStandardItem(m_routes[i].getUnloadingCity()));
        standardItemsList.append(new QStandardItem(m_routes[i].getLoadingDate()));
        standardItemsList.append(new QStandardItem(m_routes[i].getCargoWeight()));
        standardItemsList.append(new QStandardItem(m_routes[i].getCargoVolume()));
        standardItemsList.append(new QStandardItem(m_routes[i].getCargoType()));
        standardItemsList.append(new QStandardItem(m_routes[i].getPrice()));
        standardItemsList.append(new QStandardItem(m_routes[i].getStartRoute().toString()));
        standardItemsList.append(new QStandardItem(m_routes[i].getEndRoute().toString()));

        QTime time = m_routes[i].getEndRoute().time();
        time = time.addSecs(-60 * m_routes[i].getStartRoute().time().minute());
        time = time.addSecs(-1 * m_routes[i].getStartRoute().time().second());
        time = time.addSecs(-3600 * m_routes[i].getStartRoute().time().hour());
        standardItemsList.append(new QStandardItem(time.toString()));
        tbl->insertRow(tbl->rowCount(), standardItemsList);
    }
}

routehistory::~routehistory()
{
    delete ui;
}
