QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additionOperation.cpp \
    binaryOperation.cpp \
    cosOperation.cpp \
    ctgOperation.cpp \
    divisionOperation.cpp \
    facadeOperationResult.cpp \
    main.cpp \
    mainwindow.cpp \
    multiplicationOperation.cpp \
    operation.cpp \
    reciprocalOperation.cpp \
    sinOperation.cpp \
    sqrtOperation.cpp \
    subtractionOperation.cpp \
    tgOperation.cpp \
    unaryOperation.cpp

HEADERS += \
    additionOperation.h \
    binaryOperation.h \
    cosOperation.h \
    ctgOperation.h \
    divisionOperation.h \
    facadeOperationResult.h \
    mainwindow.h \
    multiplicationOperation.h \
    operation.h \
    reciprocalOperation.h \
    sinOperation.h \
    sqrtOperation.h \
    subtractionOperation.h \
    tgOperation.h \
    unaryOperation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
