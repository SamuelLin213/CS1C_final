QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ellipse.cpp \
    Line.cpp \
    Polygon.cpp \
    Polyline.cpp \
    Rectangle.cpp \
    Shapes.cpp \
    Text.cpp \
    canvas.cpp \
    contactWindow.cpp \
    loginWindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Ellipse.h \
    Line.h \
    Polygon.h \
    Polyline.h \
    Rectangle.h \
    Shapes.h \
    Text.h \
    canvas.h \
    contactWindow.h \
    loginWindow.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fuck.pro.user \
    logo.png \
    shapes.txt

RESOURCES += \
    application.qrc
