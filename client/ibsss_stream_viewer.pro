#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T00:44:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../Client
TEMPLATE = app

INCLUDEPATH += $$PWD/../specifications

SOURCES += *.cpp \
    *.cc \
    ../specifications/*.cc \
    ../specifications/*.c

HEADERS  += *.h \
    *.hh \
    #../specifications/*.hh \
    #../specifications/*.h

FORMS    += ibsss_login_window.ui \
    ibsss_stream_view_window.ui


