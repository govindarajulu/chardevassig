TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c

QMAKE_CXXFLAGS = -I/usr/src/linux-3.4.5-1-ARCH/include
QMAKE_CFLAGS = -I/usr/src/linux-3.4.5-1-ARCH/include
