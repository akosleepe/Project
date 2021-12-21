QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_route.cpp \
    adddriver.cpp \
    clientmainwindow.cpp \
    dispatchermainwindow.cpp \
    edit_route.cpp \
    edit_user.cpp \
    loginwindow.cpp \
    main.cpp \
    route.cpp \
    route_table.cpp \
    routehistory.cpp \
    user.cpp \
    users_table.cpp

HEADERS += \
    add_route.h \
    adddriver.h \
    clientmainwindow.h \
    config.h \
    dispatchermainwindow.h \
    edit_route.h \
    edit_user.h \
    loginwindow.h \
    route.h \
    route_table.h \
    routehistory.h \
    user.h \
    users_table.h \
    users_table.h

FORMS += \
    add_route.ui \
    adddriver.ui \
    clientmainwindow.ui \
    dispatchermainwindow.ui \
    edit_route.ui \
    edit_user.ui \
    loginwindow.ui \
    route_table.ui \
    routehistory.ui \
    users_table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
