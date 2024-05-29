QT       += core gui
QT       += printsupport
QT       += charts
QT       += core gui printsupport
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountsettings.cpp \
    animatedlabel.cpp \
    enter.cpp \
    forgotpass.cpp \
    login.cpp \
    loginsession.cpp \
    main.cpp \
    otp.cpp \
    passwordsec.cpp \
    reports.cpp \
    signup.cpp \
    wardenfort.cpp



HEADERS += \
    accountsettings.h \
    animatedlabel.h \
    enter.h \
    forgotpass.h \
    login.h \
    loginsession.h \
    otp.h \
    passwordsec.h \
    reports.h \
    signup.h \
    wardenfort.h



FORMS += \
    accountsettings.ui \
    dialog.ui \
    enter.ui \
    forgotpass.ui \
    form.ui \
    login.ui \
    newdb.ui \
    otp.ui \
    passwordsec.ui \
    reports.ui \
    signup.ui \
    wardenfort.ui





INCLUDEPATH += C:\npcap\Include
LIBS += -LC:\npcap\Lib\x64 -lwpcap



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    img.qrc \
    wardenfort.qrc
