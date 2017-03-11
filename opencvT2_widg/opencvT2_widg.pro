#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T17:28:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvT2_widg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ColorDetector.cpp \
    ColorDetectController.cpp

HEADERS  += mainwindow.h \
    ColorDetector.h \
    ColorDetectController.h \


FORMS    += mainwindow.ui
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
