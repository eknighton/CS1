TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    readerfunctions.cpp \
    dsvector.cpp

HEADERS += \
    dsstring.h \
    main.h \
    dsvector.h
