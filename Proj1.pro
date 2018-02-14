TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    readerfunctions.cpp \
    catch.cpp

HEADERS += \
    dsstring.h \
    main.h \
    catch.hpp
