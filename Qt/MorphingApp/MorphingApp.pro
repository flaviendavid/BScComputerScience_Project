#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T10:25:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MorphingApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    morph.cpp \
    my_tool.cpp \


HEADERS  += mainwindow.h \
    morph.h \
    my_tool.h \

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc



#QT += widgets
#qtHaveModule(printsupport): QT += printsupport

#HEADERS      = mainwindow.h \
#    morph.h \
#    my_tool.h \
#    tool.h

#SOURCES = main.cpp\
#    mainwindow.cpp \
#    morph.cpp \
#    my_tool.cpp \
#    tool.cpp

#FORMS    += mainwindow.ui

#RESOURCES += \
#    ressources.qrc
## install
#target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/scribble
#INSTALLS += target
