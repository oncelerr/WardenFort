/********************************************************************************
** Form generated from reading UI file 'accountsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSETTINGS_H
#define UI_ACCOUNTSETTINGS_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountSettings
{
public:
    QWidget *centralwidget;
    QFrame *profileTab_5;
    QPushButton *accountButton_6;
    QFrame *profileTab;
    QLabel *user_icon;
    QLabel *profile_text;
    QPushButton *dd5;
    QPushButton *dd1;
    QFrame *frame;
    QLabel *frame_5;
    QLabel *welcome_text;
    QLabel *wardenfort;
    QFrame *frame_2;
    QFrame *alertsTab;
    QLabel *alert_icon;
    QLabel *alert_text;
    QPushButton *dd6;
    QPushButton *dd2;
    QFrame *reportsTab;
    QLabel *report_icon;
    QLabel *report_text;
    QPushButton *dd3;
    QPushButton *dd7;
    QFrame *calendarTab;
    QLabel *cal_text;
    QLabel *cal_icon;
    QPushButton *dd8;
    QPushButton *dd4;
    QFrame *profileTab_2;
    QPushButton *accountButton;
    QPushButton *passwordButton;
    QPushButton *logoutButton;
    QFrame *profileTab_3;
    QPushButton *accountButton_3;
    QPushButton *passwordButton_3;
    QFrame *profileTab_4;
    QPushButton *accountButton_4;
    QFrame *frame_3;
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

    void setupUi(QMainWindow *accountSettings)
    {
        if (accountSettings->objectName().isEmpty())
            accountSettings->setObjectName("accountSettings");
        accountSettings->resize(1088, 567);
        accountSettings->setStyleSheet(QString::fromUtf8("background-color: #191F32;"));
        centralwidget = new QWidget(accountSettings);
        centralwidget->setObjectName("centralwidget");
        profileTab_5 = new QFrame(centralwidget);
        profileTab_5->setObjectName("profileTab_5");
        profileTab_5->setGeometry(QRect(21, 436, 219, 31));
        profileTab_5->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_5->setFrameShape(QFrame::StyledPanel);
        profileTab_5->setFrameShadow(QFrame::Raised);
        accountButton_6 = new QPushButton(profileTab_5);
        accountButton_6->setObjectName("accountButton_6");
        accountButton_6->setGeometry(QRect(-4, 5, 111, 24));
        accountButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        profileTab = new QFrame(centralwidget);
        profileTab->setObjectName("profileTab");
        profileTab->setGeometry(QRect(21, 237, 221, 50));
        profileTab->setStyleSheet(QString::fromUtf8("QFrame#profileTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        profileTab->setFrameShape(QFrame::StyledPanel);
        profileTab->setFrameShadow(QFrame::Raised);
        user_icon = new QLabel(profileTab);
        user_icon->setObjectName("user_icon");
        user_icon->setGeometry(QRect(20, 5, 30, 41));
        user_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        user_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/user_icon.png")));
        profile_text = new QLabel(profileTab);
        profile_text->setObjectName("profile_text");
        profile_text->setGeometry(QRect(50, 15, 60, 21));
        profile_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd5 = new QPushButton(profileTab);
        dd5->setObjectName("dd5");
        dd5->setEnabled(true);
        dd5->setGeometry(QRect(180, 15, 20, 24));
        dd5->setMaximumSize(QSize(20, 24));
        dd5->setCursor(QCursor(Qt::PointingHandCursor));
        dd5->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/wardenfort/dd1_rotated.png"), QSize(), QIcon::Normal, QIcon::Off);
        dd5->setIcon(icon);
        dd1 = new QPushButton(profileTab);
        dd1->setObjectName("dd1");
        dd1->setGeometry(QRect(180, 15, 20, 24));
        dd1->setMaximumSize(QSize(20, 24));
        dd1->setCursor(QCursor(Qt::PointingHandCursor));
        dd1->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/wardenfort/dd1.png"), QSize(), QIcon::Normal, QIcon::Off);
        dd1->setIcon(icon1);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(21, 23, 221, 521));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame\n"
"{background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_5 = new QLabel(frame);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(39, 18, 151, 171));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        frame_5->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/frame.png")));
        welcome_text = new QLabel(frame);
        welcome_text->setObjectName("welcome_text");
        welcome_text->setGeometry(QRect(0, 170, 221, 21));
        welcome_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        wardenfort = new QLabel(frame);
        wardenfort->setObjectName("wardenfort");
        wardenfort->setGeometry(QRect(8, 16, 191, 16));
        wardenfort->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/wardenfort_word (1).png")));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 214, 221, 307));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 93, 128);\n"
"border-top-right-radius: 25px;\n"
"border-top-left-radius: 25px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        alertsTab = new QFrame(centralwidget);
        alertsTab->setObjectName("alertsTab");
        alertsTab->setGeometry(QRect(21, 287, 221, 50));
        alertsTab->setStyleSheet(QString::fromUtf8("QFrame#alertsTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        alertsTab->setFrameShape(QFrame::StyledPanel);
        alertsTab->setFrameShadow(QFrame::Raised);
        alert_icon = new QLabel(alertsTab);
        alert_icon->setObjectName("alert_icon");
        alert_icon->setGeometry(QRect(20, 5, 21, 41));
        alert_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        alert_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/notif_icon.png")));
        alert_text = new QLabel(alertsTab);
        alert_text->setObjectName("alert_text");
        alert_text->setGeometry(QRect(50, 15, 60, 21));
        alert_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd6 = new QPushButton(alertsTab);
        dd6->setObjectName("dd6");
        dd6->setEnabled(true);
        dd6->setGeometry(QRect(180, 15, 20, 24));
        dd6->setMaximumSize(QSize(20, 24));
        dd6->setCursor(QCursor(Qt::PointingHandCursor));
        dd6->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd6->setIcon(icon);
        dd2 = new QPushButton(alertsTab);
        dd2->setObjectName("dd2");
        dd2->setGeometry(QRect(180, 15, 20, 24));
        dd2->setMaximumSize(QSize(20, 24));
        dd2->setCursor(QCursor(Qt::PointingHandCursor));
        dd2->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd2->setIcon(icon1);
        reportsTab = new QFrame(centralwidget);
        reportsTab->setObjectName("reportsTab");
        reportsTab->setGeometry(QRect(21, 337, 221, 50));
        reportsTab->setStyleSheet(QString::fromUtf8("QFrame#reportsTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        reportsTab->setFrameShape(QFrame::StyledPanel);
        reportsTab->setFrameShadow(QFrame::Raised);
        report_icon = new QLabel(reportsTab);
        report_icon->setObjectName("report_icon");
        report_icon->setGeometry(QRect(20, 10, 31, 31));
        report_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        report_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/report_icon.png")));
        report_text = new QLabel(reportsTab);
        report_text->setObjectName("report_text");
        report_text->setGeometry(QRect(50, 15, 60, 21));
        report_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        dd3 = new QPushButton(reportsTab);
        dd3->setObjectName("dd3");
        dd3->setGeometry(QRect(180, 15, 20, 24));
        dd3->setMaximumSize(QSize(20, 24));
        dd3->setCursor(QCursor(Qt::PointingHandCursor));
        dd3->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd3->setIcon(icon1);
        dd7 = new QPushButton(reportsTab);
        dd7->setObjectName("dd7");
        dd7->setEnabled(true);
        dd7->setGeometry(QRect(180, 15, 20, 24));
        dd7->setMaximumSize(QSize(20, 24));
        dd7->setCursor(QCursor(Qt::PointingHandCursor));
        dd7->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd7->setIcon(icon);
        calendarTab = new QFrame(centralwidget);
        calendarTab->setObjectName("calendarTab");
        calendarTab->setGeometry(QRect(21, 387, 221, 50));
        calendarTab->setStyleSheet(QString::fromUtf8("QFrame#calendarTab{\n"
"border-top: 1px solid rgb(25, 31, 50);\n"
"background-color: rgba(44, 60, 75, 0);\n"
"border-radius: 0px;\n"
"}"));
        calendarTab->setFrameShape(QFrame::StyledPanel);
        calendarTab->setFrameShadow(QFrame::Raised);
        cal_text = new QLabel(calendarTab);
        cal_text->setObjectName("cal_text");
        cal_text->setGeometry(QRect(50, 15, 121, 21));
        cal_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);"));
        cal_icon = new QLabel(calendarTab);
        cal_icon->setObjectName("cal_icon");
        cal_icon->setGeometry(QRect(20, 10, 41, 31));
        cal_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cal_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/cal_icon.png")));
        dd8 = new QPushButton(calendarTab);
        dd8->setObjectName("dd8");
        dd8->setEnabled(true);
        dd8->setGeometry(QRect(180, 15, 20, 24));
        dd8->setMaximumSize(QSize(20, 24));
        dd8->setCursor(QCursor(Qt::PointingHandCursor));
        dd8->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd8->setIcon(icon);
        dd4 = new QPushButton(calendarTab);
        dd4->setObjectName("dd4");
        dd4->setGeometry(QRect(180, 15, 20, 24));
        dd4->setMaximumSize(QSize(20, 24));
        dd4->setCursor(QCursor(Qt::PointingHandCursor));
        dd4->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        dd4->setIcon(icon1);
        profileTab_2 = new QFrame(centralwidget);
        profileTab_2->setObjectName("profileTab_2");
        profileTab_2->setGeometry(QRect(22, 285, 219, 91));
        profileTab_2->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_2->setFrameShape(QFrame::StyledPanel);
        profileTab_2->setFrameShadow(QFrame::Raised);
        accountButton = new QPushButton(profileTab_2);
        accountButton->setObjectName("accountButton");
        accountButton->setGeometry(QRect(15, 5, 111, 24));
        accountButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        passwordButton = new QPushButton(profileTab_2);
        passwordButton->setObjectName("passwordButton");
        passwordButton->setGeometry(QRect(15, 30, 141, 24));
        passwordButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"}"));
        logoutButton = new QPushButton(profileTab_2);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(25, 55, 51, 24));
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: red;\n"
"}"));
        profileTab_3 = new QFrame(centralwidget);
        profileTab_3->setObjectName("profileTab_3");
        profileTab_3->setGeometry(QRect(22, 334, 219, 61));
        profileTab_3->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_3->setFrameShape(QFrame::StyledPanel);
        profileTab_3->setFrameShadow(QFrame::Raised);
        accountButton_3 = new QPushButton(profileTab_3);
        accountButton_3->setObjectName("accountButton_3");
        accountButton_3->setGeometry(QRect(3, 5, 111, 24));
        accountButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        passwordButton_3 = new QPushButton(profileTab_3);
        passwordButton_3->setObjectName("passwordButton_3");
        passwordButton_3->setGeometry(QRect(11, 30, 141, 24));
        passwordButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"}"));
        profileTab_4 = new QFrame(centralwidget);
        profileTab_4->setObjectName("profileTab_4");
        profileTab_4->setGeometry(QRect(33, 388, 219, 31));
        profileTab_4->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0);\n"
""));
        profileTab_4->setFrameShape(QFrame::StyledPanel);
        profileTab_4->setFrameShadow(QFrame::Raised);
        accountButton_4 = new QPushButton(profileTab_4);
        accountButton_4->setObjectName("accountButton_4");
        accountButton_4->setGeometry(QRect(3, 5, 111, 24));
        accountButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 8pt \"Inter\";\n"
"background-color: transparent;\n"
"color: white;\n"
"\n"
"}"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(260, 22, 781, 521));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    /* Standard linear-gradient for most browsers */\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                 stop: 0 hsla(200, 71%, 19%, 1), /* Start color */\n"
"                                 stop: 1 hsla(221, 37%, 15%, 1)); /* End color */\n"
"border:0;\n"
" border-radius: 10px; \n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, -10, 131, 131));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/Ellipse.png")));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 80, 31, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Downloads/profileButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(25, 24));
        pushButton->setFlat(true);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 0, 111, 121));
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 140, 221, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(16);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 190, 631, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(11);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 240, 71, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setBold(true);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(300, 240, 71, 16));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 263, 220, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 263, 220, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_10 = new QLabel(frame_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 310, 71, 16));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 330, 220, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        dateEdit = new QDateEdit(frame_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(300, 330, 220, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(300, 310, 91, 16));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 380, 91, 16));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(40, 400, 220, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(40, 460, 220, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: #191F32;\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 440, 91, 16));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 400, 91, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 460, 91, 31));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        label_15 = new QLabel(frame_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(390, 360, 111, 121));
        label_15->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(390, 550, 631, 16));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_18 = new QLabel(frame_3);
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
        accountSettings->setCentralWidget(centralwidget);
        frame->raise();
        profileTab_5->raise();
        profileTab->raise();
        alertsTab->raise();
        reportsTab->raise();
        calendarTab->raise();
        profileTab_2->raise();
        profileTab_3->raise();
        profileTab_4->raise();
        frame_3->raise();

        retranslateUi(accountSettings);

        QMetaObject::connectSlotsByName(accountSettings);
    } // setupUi

    void retranslateUi(QMainWindow *accountSettings)
    {
        accountSettings->setWindowTitle(QCoreApplication::translate("accountSettings", "accountSettings", nullptr));
        accountButton_6->setText(QCoreApplication::translate("accountSettings", "Calendar", nullptr));
        user_icon->setText(QString());
        profile_text->setText(QCoreApplication::translate("accountSettings", "PROFILE", nullptr));
        dd5->setText(QString());
#if QT_CONFIG(shortcut)
        dd5->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd1->setText(QString());
#if QT_CONFIG(shortcut)
        dd1->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        frame_5->setText(QString());
        welcome_text->setText(QCoreApplication::translate("accountSettings", "Welcome, User!", nullptr));
        wardenfort->setText(QString());
        alert_icon->setText(QString());
        alert_text->setText(QCoreApplication::translate("accountSettings", "ALERTS", nullptr));
        dd6->setText(QString());
#if QT_CONFIG(shortcut)
        dd6->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd2->setText(QString());
#if QT_CONFIG(shortcut)
        dd2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        report_icon->setText(QString());
        report_text->setText(QCoreApplication::translate("accountSettings", "REPORTS", nullptr));
        dd3->setText(QString());
#if QT_CONFIG(shortcut)
        dd3->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd7->setText(QString());
#if QT_CONFIG(shortcut)
        dd7->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        cal_text->setText(QCoreApplication::translate("accountSettings", "EVENT CALENDAR", nullptr));
        cal_icon->setText(QString());
        dd8->setText(QString());
#if QT_CONFIG(shortcut)
        dd8->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd4->setText(QString());
#if QT_CONFIG(shortcut)
        dd4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        accountButton->setText(QCoreApplication::translate("accountSettings", "Account Settings", nullptr));
        passwordButton->setText(QCoreApplication::translate("accountSettings", "Password and Security", nullptr));
        logoutButton->setText(QCoreApplication::translate("accountSettings", "Log Out", nullptr));
        accountButton_3->setText(QCoreApplication::translate("accountSettings", "Notifications", nullptr));
        passwordButton_3->setText(QCoreApplication::translate("accountSettings", "Calendar Notifications", nullptr));
        accountButton_4->setText(QCoreApplication::translate("accountSettings", "Generate Report", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class accountSettings: public Ui_accountSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSETTINGS_H
