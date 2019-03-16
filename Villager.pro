TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    household.cpp \
    simulationhelper.cpp \
    village.cpp \
    villager.cpp

HEADERS += \
    globals.h \
    household.h \
    simulationhelper.h \
    village.h \
    villager.h
