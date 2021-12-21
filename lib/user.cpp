#include "user.h"

user::user()
{

}

user::~user()
{

}

void user::setName(QString name_)
{
    name = name_;
}

QString &user::getName()
{
    return name;
}

void user::setPassword(QString password_)
{
    password = password_;
}

QString &user::getPassword()
{
    return password;
}

void user::setNumber(QString number_)
{
    number = number_;
}

QString &user::getNumber()
{
    return number;
}

void user::setLogin(QString login_)
{
    login = login_;
}

QString &user::getLogin()
{
    return login;
}

void user::setDriverExp(QString driver_exp_)
{
    driver_exp = driver_exp_;
}

QString &user::getDriverExp()
{
    return driver_exp;
}

void user::setRole(int role_)
{
    role = role_;
}

int user::getRole()
{
    return role;
}

QString &user::getId()
{
    return id;
}

void user::setId(QString id_)
{
    id = id_;
}

void user::save(QDataStream &ost) const
{
    ost << login << password << name << number << driver_exp << id << QString("%1").arg(role);
}

void user::load(QDataStream &ist)
{
    ist >> login >> password >> name >> number >> driver_exp >> id;
    QString tmp;
    ist >> tmp;
    role = tmp.toInt();
}

