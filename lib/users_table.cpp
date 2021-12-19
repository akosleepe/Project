#include "users_table.h"
#include "ui_users_table.h"

users_table::users_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::users_table)
{
    ui->setupUi(this);
}

users_table::~users_table()
{
    delete ui;
}
