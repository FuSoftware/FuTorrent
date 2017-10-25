#-------------------------------------------------
#
# Project created by QtCreator 2017-10-14T18:25:42
#
#-------------------------------------------------

#https://wiki.theory.org/index.php/BitTorrentSpecification#Bencoding

QT       += core gui
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FuTorrent
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    torrent/parsing/torrentparser.cpp \
    torrent/torrentfile.cpp \
    torrent/parsing/data/tbytes.cpp \
    torrent/parsing/data/tdata.cpp \
    torrent/parsing/data/tstring.cpp \
    tests.cpp \
    torrent/parsing/data/tinteger.cpp \
    torrent/parsing/data/tlist.cpp \
    torrent/parsing/data/tdictionnary.cpp \
    utils.cpp \
    torrent/tracker/tracker.cpp

HEADERS += \
        mainwindow.h \
    torrent/parsing/torrentparser.h \
    torrent/torrentfile.h \
    torrent/parsing/data/tbytes.h \
    torrent/parsing/data/tdata.h \
    torrent/parsing/data/tstring.h \
    tests.h \
    torrent/parsing/data/tinteger.h \
    torrent/parsing/data/tlist.h \
    torrent/parsing/data/tdictionnary.h \
    torrent/parsing/data/tdatatypes.h \
    utils.h \
    torrent/tracker/tracker.h
