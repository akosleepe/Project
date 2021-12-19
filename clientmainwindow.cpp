#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"

clientMainWindow::clientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientMainWindow)
{
    ui->setupUi(this);
}

clientMainWindow::~clientMainWindow()
{
    delete ui;
}
