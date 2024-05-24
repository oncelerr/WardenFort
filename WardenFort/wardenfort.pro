QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountsettings.cpp \
    animatedlabel.cpp \
    chat.cpp \
    enter.cpp \
    forgotpass.cpp \
    login.cpp \
    loginsession.cpp \
    main.cpp \
    otp.cpp \
    passwordsec.cpp \
    signup.cpp \
    wardenfort.cpp

HEADERS += \
    accountsettings.h \
    animatedlabel.h \
    chat.h \
    enter.h \
    forgotpass.h \
    login.h \
    loginsession.h \
    otp.h \
    passwordsec.h \
    signup.h \
    wardenfort.h

FORMS += \
    accountsettings.ui \
    chat.ui \
    dialog.ui \
    enter.ui \
    forgotpass.ui \
    form.ui \
    login.ui \
    newdb.ui \
    otp.ui \
    passwordsec.ui \
    signup.ui \
    wardenfort.ui

QT += charts
QT += core gui printsupport
QT += network
QT += sql

INCLUDEPATH += C:\npcap\Include
LIBS += -LC:\npcap\Lib\x64 -lwpcap



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    wardenfort.qrc
