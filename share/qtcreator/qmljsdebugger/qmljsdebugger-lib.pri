QT += declarative script
INCLUDEPATH += $$PWD $$PWD/include editor
DEPENDPATH += $$PWD $$PWD/include editor

contains(CONFIG, dll) {
    DEFINES += BUILD_QMLJSDEBUGGER_LIB
} else {
    DEFINES += BUILD_QMLJSDEBUGGER_STATIC_LIB
}

include($$PWD/private_headers.pri)

include($$PWD/editor/editor.pri)

## Input
HEADERS += \
    include/jsdebuggeragent.h \
    include/qdeclarativeviewobserver.h \
    include/qdeclarativeobserverservice.h \
    include/qmlobserverconstants.h \
    include/qmljsdebugger_global.h \
    qdeclarativeviewobserver_p.h

SOURCES += \
    jsdebuggeragent.cpp \
    qdeclarativeviewobserver.cpp \
    qdeclarativeobserverservice.cpp

OTHER_FILES += qmljsdebugger.pri
