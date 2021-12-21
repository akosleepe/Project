#ifndef EDIT_ROUTE_H
#define EDIT_ROUTE_H

#include <QDialog>
#include "route.h"

namespace Ui {
class edit_route;
}

class edit_route : public QDialog
{
    Q_OBJECT

public:
    explicit edit_route(QWidget *parent = nullptr);
    ~edit_route();
    void setRoute(route*);
    void setRouteId(route*,QString);
    void setStatus(route*);

public slots:
    void accept();
    void reject();
private:
    Ui::edit_route *ui;
    route* m_route;
};

#endif // EDIT_ROUTE_H
