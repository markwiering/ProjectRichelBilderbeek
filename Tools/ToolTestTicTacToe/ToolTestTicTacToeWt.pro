#-------------------------------------------------
#
# Project created by QtCreator 2010-09-17T11:09:34
#
#-------------------------------------------------
QT       += core
QT       -= gui
TARGET = ToolTestTicTacToeWt
LIBS += -L/usr/lib -lwt  -lwthttp
#-lwtext
QMAKE_CXXFLAGS += -DNDEBUG
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
SOURCES +=  \  
    wtmain.cpp \
    ../../Classes/CppTicTacToe/tictactoe.cpp \
    ../../Classes/CppWtTicTacToeWidget/wttictactoewidget.cpp
HEADERS  +=  \
    ../../Classes/CppTicTacToe/tictactoe.h \
    ../../Classes/CppWtTicTacToeWidget/wttictactoewidget.h