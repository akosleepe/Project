#include <QMessageBox>

#include "add_route.h"
#include "ui_add_route.h"
#include "config.h"

add_route::add_route(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_route)
{
    ui->setupUi(this);
}

add_route::~add_route()
{
    delete ui;
}

void add_route::setLoadingCity(QString m_loading_city_)
{
    ui->loadingCityEdit->setText(m_loading_city_);
}

void add_route::setUnloadingCity(QString m_unloading_city_)
{
    ui->unloadingCityEdit->setText(m_unloading_city_);
}

void add_route::setLoadingDate(QString m_loading_date_)
{
    ui->loadingDateEdit->setText(m_loading_date_);
}

void add_route::setCargoWeight(QString m_cargo_weight_)
{
    ui->cargoWeightEdit->setText(m_cargo_weight_);
}

void add_route::setCargoVolume(QString m_cargo_volume_)
{
    ui->cargoVolumeEdit->setText(m_cargo_volume_);
}

void add_route::setCargoType(QString m_cargo_type_)
{
    ui->cargoTypeEdit->setText(m_cargo_type_);
}

void add_route::setPrice(QString m_price_)
{
    ui->priceEdit->setText(m_price_);
}

void add_route::setRoute(route *m_route_)
{
    m_route = m_route_;
}

void add_route::accept()
{
    QString loading_city = ui->loadingCityEdit->text();
    QString unloading_city = ui->unloadingCityEdit->text();
    QString loading_date = ui->loadingDateEdit->text();
    QString cargo_weight = ui->cargoWeightEdit->text();
    QString cargo_volume = ui->cargoVolumeEdit->text();
    QString cargo_type = ui->cargoTypeEdit->text();
    QString price = ui->priceEdit->text();

   /* if (name.size() > 50 || name.isEmpty())
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
    }*/

    m_route->setLoadingCity(loading_city);
    m_route->setUnloadingCity(unloading_city);
    m_route->setLoadingDate(loading_date);
    m_route->setCargoWeight(cargo_weight);
    m_route->setCargoVolume(cargo_volume);
    m_route->setCargoType(cargo_type);
    m_route->setPrice(price);
    m_route->setStatus(0); // 0-не взят 1-взят 2-выполнен

    return QDialog::accept();
}

void add_route::reject()
{
    add_route::close();
}
