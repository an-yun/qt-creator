TEMPLATE = app

CONFIG += qt warn_on console depend_includepath
CONFIG -= app_bundle
CONFIG += qtestlib testcase

QT += script \
    declarative

PLUGIN_DIR=../../../../../src/plugins/qmlprojectmanager

include($$PLUGIN_DIR/fileformat/fileformat.pri)

INCLUDEPATH += $$PLUGIN_DIR/fileformat

DEFINES += SRCDIR=\\\"$$PWD\\\"

TEMPLATE = app
SOURCES += tst_fileformat.cpp
