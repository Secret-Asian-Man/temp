TEMPLATE = app
CONFIG += .
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    image.cpp \
    EasyBMP.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    image.h \
    EasyBMP.h \
    EasyBMP_BMP.h \
    EasyBMP_DataStructures.h \
    EasyBMP_VariousBMPutilities.h

