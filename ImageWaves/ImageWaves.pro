#-------------------------------------------------
#
# Project created by QtCreator 2013-11-10T14:13:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageWaves
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagehandler.cpp \
    ffthandler.cpp

HEADERS  += mainwindow.h \
    imagehandler.h \
    ffthandler.h

LIBS += -lfftw3 -lm

FORMS    += mainwindow.ui
