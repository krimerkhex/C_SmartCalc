QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c11 c++17

TEMPLATE = app

mac:LIBS += -framework ApplicationServices

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    credit.cpp \
    depozit.cpp \
    main.cpp \
    mainwindow.cpp \
    s21_credit.c \
    s21_depozit.c \
    s21_smart_calc.c \
    s21_struct.c \
    qcustomplot.cpp

HEADERS += \
    calculator.h \
    credit.h \
    depozit.h \
    mainwindow.h \
    s21_credit.h \
    s21_depozit.h \
    s21_smart_calc.h \
    s21_struct.h \
    qcustomplot.h

FORMS += \
    calculator.ui \
    credit.ui \
    depozit.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
