/********************************************************************************
** Form generated from reading UI file 'accountsetting.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSETTING_H
#define UI_ACCOUNTSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountSettings
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_10;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_18;
    QFrame *profileTab_5;
    QPushButton *accountButton_13;
    QFrame *calendarTab;
    QLabel *cal_text_4;
    QLabel *cal_icon_4;
    QPushButton *dd8_4;
    QPushButton *dd4_4;
    QFrame *frame;
    QLabel *frame_10;
    QLabel *welcome_text_4;
    QLabel *wardenfort_4;
    QFrame *frame_11;
    QFrame *profileTab_4;
    QPushButton *accountButton_14;
    QFrame *profileTab;
    QLabel *user_icon_4;
    QLabel *profile_text_4;
    QPushButton *dd5_4;
    QPushButton *dd1_4;
    QFrame *alertsTab;
    QLabel *alert_icon_4;
    QLabel *alert_text_4;
    QPushButton *dd6_4;
    QPushButton *dd2_4;
    QFrame *profileTab_3;
    QPushButton *accountButton_15;
    QPushButton *passwordButton_7;
    QFrame *reportsTab;
    QLabel *report_icon_4;
    QLabel *report_text_4;
    QPushButton *dd3_4;
    QPushButton *dd7_4;
    QFrame *profileTab_2;
    QPushButton *accountButton_16;
    QPushButton *passwordButton_8;
    QPushButton *logoutButton_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *accountSettings)
    {
        if (accountSettings->objectName().isEmpty())
            accountSettings->setObjectName("accountSettings");
        accountSettings->resize(1088, 567);
        accountSettings->setStyleSheet(QString::fromUtf8("background-color: #191F32;"));
        centralwidget = new QWidget(accountSettings);
        centralwidget->setObjectName("centralwidget");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(280, 20, 781, 521));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    /* Standard linear-gradient for most browsers */\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                 stop: 0 hsla(200, 71%, 19%, 1), /* Start color */\n"
"                                 stop: 1 hsla(221, 37%, 15%, 1)); /* End color */\n"
"border:0;\n"
" border-radius: 10px; \n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, -10, 131, 131));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/Ellipse.png")));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 80, 31, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/profileButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 24));
        pushButton->setFlat(true);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 0, 111, 121));
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 140, 221, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(16);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 190, 631, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(11);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 240, 71, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setBold(true);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(300, 240, 71, 16));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 260, 220, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 260, 220, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 310, 71, 16));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 330, 220, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(300, 330, 220, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(300, 310, 91, 16));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 380, 91, 16));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(40, 400, 220, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        lineEdit_4 = new QLineEdit(frame_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(40, 460, 220, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 440, 91, 16));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 400, 91, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 460, 91, 31));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(390, 360, 111, 121));
        label_15->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(390, 550, 631, 16));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(680, 290, 111, 121));
        label_18->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_4->raise();
        label_5->raise();
        pushButton->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        label_10->raise();
        comboBox->raise();
        dateEdit->raise();
        label_11->raise();
        label_12->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        label_13->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        label_15->raise();
        label_16->raise();
        label_18->raise();
        profileTab_5 = new QFrame(centralwidget);
        profileTab_5->setObjectName("profileTab_5");
        profileTab_5->setGeometry(QRect(29, 431, 219, 31));
        profileTab_5->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_5->setFrameShape(QFrame::StyledPanel);
        profileTab_5->setFrameShadow(QFrame::Raised);
        accountButton_13 = new QPushButton(profileTab_5);
        accountButton_13->setObjectName("accountButton_13");
        accountButton_13->setGeometry(QRect(-4, 5, 111, 24));
        accountButton_13->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        calendarTab = new QFrame(centralwidget);
        calendarTab->setObjectName("calendarTab");
        calendarTab->setGeometry(QRect(29, 382, 221, 50));
        calendarTab->setStyleSheet(QString::fromUtf8("QFrame#calendarTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        calendarTab->setFrameShape(QFrame::StyledPanel);
        calendarTab->setFrameShadow(QFrame::Raised);
        cal_text_4 = new QLabel(calendarTab);
        cal_text_4->setObjectName("cal_text_4");
        cal_text_4->setGeometry(QRect(50, 15, 121, 21));
        cal_text_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        cal_icon_4 = new QLabel(calendarTab);
        cal_icon_4->setObjectName("cal_icon_4");
        cal_icon_4->setGeometry(QRect(20, 10, 41, 31));
        cal_icon_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cal_icon_4->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/cal_icon.png")));
        dd8_4 = new QPushButton(calendarTab);
        dd8_4->setObjectName("dd8_4");
        dd8_4->setEnabled(true);
        dd8_4->setGeometry(QRect(180, 15, 20, 24));
        dd8_4->setMaximumSize(QSize(20, 24));
        dd8_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd8_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/wardenfort/dd1_rotated.png"), QSize(), QIcon::Normal, QIcon::Off);
        dd8_4->setIcon(icon1);
        dd4_4 = new QPushButton(calendarTab);
        dd4_4->setObjectName("dd4_4");
        dd4_4->setGeometry(QRect(180, 15, 20, 24));
        dd4_4->setMaximumSize(QSize(20, 24));
        dd4_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd4_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/wardenfort/dd1.png"), QSize(), QIcon::Normal, QIcon::Off);
        dd4_4->setIcon(icon2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(29, 18, 221, 521));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame\n"
"{background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_10 = new QLabel(frame);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(39, 18, 151, 171));
        frame_10->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame_10->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/frame.png")));
        welcome_text_4 = new QLabel(frame);
        welcome_text_4->setObjectName("welcome_text_4");
        welcome_text_4->setGeometry(QRect(0, 170, 221, 21));
        welcome_text_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        wardenfort_4 = new QLabel(frame);
        wardenfort_4->setObjectName("wardenfort_4");
        wardenfort_4->setGeometry(QRect(8, 16, 191, 16));
        wardenfort_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort_4->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/wardenfort_word (1).png")));
        frame_11 = new QFrame(frame);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(0, 214, 221, 311));
        frame_11->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 93, 128);\n"
