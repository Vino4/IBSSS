#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T00:44:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = streamViewer
TEMPLATE = app


SOURCES += main.cpp\
        loginpage.cpp \
    streamview.cpp

HEADERS  += loginpage.h \
    streamview.h

FORMS    += loginpage.ui \
    streamview.ui
