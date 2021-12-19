#include "dispatchermainwindow.h"
#include "ui_dispatchermainwindow.h"

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
