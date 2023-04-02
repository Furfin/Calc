QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qcustomplot.cpp \
    s21_plotwindow.cpp \
    s21_shunting_yard.c \
    main.cpp \
    s21_smart_calc_window.cpp

HEADERS += \
    qcustomplot.h \
    s21_plotwindow.h \
    s21_shunting_yard.h \
    s21_smart_calc_window.h


FORMS += \
    s21_plotwindow.ui \
    s21_smart_calc_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
