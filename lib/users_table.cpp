#include "users_table.h"
#include "ui_users_table.h"
#include "edit_user.h"
#include "adddriver.h"

users_table::users_table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users_table)
{
    ui->setupUi(this);
}

void users_table::setUsers(std::vector<user>* m_users_)
{
    m_users = m_users_;
    addColumns();
    addRows();

}

users_table::~users_table()
{
    delete ui;
}

void users_table::addColumns()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(3);
    tbl->setHorizontalHeaderLabels(QStringList() << "ФИО" << "Номер" << "Стаж");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(tbl);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void users_table::addRows()
{
    for (size_t i = 0; i < m_users->size(); i++)
    {
        if (m_users->at(i).getRole() == 0)
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_users->at(i).getName()));
            standardItemsList.append(new QStandardItem(m_users->at(i).getNumber()));
            standardItemsList.append(new QStandardItem(m_users->at(i).getDriverExp()));
            tbl->insertRow(tbl->rowCount(), standardItemsList);
        }
    }
}



void users_table::on_addButton_clicked()
{
    adddriver add_user;
    user user;

    add_user.setUser(&user);
    if (add_user.exec() != users_table::Accepted)
    {
        return;
    }
    m_users->push_back(user);
    setUsers(m_users);
}

void users_table::on_editButton_clicked()
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
}
bool users_table::checkRole(user* user)
{
    if (user->getRole()!=2)
    return true;
    else return false;
}

void users_table::on_deleteButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();
    m_users->erase(m_users->begin() + ind);
    setUsers(m_users);
}