"border-top-right-radius: 25px;\n"
"border-top-left-radius: 25px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        profileTab_4 = new QFrame(centralwidget);
        profileTab_4->setObjectName("profileTab_4");
        profileTab_4->setGeometry(QRect(41, 383, 219, 31));
        profileTab_4->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_4->setFrameShape(QFrame::StyledPanel);
        profileTab_4->setFrameShadow(QFrame::Raised);
        accountButton_14 = new QPushButton(profileTab_4);
        accountButton_14->setObjectName("accountButton_14");
        accountButton_14->setGeometry(QRect(3, 5, 111, 24));
        accountButton_14->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        profileTab = new QFrame(centralwidget);
        profileTab->setObjectName("profileTab");
        profileTab->setGeometry(QRect(29, 232, 221, 50));
        profileTab->setStyleSheet(QString::fromUtf8("QFrame#profileTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        profileTab->setFrameShape(QFrame::StyledPanel);
        profileTab->setFrameShadow(QFrame::Raised);
        user_icon_4 = new QLabel(profileTab);
        user_icon_4->setObjectName("user_icon_4");
        user_icon_4->setGeometry(QRect(20, 5, 30, 41));
        user_icon_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        user_icon_4->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/user_icon.png")));
        profile_text_4 = new QLabel(profileTab);
        profile_text_4->setObjectName("profile_text_4");
        profile_text_4->setGeometry(QRect(50, 15, 60, 21));
        profile_text_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd5_4 = new QPushButton(profileTab);
        dd5_4->setObjectName("dd5_4");
        dd5_4->setEnabled(true);
        dd5_4->setGeometry(QRect(180, 15, 20, 24));
        dd5_4->setMaximumSize(QSize(20, 24));
        dd5_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd5_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd5_4->setIcon(icon1);
        dd1_4 = new QPushButton(profileTab);
        dd1_4->setObjectName("dd1_4");
        dd1_4->setGeometry(QRect(180, 15, 20, 24));
        dd1_4->setMaximumSize(QSize(20, 24));
        dd1_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd1_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd1_4->setIcon(icon2);
        alertsTab = new QFrame(centralwidget);
        alertsTab->setObjectName("alertsTab");
        alertsTab->setGeometry(QRect(29, 282, 221, 50));
        alertsTab->setStyleSheet(QString::fromUtf8("QFrame#alertsTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        alertsTab->setFrameShape(QFrame::StyledPanel);
        alertsTab->setFrameShadow(QFrame::Raised);
        alert_icon_4 = new QLabel(alertsTab);
        alert_icon_4->setObjectName("alert_icon_4");
        alert_icon_4->setGeometry(QRect(20, 5, 21, 41));
        alert_icon_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        alert_icon_4->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/notif_icon.png")));
        alert_text_4 = new QLabel(alertsTab);
        alert_text_4->setObjectName("alert_text_4");
        alert_text_4->setGeometry(QRect(50, 15, 60, 21));
        alert_text_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd6_4 = new QPushButton(alertsTab);
        dd6_4->setObjectName("dd6_4");
        dd6_4->setEnabled(true);
        dd6_4->setGeometry(QRect(180, 15, 20, 24));
        dd6_4->setMaximumSize(QSize(20, 24));
        dd6_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd6_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd6_4->setIcon(icon1);
        dd2_4 = new QPushButton(alertsTab);
        dd2_4->setObjectName("dd2_4");
        dd2_4->setGeometry(QRect(180, 15, 20, 24));
        dd2_4->setMaximumSize(QSize(20, 24));
        dd2_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd2_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd2_4->setIcon(icon2);
        profileTab_3 = new QFrame(centralwidget);
        profileTab_3->setObjectName("profileTab_3");
        profileTab_3->setGeometry(QRect(30, 329, 219, 61));
        profileTab_3->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_3->setFrameShape(QFrame::StyledPanel);
        profileTab_3->setFrameShadow(QFrame::Raised);
        accountButton_15 = new QPushButton(profileTab_3);
        accountButton_15->setObjectName("accountButton_15");
        accountButton_15->setGeometry(QRect(3, 5, 111, 24));
        accountButton_15->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        passwordButton_7 = new QPushButton(profileTab_3);
        passwordButton_7->setObjectName("passwordButton_7");
        passwordButton_7->setGeometry(QRect(11, 30, 141, 24));
        passwordButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"}"));
        reportsTab = new QFrame(centralwidget);
        reportsTab->setObjectName("reportsTab");
        reportsTab->setGeometry(QRect(29, 332, 221, 50));
        reportsTab->setStyleSheet(QString::fromUtf8("QFrame#reportsTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        reportsTab->setFrameShape(QFrame::StyledPanel);
        reportsTab->setFrameShadow(QFrame::Raised);
        report_icon_4 = new QLabel(reportsTab);
        report_icon_4->setObjectName("report_icon_4");
        report_icon_4->setGeometry(QRect(20, 10, 31, 31));
        report_icon_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        report_icon_4->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/report_icon.png")));
        report_text_4 = new QLabel(reportsTab);
        report_text_4->setObjectName("report_text_4");
        report_text_4->setGeometry(QRect(50, 15, 60, 21));
        report_text_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd3_4 = new QPushButton(reportsTab);
        dd3_4->setObjectName("dd3_4");
        dd3_4->setGeometry(QRect(180, 15, 20, 24));
        dd3_4->setMaximumSize(QSize(20, 24));
        dd3_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd3_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd3_4->setIcon(icon2);
        dd7_4 = new QPushButton(reportsTab);
        dd7_4->setObjectName("dd7_4");
        dd7_4->setEnabled(true);
        dd7_4->setGeometry(QRect(180, 15, 20, 24));
        dd7_4->setMaximumSize(QSize(20, 24));
        dd7_4->setCursor(QCursor(Qt::PointingHandCursor));
        dd7_4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd7_4->setIcon(icon1);
        profileTab_2 = new QFrame(centralwidget);
        profileTab_2->setObjectName("profileTab_2");
        profileTab_2->setGeometry(QRect(30, 280, 219, 91));
        profileTab_2->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_2->setFrameShape(QFrame::StyledPanel);
        profileTab_2->setFrameShadow(QFrame::Raised);
        accountButton_16 = new QPushButton(profileTab_2);
        accountButton_16->setObjectName("accountButton_16");
        accountButton_16->setGeometry(QRect(15, 5, 111, 24));
        accountButton_16->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        passwordButton_8 = new QPushButton(profileTab_2);
        passwordButton_8->setObjectName("passwordButton_8");
        passwordButton_8->setGeometry(QRect(15, 30, 141, 24));
        passwordButton_8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"}"));
        logoutButton_4 = new QPushButton(profileTab_2);
        logoutButton_4->setObjectName("logoutButton_4");
        logoutButton_4->setGeometry(QRect(25, 55, 51, 24));
        logoutButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: red;\n"
"}"));
        accountSettings->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(accountSettings);
        statusbar->setObjectName("statusbar");
        accountSettings->setStatusBar(statusbar);

        retranslateUi(accountSettings);

        QMetaObject::connectSlotsByName(accountSettings);
    } // setupUi

    void retranslateUi(QMainWindow *accountSettings)
    {
        accountSettings->setWindowTitle(QCoreApplication::translate("accountSettings", "accountSettings", nullptr));
        label_4->setText(QString());
        pushButton->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("accountSettings", "PERSONAL DETAILS", nullptr));
        label_7->setText(QCoreApplication::translate("accountSettings", "WardenFort uses this information to verify your identity and to keep our community safe. ", nullptr));
        label_8->setText(QCoreApplication::translate("accountSettings", "First Name", nullptr));
        label_9->setText(QCoreApplication::translate("accountSettings", "Last Name", nullptr));
        label_10->setText(QCoreApplication::translate("accountSettings", "Gender", nullptr));
        label_11->setText(QCoreApplication::translate("accountSettings", "Date of Birth", nullptr));
        label_12->setText(QCoreApplication::translate("accountSettings", "Email Address", nullptr));
        label_13->setText(QCoreApplication::translate("accountSettings", "Username", nullptr));
        pushButton_2->setText(QCoreApplication::translate("accountSettings", "Change", nullptr));
        pushButton_3->setText(QCoreApplication::translate("accountSettings", "Change", nullptr));
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("accountSettings", "WardenFort uses this information to verify your identity and to keep our community safe. ", nullptr));
        label_18->setText(QString());
        accountButton_13->setText(QCoreApplication::translate("accountSettings", "Calendar", nullptr));
        cal_text_4->setText(QCoreApplication::translate("accountSettings", "EVENT CALENDAR", nullptr));
        cal_icon_4->setText(QString());
        dd8_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd8_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd4_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd4_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        frame_10->setText(QString());
        welcome_text_4->setText(QCoreApplication::translate("accountSettings", "Welcome, User!", nullptr));
        wardenfort_4->setText(QString());
        accountButton_14->setText(QCoreApplication::translate("accountSettings", "Generate Report", nullptr));
        user_icon_4->setText(QString());
        profile_text_4->setText(QCoreApplication::translate("accountSettings", "PROFILE", nullptr));
        dd5_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd5_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd1_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd1_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        alert_icon_4->setText(QString());
        alert_text_4->setText(QCoreApplication::translate("accountSettings", "ALERTS", nullptr));
        dd6_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd6_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd2_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd2_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        accountButton_15->setText(QCoreApplication::translate("accountSettings", "Notifications", nullptr));
        passwordButton_7->setText(QCoreApplication::translate("accountSettings", "Calendar Notifications", nullptr));
        report_icon_4->setText(QString());
        report_text_4->setText(QCoreApplication::translate("accountSettings", "REPORTS", nullptr));
        dd3_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd3_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd7_4->setText(QString());
#if QT_CONFIG(shortcut)
        dd7_4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        accountButton_16->setText(QCoreApplication::translate("accountSettings", "Account Settings", nullptr));
        passwordButton_8->setText(QCoreApplication::translate("accountSettings", "Password and Security", nullptr));
        logoutButton_4->setText(QCoreApplication::translate("accountSettings", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountSettings: public Ui_accountSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSETTING_H
