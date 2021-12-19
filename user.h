#ifndef USER_H
#define USER_H


#include <QString>


class user
{

public:
    user();
    ~user();
    void setName(QString);
    QString &getName();
    void setLogin(QString);
    QString &getLogin();
    void setPassword(QString);
    QString &getPassword();
    void setNumber(QString);
    QString &getNumber();
    void setDriverExp(QString);
    QString &getDriverExp();
    void setRole(int);
    int getRole();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString login;
    QString password;
    QString name;
    QString number;
    QString driver_exp;
    int role;
};

inline QDataStream &operator<<(QDataStream &ost, const user &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, user &u)
{
    u.load(ist);
    return ist;
}
#endif // USER_H
