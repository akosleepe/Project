#include "adddriver.h"
#include "ui_adddriver.h"

adddriver::adddriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddriver)
{
    ui->setupUi(this);
}

adddriver::~adddriver()
{
    delete ui;
}
