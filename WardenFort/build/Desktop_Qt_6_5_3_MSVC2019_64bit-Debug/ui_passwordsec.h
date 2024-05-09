/********************************************************************************
** Form generated from reading UI file 'passwordsec.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDSEC_H
#define UI_PASSWORDSEC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordSec
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_6;
    QFrame *frame;
    QWidget *widget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_14;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_9;
    QLineEdit *changePass;
    QPushButton *changePassButton;
    QLabel *label_10;
    QComboBox *comboBox;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *comboBox_2;
    QLabel *label_15;
    QComboBox *comboBox_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *passwordSec)
    {
        if (passwordSec->objectName().isEmpty())
            passwordSec->setObjectName("passwordSec");
        passwordSec->resize(1088, 567);
        passwordSec->setStyleSheet(QString::fromUtf8("background-color: #191F32;"));
        centralwidget = new QWidget(passwordSec);
        centralwidget->setObjectName("centralwidget");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 0, 111, 121));
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(310, 190, 631, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(11);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 10, 781, 511));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/bg.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(310, 150, 301, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 10, 215, 510));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(44, 60, 75, 0.5);\n"
"    border-radius: 10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 190, 215, 326));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgba(57, 83, 113, 0.5);\n"
"    border-radius: 25px;\n"
"}"));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(0, 40, 215, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setPointSize(9);
        font2.setBold(true);
        toolButton->setFont(font2);
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: transparent;\n"
"    color: #01FDF5;\n"
"	border-bottom: 2px solid #191F32;\n"
"	border-radius: 0px;\n"
"	padding: 5px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/profileIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(24, 24));
        toolButton->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setGeometry(QRect(0, 100, 215, 50));
        toolButton_2->setFont(font2);
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: transparent;\n"
"    color: #01FDF5;\n"
"	border-bottom: 2px solid #191F32;\n"
"	border-radius: 0px;\n"
"	padding: 5px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Downloads/alertIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(24, 24));
        toolButton_2->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(0, 160, 215, 50));
        toolButton_3->setFont(font2);
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: transparent;\n"
"    color: #01FDF5;\n"
"	border-bottom: 2px solid #191F32;\n"
"	border-radius: 0px;\n"
"	padding: 5px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../Downloads/folderIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(24, 24));
        toolButton_3->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(0, 220, 215, 50));
        toolButton_4->setFont(font2);
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: transparent;\n"
"    color: #01FDF5;\n"
"	border-bottom: 2px solid #191F32;\n"
"	border-radius: 0px;\n"
"	padding: 5px;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../../Downloads/calendarIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(24, 24));
        toolButton_4->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, 0, 231, 51));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/wardenfort.png")));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(55, 60, 111, 121));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/circle.png")));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(70, 70, 71, 81));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 0, 141, 131));
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/Ellipse.png")));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 90, 31, 24));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../../Downloads/profileButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(25, 24));
        pushButton->setFlat(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(320, 230, 71, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setBold(true);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        changePass = new QLineEdit(centralwidget);
        changePass->setObjectName("changePass");
        changePass->setGeometry(QRect(310, 250, 220, 31));
        changePass->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        changePassButton = new QPushButton(centralwidget);
        changePassButton->setObjectName("changePassButton");
        changePassButton->setGeometry(QRect(570, 250, 91, 31));
        changePassButton->setFont(font3);
        changePassButton->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(320, 290, 71, 16));
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(310, 310, 220, 31));
        comboBox->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(310, 400, 631, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(310, 360, 301, 31));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(320, 440, 71, 16));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(310, 460, 220, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(620, 440, 121, 16));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(610, 460, 220, 31));
        comboBox_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        passwordSec->setCentralWidget(centralwidget);
        label_3->raise();
        label_5->raise();
        label_7->raise();
        label_6->raise();
        frame->raise();
        label_8->raise();
        pushButton->raise();
        label_9->raise();
        changePass->raise();
        changePassButton->raise();
        label_10->raise();
        comboBox->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        comboBox_2->raise();
        label_15->raise();
        comboBox_3->raise();
        menubar = new QMenuBar(passwordSec);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1088, 22));
        passwordSec->setMenuBar(menubar);
        statusbar = new QStatusBar(passwordSec);
        statusbar->setObjectName("statusbar");
        passwordSec->setStatusBar(statusbar);

        retranslateUi(passwordSec);

        QMetaObject::connectSlotsByName(passwordSec);
    } // setupUi

    void retranslateUi(QMainWindow *passwordSec)
    {
        passwordSec->setWindowTitle(QCoreApplication::translate("passwordSec", "passwordSec", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("passwordSec", "Manage your passwords, login preferences and recovery methods.", nullptr));
        label_3->setText(QString());
        label_6->setText(QCoreApplication::translate("passwordSec", "PASSWORD AND SECURITY", nullptr));
        toolButton->setText(QCoreApplication::translate("passwordSec", "PROFILE", nullptr));
        toolButton_2->setText(QCoreApplication::translate("passwordSec", "ALERTS", nullptr));
        toolButton_3->setText(QCoreApplication::translate("passwordSec", "REPORTS", nullptr));
        toolButton_4->setText(QCoreApplication::translate("passwordSec", "CALENDAR", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_14->setText(QString());
        label_8->setText(QString());
        pushButton->setText(QString());
        label_9->setText(QCoreApplication::translate("passwordSec", "Password", nullptr));
        changePassButton->setText(QCoreApplication::translate("passwordSec", "Change", nullptr));
        label_10->setText(QCoreApplication::translate("passwordSec", "Gender", nullptr));
        label_11->setText(QCoreApplication::translate("passwordSec", "Review security issues by running checks across apps, devices and emails sent.", nullptr));
        label_12->setText(QCoreApplication::translate("passwordSec", "SECURITY CHECKS", nullptr));
        label_13->setText(QCoreApplication::translate("passwordSec", "Login Alerts", nullptr));
        label_15->setText(QCoreApplication::translate("passwordSec", "Security Checkup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordSec: public Ui_passwordSec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDSEC_H
