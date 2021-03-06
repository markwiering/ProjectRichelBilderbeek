QT       += core gui
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
TEMPLATE = app

INCLUDEPATH += \
    ../../Classes/CppQtHideAndShowDialog

SOURCES += \
    ../../Classes/CppQtHideAndShowDialog/qthideandshowdialog.cpp \
    qtmain.cpp \
    qttesthideandshowmaindialog.cpp

HEADERS += \
    ../../Classes/CppQtHideAndShowDialog/qthideandshowdialog.h \
    qttesthideandshowmaindialog.h

OTHER_FILES += \
    ../../Classes/CppQtHideAndShowDialog/Licence.txt

FORMS += \
    qttesthideandshowmaindialog.ui
