#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T16:47:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentInfo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logging.cpp \
    init.cpp \
    mysql.cpp \
    dealall.cpp \
    stuinfo.cpp \
    addinfo.cpp \
    changestu.cpp \
    healthinfo.cpp \
    addhinfo.cpp \
    changeheal.cpp \
    gradeinfo.cpp \
    addgradeinfo.cpp \
    changegrade.cpp

HEADERS  += mainwindow.h \
    logging.h \
    init.h \
    mysql.h \
    dealall.h \
    stuinfo.h \
    addinfo.h \
    changestu.h \
    healthinfo.h \
    addhinfo.h \
    changeheal.h \
    gradeinfo.h \
    addgradeinfo.h \
    changegrade.h

FORMS    += mainwindow.ui \
    logging.ui \
    init.ui \
    dealall.ui \
    stuinfo.ui \
    addinfo.ui \
    changestu.ui \
    healthinfo.ui \
    addhinfo.ui \
    changeheal.ui \
    gradeinfo.ui \
    addgradeinfo.ui \
    changegrade.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res.qrc

QT        += sql
