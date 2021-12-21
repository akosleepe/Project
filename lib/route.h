#ifndef ROUTE_H
#define ROUTE_H


#include <QString>
#include <QDateTime>

class route
{
public:
    route();
    ~route();
    void setLoadingCity(QString);
    QString &getLoadingCity();
    void setUnloadingCity(QString);
    QString &getUnloadingCity();
    void setLoadingDate(QString);
    QString &getLoadingDate();
    void setCargoWeight(QString);
    QString &getCargoWeight();
    void setCargoVolume(QString);
    QString &getCargoVolume();
    void setCargoType(QString);
    QString &getCargoType();
    void setPrice(QString);
    QString &getPrice();
    void setRouteId(QString);
    QString &getRouteId();

    void setStartRoute(QDateTime);
    void setStartRoute(QString);
    QDateTime &getStartRoute();
    void setEndRoute(QDateTime);
    void setEndRoute(QString);
    QDateTime &getEndRoute();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString loading_city;
    QString unloading_city;
    QString loading_date;
    QString cargo_weight;
    QString cargo_volume;
    QString cargo_type;
    QString price;
    QString route_id;
    QDateTime start_route;
    QDateTime end_route;
};

inline QDataStream &operator<<(QDataStream &ost, const route &c)
{
    c.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, route &c)
{
    c.load(ist);
    return ist;
}

#endif // ROUTE_H
