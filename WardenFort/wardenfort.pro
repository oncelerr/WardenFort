QT       += core gui
QT       += printsupport

QT       += core gui printsupport
QT       += network
QT       += sql
QT += websockets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountwidget.cpp \
    animatedlabel.cpp \
    calendar.cpp \
    calendarnotifications.cpp\
    chatmessagewidget.cpp \
    chatswidget.cpp \
    contacts.cpp \
    customcalendarwidget.cpp \
    eventdialog.cpp \
    notificationwidget.cpp\
    database.cpp \
    enter.cpp \
    forgotpass.cpp \
    globals.cpp \
    login.cpp \
    loginsession.cpp \
    main.cpp \
    notifwidget.cpp \
    otp.cpp \
    passwordsecwidget.cpp \
    reports.cpp \
    reportswidget.cpp \
    signup.cpp \
    wardenfort.cpp



HEADERS += \
    accountwidget.h \
    calendar.h \
    calendarnotifications.h\
    chatmessagewidget.h \
    chatswidget.h \
    contacts.h \
    customcalendarwidget.h \
    eventdialog.h \
    notificationwidget.h\
    animatedlabel.h \
    database.h \
    enter.h \
    forgotpass.h \
    globals.h \
    login.h \
    loginsession.h \
    notifwidget.h \
    otp.h \
    passwordsecwidget.h \
    reports.h \
    reportswidget.h \
    signup.h \
    wardenfort.h



FORMS += \
    accountwidget.ui \
    calendar.ui \
    calendarnotifications.ui\
    chatmessagewidget.ui \
    chatswidget.ui \
    contacts.ui \
    eventdialog.ui \
    notificationwidget.ui\
    dialog.ui \
    enter.ui \
    forgotpass.ui \
    form.ui \
    login.ui \
    newdb.ui \
    notifwidget.ui \
    otp.ui \
    passwordsecwidget.ui \
    reports.ui \
    reportswidget.ui \
    signup.ui \
    wardenfort.ui





INCLUDEPATH += C:\npcap\Include
LIBS += -LC:\npcap\Lib\x64 -lwpcap



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    wardenfort.qrc
