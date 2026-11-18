TEMPLATE = lib
TARGET = primelist_lib
CONFIG += staticlib c++17 debug_and_release build_all
CONFIG -= qt

CONFIG(debug, debug|release): DESTDIR = debug
else: DESTDIR = release

SOURCES += primelist.cpp
HEADERS += primelist.h
