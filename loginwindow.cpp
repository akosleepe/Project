#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , log(new Ui::MainWindow)
{
    log->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete log;
}


void LoginWindow::on_pushButton_clicked()
{
    QString login = log->login->text();
    QString password = log->pass->text();
    if(login=="Len" && password == "123")
    {
        QMessageBox::information(this,"Login","Успешно");
        hide();
        MainWindow window;
        window.setModal(true);
        window.exec();

    }
    else{
        QMessageBox::warning(this,"Login","Не успешно");
    }
}

