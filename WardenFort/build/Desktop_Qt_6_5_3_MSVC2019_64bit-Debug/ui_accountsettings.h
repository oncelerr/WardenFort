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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountSettings
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QLabel *label_3;
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
        frame_2->setGeometry(QRect(260, 10, 781, 511));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 781, 511));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/bg.png")));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, -10, 131, 131));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/Ellipse.png")));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 80, 31, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/profileButton.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        lineEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 260, 220, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 310, 71, 16));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 330, 220, 31));
        comboBox->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(300, 330, 220, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
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
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        lineEdit_4 = new QLineEdit(frame_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(40, 460, 220, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border-radius: 15px;"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 440, 91, 16));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white;"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 400, 91, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #01FDF5;\n"
"color: black;\n"
"border-radius: 15px;"));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(310, 460, 91, 31));
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
        label_3->raise();
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
        statusbar = new QStatusBar(accountSettings);
        statusbar->setObjectName("statusbar");
        accountSettings->setStatusBar(statusbar);

        retranslateUi(accountSettings);

        QMetaObject::connectSlotsByName(accountSettings);
    } // setupUi

    void retranslateUi(QMainWindow *accountSettings)
    {
        accountSettings->setWindowTitle(QCoreApplication::translate("accountSettings", "accountSettings", nullptr));
        label_3->setText(QString());
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
