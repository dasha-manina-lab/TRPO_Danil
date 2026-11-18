QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += main.cpp dialog.cpp
HEADERS += dialog.h
FORMS += dialog.ui

include(../primelist_lib/primelist_link.pri)
