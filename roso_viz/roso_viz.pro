#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T21:56:55
#
#-------------------------------------------------

QT       += core gui network

TARGET = roso_viz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpserver.cpp \
    util/logger.cpp \
    Setting/settingcenter.cpp \
    data/robopos.cpp \
    controller/fieldmodelcontroller.cpp \
    data/statefortimestep.cpp \
    widgets/rosofieldwdgt.cpp \
    drawing/robotgraphicitem.cpp \
    drawing/ballgraphicitem.cpp \
    drawing/fieldgraphicitem.cpp \
    drawing/robottargetgraphicitem.cpp \
    data/staterecord.cpp \
    player/modemanager.cpp \
    player/recorder.cpp \
    player/recordplayer.cpp

HEADERS  += mainwindow.h \
    udpserver.h \
    util/logger.h \
    Setting/settingcenter.h \
    data/robopos.h \
    commonDefs.h \
    controller/fieldmodelcontroller.h \
    data/statefortimestep.h \
    widgets/rosofieldwdgt.h \
    drawing/robotgraphicitem.h \
    drawing/ballgraphicitem.h \
    drawing/fieldgraphicitem.h \
    drawing/robottargetgraphicitem.h \
    data/staterecord.h \
    player/modemanager.h \
    player/recorder.h \
    player/recordplayer.h

FORMS    += mainwindow.ui \
    widgets/rosofieldwdgt.ui

RESOURCES += \
    res.qrc


QMAKE_POST_LINK += $$quote(cp --force $${PWD}/rosoviz.ini $${OUT_PWD}$$escape_expand(\n\t))

