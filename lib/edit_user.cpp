#include <QMessageBox>

#include "edit_user.h"
#include "ui_edit_user.h"
#include "config.h"

edit_user::edit_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_user)
{
    ui->setupUi(this);
}

void edit_user::setUser(user* m_user_)
{
    m_user = m_user_;

    if (m_user)
    {
        ui->nameEdit->setText(m_user->getName());
        ui->numberEdit->setText(m_user->getNumber());
        ui->driverExpEdit->setText(m_user->getDriverExp());
        ui->passwordEdit->setText(m_user->getPassword());
        ui->loginEdit->setText(m_user->getLogin());
        ui->idEdit->setText(m_user->getId());
    }
    else
        ui->numberEdit->setReadOnly(false);
}

void edit_user::accept()
{
    QString login = ui->loginEdit->text();
    QString num = ui->numberEdit->text();
    QString name = ui->nameEdit->text();
    QString password = ui->passwordEdit->text();
    QString driverExp = ui->driverExpEdit->text();
    QString id = ui->idEdit->text();

    if (login.size() > 40 || login.isEmpty())
    {
        QMessageBox::warning(0, config::applicationName, "Имя должно состоять не больше чем из 40 элементов");
        return;
    }

    if ( num.size() != 12 || (num[0] != '+') )
    {
        QMessageBox::warning(0, config::applicationName, "Код страны записывается полностью");
        return;
    }

    if ( name.isEmpty() )
    {
        QMessageBox::warning(0, config::applicationName, "Поля ФИО должно быть заполнено");
        return;
    }

    if ( password.isEmpty() )
    {
        QMessageBox::warning(0, config::applicationName, "Поле пароля должно быть заполнено");
        return;
    }

    if ( driverExp.isEmpty() )
    {
        QMessageBox::warning(0, config::applicationName, "Поле стажа должно быть заполнено");
        return;
    }

    if ( id.isEmpty() || id.size() > 5 )
    {
        QMessageBox::warning(0, config::applicationName, "Поля id должно быть заполнено и должно состоять не больше чем из 5 элементов");
        return;
    }

    m_user->setName(name);
    m_user->setNumber(num);
    m_user->setLogin(login);
    m_user->setDriverExp(driverExp);
    m_user->setPassword(password);
    m_user->setId(id);

    return QDialog::accept();
}

edit_user::~edit_user()
{
    delete ui;
}

void edit_user::reject()
{
    edit_user::close();
}
