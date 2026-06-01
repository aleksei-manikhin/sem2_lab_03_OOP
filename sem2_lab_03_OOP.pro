QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatorCommand.cpp \
    calculatorLogic.cpp \
    facade.cpp \
    operations/additionOperation.cpp \
    operations/binaryOperation.cpp \
    operations/cosOperation.cpp \
    operations/ctgOperation.cpp \
    operations/divisionOperation.cpp \
    expressionBuilder.cpp \
    expressionEvaluator.cpp \
    facadeOperationResult.cpp \
    main.cpp \
    mainwindow.cpp \
    operations/multiplicationOperation.cpp \
    operations/operation.cpp \
    operations/operationRegistry.cpp \
    operations/reciprocalOperation.cpp \
    rpnEvaluator.cpp \
    shuntingYard.cpp \
    operations/sinOperation.cpp \
    operations/sqrtOperation.cpp \
    operations/subtractionOperation.cpp \
    operations/tgOperation.cpp \
    token.cpp \
    tokenizer.cpp \
    operations/unaryOperation.cpp

HEADERS += \
    calculatorCommand.h \
    calculatorLogic.h \
    facade.h \
    operations/additionOperation.h \
    operations/binaryOperation.h \
    operations/cosOperation.h \
    operations/ctgOperation.h \
    operations/divisionOperation.h \
    expressionBuilder.h \
    expressionEvaluator.h \
    facadeOperationResult.h \
    mainwindow.h \
    operations/multiplicationOperation.h \
    operations/operation.h \
    operations/operationRegistry.h \
    operations/reciprocalOperation.h \
    rpnEvaluator.h \
    shuntingYard.h \
    operations/sinOperation.h \
    operations/sqrtOperation.h \
    operations/subtractionOperation.h \
    operations/tgOperation.h \
    token.h \
    tokenizer.h \
    operations/unaryOperation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
