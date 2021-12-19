/*!
 * \file
 * \brief Конфиг файл
 */
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QtGlobal>
#include <QString>

namespace config
{
    //! Название программы
    const char applicationName[] = QT_TRANSLATE_NOOP("Config", "Cargo transportation");
    //! Версия программы
    const char applicationVersion[] = "20211219";
    //! Название файла с пользователей
    const QString fileUsers = "users.tnb";
    //! Настройки администратора и самой фирмы Call Center
    const QString fileCalls = "calls.tnb";

    const QString nameManagers = "Call Center Manager";
    const QString nameAdmin = "Admin";
    const QString loginAdmin = "adminCallCenter";
    const QString passwordAdmin = "12345";
    const QString driverExp = "Krasnoyarsk";
    const QString number = "+79509777777";

}

#endif // CONFIG_HPP
