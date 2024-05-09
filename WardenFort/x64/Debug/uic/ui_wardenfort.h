/********************************************************************************
** Form generated from reading UI file 'wardenfort.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARDENFORT_H
#define UI_WARDENFORT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WardenFort
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *frame_5;
    QLabel *welcome_text;
    QLabel *wardenfort;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *criticalDetections;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QFrame *profileTab;
    QLabel *user_icon;
    QLabel *profile_text;
    QPushButton *dd5;
    QPushButton *dd1;
    QFrame *alertsTab;
    QLabel *alert_icon;
    QLabel *alert_text;
    QPushButton *dd6;
    QPushButton *dd2;
    QFrame *profileTab_2;
    QPushButton *accountButton;
    QPushButton *passwordButton;
    QPushButton *logoutButton;
    QFrame *profileTab_3;
    QPushButton *accountButton_3;
    QPushButton *passwordButton_3;
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
    QFrame *profileTab_4;
    QPushButton *accountButton_4;
    QFrame *profileTab_5;
    QPushButton *accountButton_6;
    QFrame *frame_4;
    QLabel *overallAlert;
    QLabel *label_4;
    QFrame *frame_8;
    QLabel *label_9;
    QLabel *trafficAnomalies;
    QFrame *frame_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;

    void setupUi(QMainWindow *WardenFort)
    {
        if (WardenFort->objectName().isEmpty())
            WardenFort->setObjectName("WardenFort");
        WardenFort->resize(1088, 562);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WardenFort->sizePolicy().hasHeightForWidth());
        WardenFort->setSizePolicy(sizePolicy);
        WardenFort->setMinimumSize(QSize(1088, 562));
        WardenFort->setMaximumSize(QSize(1088, 562));
        WardenFort->setCursor(QCursor(Qt::ArrowCursor));
        WardenFort->setStyleSheet(QString::fromUtf8("background-color: #191F32;"));
        WardenFort->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(WardenFort);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 221, 521));
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
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(410, 20, 141, 106));
        frame_3->setMinimumSize(QSize(141, 106));
        frame_3->setMaximumSize(QSize(180, 106));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        criticalDetections = new QLabel(frame_3);
        criticalDetections->setObjectName("criticalDetections");
        criticalDetections->setGeometry(QRect(0, 40, 141, 41));
        criticalDetections->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"	font: 700 20pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 151, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(260, 140, 441, 401));
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
" {background-color: #191F32;\n"
"color: white;\n"
"}\n"
"QTableCornerButton::section {background-color: #191F32;}\n"
"QTableWidget{\n"
"background-color: #2C3C4B;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        profileTab = new QFrame(centralwidget);
        profileTab->setObjectName("profileTab");
        profileTab->setGeometry(QRect(20, 234, 221, 50));
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
        alertsTab = new QFrame(centralwidget);
        alertsTab->setObjectName("alertsTab");
        alertsTab->setGeometry(QRect(20, 284, 221, 50));
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
        profileTab_2 = new QFrame(centralwidget);
        profileTab_2->setObjectName("profileTab_2");
        profileTab_2->setGeometry(QRect(21, 282, 219, 91));
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
        profileTab_3->setGeometry(QRect(21, 331, 219, 61));
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
        reportsTab = new QFrame(centralwidget);
        reportsTab->setObjectName("reportsTab");
        reportsTab->setGeometry(QRect(20, 334, 221, 50));
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
        calendarTab->setGeometry(QRect(20, 384, 221, 50));
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
        profileTab_4 = new QFrame(centralwidget);
        profileTab_4->setObjectName("profileTab_4");
        profileTab_4->setGeometry(QRect(32, 385, 219, 31));
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
        profileTab_5 = new QFrame(centralwidget);
        profileTab_5->setObjectName("profileTab_5");
        profileTab_5->setGeometry(QRect(20, 433, 219, 31));
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
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(560, 20, 141, 106));
        frame_4->setMinimumSize(QSize(141, 106));
        frame_4->setMaximumSize(QSize(180, 106));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        overallAlert = new QLabel(frame_4);
        overallAlert->setObjectName("overallAlert");
        overallAlert->setGeometry(QRect(0, 40, 141, 41));
        overallAlert->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"	font: 700 20pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 151, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        frame_8 = new QFrame(centralwidget);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(260, 20, 141, 106));
        frame_8->setMinimumSize(QSize(141, 106));
        frame_8->setMaximumSize(QSize(180, 106));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_8);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 10, 151, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        trafficAnomalies = new QLabel(frame_8);
        trafficAnomalies->setObjectName("trafficAnomalies");
        trafficAnomalies->setGeometry(QRect(0, 40, 141, 41));
        trafficAnomalies->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"	font: 700 20pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        frame_6 = new QFrame(centralwidget);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(710, 20, 371, 161));
        frame_6->setMinimumSize(QSize(0, 0));
        frame_6->setMaximumSize(QSize(99999, 99999));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 60, 75);\n"
"border-radius: 10px;"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_6);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 151, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 40, 61, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(frame_6);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 40, 191, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_10 = new QLabel(frame_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 70, 61, 16));
        label_10->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(frame_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 100, 61, 16));
        label_11->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_12 = new QLabel(frame_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 130, 81, 16));
        label_12->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_13 = new QLabel(frame_6);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(100, 70, 191, 16));
        label_13->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(100, 100, 191, 16));
        label_14->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_15 = new QLabel(frame_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(100, 130, 191, 16));
        label_15->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        WardenFort->setCentralWidget(centralwidget);
        frame_8->raise();
        frame_3->raise();
        frame->raise();
        tableWidget->raise();
        profileTab->raise();
        alertsTab->raise();
        reportsTab->raise();
        calendarTab->raise();
        profileTab_2->raise();
        profileTab_3->raise();
        profileTab_4->raise();
        profileTab_5->raise();
        frame_4->raise();
        frame_6->raise();

        retranslateUi(WardenFort);

        QMetaObject::connectSlotsByName(WardenFort);
    } // setupUi

    void retranslateUi(QMainWindow *WardenFort)
    {
        WardenFort->setWindowTitle(QCoreApplication::translate("WardenFort", "WardenFort", nullptr));
        frame_5->setText(QString());
        welcome_text->setText(QString());
        wardenfort->setText(QString());
        criticalDetections->setText(QCoreApplication::translate("WardenFort", "0", nullptr));
        label_2->setText(QCoreApplication::translate("WardenFort", "Critical Detections", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WardenFort", "Timestamp", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WardenFort", "Source IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WardenFort", "Destination IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WardenFort", "Source Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WardenFort", "Destination Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WardenFort", "Flags", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WardenFort", "Captured length", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WardenFort", "Info", nullptr));
        user_icon->setText(QString());
        profile_text->setText(QCoreApplication::translate("WardenFort", "PROFILE", nullptr));
        dd5->setText(QString());
#if QT_CONFIG(shortcut)
        dd5->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd1->setText(QString());
#if QT_CONFIG(shortcut)
        dd1->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        alert_icon->setText(QString());
        alert_text->setText(QCoreApplication::translate("WardenFort", "ALERTS", nullptr));
        dd6->setText(QString());
#if QT_CONFIG(shortcut)
        dd6->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd2->setText(QString());
#if QT_CONFIG(shortcut)
        dd2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        accountButton->setText(QCoreApplication::translate("WardenFort", "Account Settings", nullptr));
        passwordButton->setText(QCoreApplication::translate("WardenFort", "Password and Security", nullptr));
        logoutButton->setText(QCoreApplication::translate("WardenFort", "Log Out", nullptr));
        accountButton_3->setText(QCoreApplication::translate("WardenFort", "Notifications", nullptr));
        passwordButton_3->setText(QCoreApplication::translate("WardenFort", "Calendar Notifications", nullptr));
        report_icon->setText(QString());
        report_text->setText(QCoreApplication::translate("WardenFort", "REPORTS", nullptr));
        dd3->setText(QString());
#if QT_CONFIG(shortcut)
        dd3->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd7->setText(QString());
#if QT_CONFIG(shortcut)
        dd7->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        cal_text->setText(QCoreApplication::translate("WardenFort", "EVENT CALENDAR", nullptr));
        cal_icon->setText(QString());
        dd8->setText(QString());
#if QT_CONFIG(shortcut)
        dd8->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        dd4->setText(QString());
#if QT_CONFIG(shortcut)
        dd4->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        accountButton_4->setText(QCoreApplication::translate("WardenFort", "Generate Report", nullptr));
        accountButton_6->setText(QCoreApplication::translate("WardenFort", "Calendar", nullptr));
        overallAlert->setText(QCoreApplication::translate("WardenFort", "0", nullptr));
        label_4->setText(QCoreApplication::translate("WardenFort", "Overall alerts", nullptr));
        label_9->setText(QCoreApplication::translate("WardenFort", "Traffic Anomalies", nullptr));
        trafficAnomalies->setText(QCoreApplication::translate("WardenFort", "0", nullptr));
        label_6->setText(QCoreApplication::translate("WardenFort", "Packet Details", nullptr));
        label_7->setText(QCoreApplication::translate("WardenFort", "Source IP:", nullptr));
        label_8->setText(QCoreApplication::translate("WardenFort", "null", nullptr));
        label_10->setText(QCoreApplication::translate("WardenFort", "Domain:", nullptr));
        label_11->setText(QCoreApplication::translate("WardenFort", "ISP: ", nullptr));
        label_12->setText(QCoreApplication::translate("WardenFort", "Total Reports:", nullptr));
        label_13->setText(QCoreApplication::translate("WardenFort", "null", nullptr));
        label_14->setText(QCoreApplication::translate("WardenFort", "null", nullptr));
        label_15->setText(QCoreApplication::translate("WardenFort", "null", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WardenFort: public Ui_WardenFort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARDENFORT_H
