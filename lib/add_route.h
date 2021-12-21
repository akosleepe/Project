#ifndef ADD_ROUTE_H
#define ADD_ROUTE_H

#include <QDialog>

#include "route.h"

namespace Ui {
class add_route;
}

class add_route : public QDialog
{
    Q_OBJECT

public:
    explicit add_route(QWidget *parent = nullptr);
    ~add_route();
    void setLoadingCity(QString);
    void setUnloadingCity(QString);
    void setLoadingDate(QString);
    void setCargoWeight(QString);
    void setCargoVolume(QString);
    void setCargoType(QString);
    void setPrice(QString);

    void setRoute (route*);

public slots:
    void accept();
    void reject();

private:
    route *m_route;
    Ui::add_route *ui;
};
#endif // ADD_ROUTE_H
