#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T00:44:24
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../Client
TEMPLATE = app

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

INCLUDEPATH += /usr/include/cryptopp
INCLUDEPATH += $$PWD/../specifications
INCLUDEPATH += $$PWD/../crypto

LIBS += -L/usr/lib/cryptopp -lcryptopp

SOURCES += *.cpp \
    *.cc \
    ../specifications/*.cc \
    ../specifications/*.c   \
    ../crypto/*.cpp

HEADERS  += *.h \
            *.hh


FORMS    += ibsss_login_window.ui \
    ibsss_stream_view_window.ui


