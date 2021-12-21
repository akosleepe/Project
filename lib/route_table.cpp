#include "route_table.h"
#include "ui_route_table.h"
//#include "edit_user.h"
#include "add_route.h"

route_table::route_table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::route_table)
{
    ui->setupUi(this);
}

void route_table::setRoutes(std::vector<route>* m_routes_)
{
    m_routes = m_routes_;
    addColumns();
    addRows();
}

route_table::~route_table()
{
    delete ui;
}

void route_table::addColumns()
{
    tblr = new QStandardItemModel;
    tblr->setColumnCount(3);
    tblr->setHorizontalHeaderLabels(QStringList() << "Город погрузки" << "Город разргрузки" << "Дата погрузки" << "Вес груза"
                                    << "Объём груза" << "Тип груза" << "Цена");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(tblr);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void route_table::addRows()
{
    for (size_t i = 0; i < m_routes->size(); i++)
    {
        if (m_routes->at(i).getStatus() == 0)
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_routes->at(i).getLoadingCity()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getUnloadingCity()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getLoadingDate()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getCargoWeight()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getCargoVolume()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getCargoType()));
            standardItemsList.append(new QStandardItem(m_routes->at(i).getPrice()));
            tblr->insertRow(tblr->rowCount(), standardItemsList);
        }
    }
}

void route_table::on_addButton_clicked()
{
    add_route add_route;
    route route;

    add_route.setRoute(&route);
    if (add_route.exec() != route_table::Accepted)
    {
        return;
    }
    m_routes->push_back(route);
    setRoutes(m_routes);
}

/*void route_table::on_editButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int i = index.row();

    edit_user add_user;

    for (;!checkRole(&m_users->at(i));i++)
    {}
    add_user.setUser(&m_users->at(i));
    if (add_user.exec() != users_table::Accepted)
    {
        return;
    }

    setUsers(m_users);
}*/

void route_table::on_deleteButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();
    m_routes->erase(m_routes->begin() + ind);
    setRoutes(m_routes);
}
