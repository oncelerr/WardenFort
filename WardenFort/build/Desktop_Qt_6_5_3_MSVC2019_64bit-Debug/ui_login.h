/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *cyber_bg;
    QWidget *widget;
    QLabel *username_text;
    QLineEdit *typeUN_box;
    QLineEdit *typePASS_box;
    QLabel *pass_text;
    QPushButton *loginButton;
    QLabel *wf_logo;
    QLabel *wf_word_2;
    QLabel *user_icon;
    QLabel *pass_icon;
    QLabel *wf_word;
    QCheckBox *eye_open;
    QCheckBox *eye_closed;
    QPushButton *signup_button;
    QPushButton *forgot_pass;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1088, 567);
        login->setMinimumSize(QSize(1088, 567));
        login->setMaximumSize(QSize(1088, 567));
        login->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 31, 50);\n"
""));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        cyber_bg = new QLabel(centralwidget);
        cyber_bg->setObjectName("cyber_bg");
        cyber_bg->setGeometry(QRect(490, 130, 411, 331));
        cyber_bg->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/cyber (1).png")));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(360, 20, 333, 527));
        widget->setMinimumSize(QSize(333, 527));
        widget->setMaximumSize(QSize(333, 527));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;\n"
""));
        username_text = new QLabel(widget);
        username_text->setObjectName("username_text");
        username_text->setGeometry(QRect(40, 180, 81, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff;\n"
"background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"\n"
""));
        typeUN_box = new QLineEdit(widget);
        typeUN_box->setObjectName("typeUN_box");
        typeUN_box->setGeometry(QRect(30, 200, 275, 52));
        typeUN_box->setMinimumSize(QSize(275, 52));
        typeUN_box->setMaximumSize(QSize(275, 52));
        typeUN_box->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        typePASS_box = new QLineEdit(widget);
        typePASS_box->setObjectName("typePASS_box");
        typePASS_box->setGeometry(QRect(30, 290, 275, 52));
        typePASS_box->setMinimumSize(QSize(275, 52));
        typePASS_box->setMaximumSize(QSize(275, 52));
        typePASS_box->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"padding: 50px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));
        pass_text = new QLabel(widget);
        pass_text->setObjectName("pass_text");
        pass_text->setGeometry(QRect(40, 270, 81, 16));
        pass_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff;\n"
"background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"\n"
""));
        loginButton = new QPushButton(widget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 400, 275, 34));
        loginButton->setMinimumSize(QSize(275, 34));
        loginButton->setMaximumSize(QSize(275, 34));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px; \n"
"background-color: rgb(22, 27, 46);\n"
"color: white;\n"
"}\n"
"QPushButton:hover {\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(24, 40, 55); /* Adjust pressed color if needed */\n"
"}"));
        typeUN_box->raise();
        username_text->raise();
        typePASS_box->raise();
        pass_text->raise();
        loginButton->raise();
        wf_logo = new QLabel(centralwidget);
        wf_logo->setObjectName("wf_logo");
        wf_logo->setGeometry(QRect(480, 40, 101, 121));
        wf_logo->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);"));
        wf_logo->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/7-removebg-preview 1.png")));
        wf_word_2 = new QLabel(centralwidget);
        wf_word_2->setObjectName("wf_word_2");
        wf_word_2->setGeometry(QRect(400, 140, 251, 31));
        wf_word_2->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);"));
        wf_word_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/logo (4).png")));
        user_icon = new QLabel(centralwidget);
        user_icon->setObjectName("user_icon");
        user_icon->setGeometry(QRect(406, 231, 30, 31));
        user_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        user_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/pass_icon (11).png")));
        pass_icon = new QLabel(centralwidget);
        pass_icon->setObjectName("pass_icon");
        pass_icon->setGeometry(QRect(408, 310, 31, 51));
        pass_icon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        pass_icon->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/pass_icon (4).png")));
        wf_word = new QLabel(centralwidget);
        wf_word->setObjectName("wf_word");
        wf_word->setGeometry(QRect(420, 150, 201, 21));
        wf_word->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wf_word->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/wardenfort_word (1).png")));
        eye_open = new QCheckBox(centralwidget);
        eye_open->setObjectName("eye_open");
        eye_open->setEnabled(true);
        eye_open->setGeometry(QRect(610, 327, 51, 21));
        eye_open->setCursor(QCursor(Qt::PointingHandCursor));
        eye_open->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/wardenfort/eye_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        eye_open->setIcon(icon);
        eye_open->setCheckable(false);
        eye_open->setChecked(false);
        eye_open->setTristate(false);
        eye_closed = new QCheckBox(centralwidget);
        eye_closed->setObjectName("eye_closed");
        eye_closed->setGeometry(QRect(610, 326, 40, 22));
        eye_closed->setCursor(QCursor(Qt::PointingHandCursor));
        eye_closed->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/wardenfort/eye_closed.png"), QSize(), QIcon::Normal, QIcon::Off);
        eye_closed->setIcon(icon1);
        eye_closed->setCheckable(false);
        eye_closed->setChecked(false);
        signup_button = new QPushButton(centralwidget);
        signup_button->setObjectName("signup_button");
        signup_button->setGeometry(QRect(487, 458, 80, 24));
        signup_button->setCursor(QCursor(Qt::PointingHandCursor));
        signup_button->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border: none;\n"
"text-decoration: underline;\n"
"font: 7.5pt \"Segoe UI\";\n"
"\n"
""));
        forgot_pass = new QPushButton(centralwidget);
        forgot_pass->setObjectName("forgot_pass");
        forgot_pass->setGeometry(QRect(576, 357, 80, 24));
        forgot_pass->setCursor(QCursor(Qt::PointingHandCursor));
        forgot_pass->setStyleSheet(QString::fromUtf8("font: 7.5pt \"Segoe UI\";\n"
"color: #ffffff;\n"
"border: 0;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"\n"
""));
        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Login", nullptr));
        cyber_bg->setText(QString());
        username_text->setText(QCoreApplication::translate("login", "Username", nullptr));
        typeUN_box->setPlaceholderText(QCoreApplication::translate("login", "Type your username", nullptr));
        typePASS_box->setPlaceholderText(QCoreApplication::translate("login", "Type your password", nullptr));
        pass_text->setText(QCoreApplication::translate("login", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("login", "Login", nullptr));
        wf_logo->setText(QString());
        wf_word_2->setText(QString());
        user_icon->setText(QString());
        pass_icon->setText(QString());
        wf_word->setText(QString());
        eye_open->setText(QString());
#if QT_CONFIG(shortcut)
        eye_open->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        eye_closed->setText(QString());
        signup_button->setText(QCoreApplication::translate("login", "Sign up", nullptr));
        forgot_pass->setText(QCoreApplication::translate("login", "Forgot Password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
