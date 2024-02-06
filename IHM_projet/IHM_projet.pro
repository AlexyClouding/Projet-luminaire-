QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    interface_information.cpp \
    interface_parametre.cpp \
    main.cpp \
    interface_principale.cpp

HEADERS += \
    interface_information.h \
    interface_parametre.h \
    interface_principale.h

FORMS += \
    interface_information.ui \
    interface_parametre.ui \
    interface_principale.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
