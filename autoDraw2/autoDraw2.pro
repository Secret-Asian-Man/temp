TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    EasyBMP.cpp \
    image.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    EasyBMP.h \
    EasyBMP_BMP.h \
    EasyBMP_DataStructures.h \
    EasyBMP_VariousBMPutilities.h \
    image.h

