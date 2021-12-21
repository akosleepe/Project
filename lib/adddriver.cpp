#include <QMessageBox>

#include "adddriver.h"
#include "ui_adddriver.h"
#include "config.h"

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

void adddriver::setName(QString m_name_)
{
    ui->nameEdit->setText(m_name_);
}

void adddriver::setPassword(QString m_password_)
{
    ui->passwordEdit->setText(m_password_);
}

void adddriver::setNumber(QString m_number_)
{
    ui->numberEdit->setText(m_number_);
}

void adddriver::setLogin(QString m_login_)
{
    ui->loginEdit->setText(m_login_);
}

void adddriver::setDriverExp(QString m_driverExp_)
{
    ui->driverExpEdit->setText(m_driverExp_);
}

void adddriver::setId(QString m_id_)
{
    ui->idEdit->setText(m_id_);
}

void adddriver::setUser(user *m_user_)
{
    m_user = m_user_;
}


void adddriver::accept()
{
    QString login = ui->loginEdit->text();
    QString number = ui->numberEdit->text();
    QString name = ui->nameEdit->text();
    QString password = ui->passwordEdit->text();
    QString driverExp = ui->driverExpEdit->text();
    QString id = ui->idEdit->text();

    if (name.size() > 50 || name.isEmpty())
    {
        QMessageBox::warning(0, config::applicationName, "Название компании должно состоять не больше чем из 20 элементов");
        return;
    }
    else if (name == config::nameAdmin)
    {
        QMessageBox::warning(0, config::applicationName, "Эта компания уже внесена в базу данных");
        return;
    }
    else if ( name.contains(config::nameManagers, Qt::CaseSensitive) )
    {
        QMessageBox::warning(0, config::applicationName, "Эта компания уже внесена в базу данных");
        return;
    }

    if ( (password.size() > 24) || (password.size() < 8) )
    {
        QMessageBox::warning(0, config::applicationName, "Пароль должен быть не больше 24 элеметов и не меньше 8");
        return;
    }

    if ( number.size() != 12 || (number[0] != '+') )
    {
        QMessageBox::warning(0, config::applicationName, "Код страны записывается полностью");
        return;
    }
    else if (number == config::number)
    {
        QMessageBox::warning(0, config::applicationName, "Этот номер уже есть в базе дынных");
        return;
    }
    if ( login.size() > 30  || login.isEmpty())
    {
        QMessageBox::warning(0, config::applicationName, "Слишком длинный логин");
        return;
    }
    else if (number == config::loginAdmin)
    {
        QMessageBox::warning(0, config::applicationName, "Этот логин уже есть в базе дынных");
        return;
    }

    if ( id.isEmpty() || id.size() > 5 )
    {
        QMessageBox::warning(0, config::applicationName, "Поля id должно быть заполнено и должно состоять не больше чем из 5 элементов");
        return;
    }

    m_user->setName(name);
    m_user->setNumber(number);
    m_user->setLogin(login);
    m_user->setDriverExp(driverExp);
    m_user->setPassword(password);
    m_user->setId(id);
    m_user->setRole(0);

    return QDialog::accept();
}

void adddriver::reject()
{
    adddriver::close();
}
