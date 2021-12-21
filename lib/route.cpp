#include "route.h"

route::route()
{

}

route::~route()
{

}

void route::setLoadingCity(QString load_)
{
    loading_city = load_;
}

QString &route::getLoadingCity()
{
    return loading_city;
}
void route::setUnloadingCity(QString unload_)
{
    unloading_city = unload_;
}
QString &route::getUnloadingCity()
{
    return unloading_city;
}
void route::setLoadingDate(QString date_)
{
    loading_date = date_;
}
QString &route::getLoadingDate()
{
    return loading_date;
}
void route::setCargoWeight(QString weight_)
{
    cargo_weight = weight_;
}
QString &route::getCargoWeight()
{
    return cargo_weight;
}
void route::setCargoVolume(QString volume_)
{
    cargo_volume = volume_;
}
QString &route::getCargoVolume()
{
    return cargo_volume;
}
void route::setCargoType(QString type_)
{
    cargo_type = type_;
}
QString &route::getCargoType()
{
    return cargo_type;
}
void route::setPrice(QString price_)
{
    price = price_;
}
QString &route::getPrice()
{
    return price;
}
void route::setRouteId(QString id_)
{
    route_id = id_;
}
QString &route::getRouteId()
{
    return route_id;
}

void route::setStatus(int status_)
{
    status = status_;
}

int route::getStatus()
{
    return status;
}

void route::setStartRoute(QDateTime start_)
{
    start_route = start_;
}

void route::setStartRoute(QString start_)
{
    start_route = QDateTime::fromString(start_, "dd MMM yyyy HH:mm:ss");
}

QDateTime &route::getStartRoute()
{
    return start_route;
}

void route::setEndRoute(QDateTime end_)
{
    end_route = end_;
}

void route::setEndRoute(QString end_)
{
    end_route = QDateTime::fromString(end_, "dd MMM yyyy HH:mm:ss");
}

QDateTime &route::getEndRoute()
{
    return end_route;
}



void route::save(QDataStream &ost) const
{
    ost << loading_city << unloading_city << loading_date << cargo_weight << cargo_volume << cargo_type
        << price << route_id << status << start_route << end_route;
}

void route::load(QDataStream &ist)
{
    ist >> loading_city >> unloading_city >> loading_date >> cargo_weight >> cargo_volume >> cargo_type
        >> price >> route_id >> status >> start_route >> end_route;
}
