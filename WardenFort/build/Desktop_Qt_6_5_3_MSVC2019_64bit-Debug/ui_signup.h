/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QCheckBox *eye_closed;
    QLabel *cyber_bg;
    QLabel *wf_logo;
    QCheckBox *eye_open;
    QLabel *wf_word;
    QWidget *widget_2;
    QLineEdit *first_name;
    QLineEdit *last_name;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *email_address;
    QPushButton *create_button;
    QCheckBox *back_button;
    QLabel *fn_text;
    QLabel *ln_text;
    QLabel *un_text;
    QLabel *emtext;
    QLabel *pd_text;
    QLabel *pass_rest;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(1088, 567);
        signup->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 31, 50);\n"
""));
        eye_closed = new QCheckBox(signup);
        eye_closed->setObjectName("eye_closed");
        eye_closed->setGeometry(QRect(612, 326, 40, 22));
        eye_closed->setCursor(QCursor(Qt::PointingHandCursor));
        eye_closed->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/admin/Downloads/eye_closed.png"), QSize(), QIcon::Normal, QIcon::Off);
        eye_closed->setIcon(icon);
        eye_closed->setCheckable(false);
        eye_closed->setChecked(false);
        cyber_bg = new QLabel(signup);
        cyber_bg->setObjectName("cyber_bg");
        cyber_bg->setGeometry(QRect(492, 130, 411, 331));
        cyber_bg->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/wardenfort 1.png")));
        wf_logo = new QLabel(signup);
        wf_logo->setObjectName("wf_logo");
        wf_logo->setGeometry(QRect(505, 8, 101, 121));
        wf_logo->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);"));
        wf_logo->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/7-removebg-preview 1.png")));
        eye_open = new QCheckBox(signup);
        eye_open->setObjectName("eye_open");
        eye_open->setEnabled(true);
        eye_open->setGeometry(QRect(612, 327, 51, 21));
        eye_open->setCursor(QCursor(Qt::PointingHandCursor));
        eye_open->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/admin/Downloads/eye_open.png"), QSize(), QIcon::Selected, QIcon::Off);
        eye_open->setIcon(icon1);
        eye_open->setCheckable(false);
        eye_open->setChecked(false);
        eye_open->setTristate(false);
        wf_word = new QLabel(signup);
        wf_word->setObjectName("wf_word");
        wf_word->setGeometry(QRect(452, 111, 201, 21));
        wf_word->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wf_word->setPixmap(QPixmap(QString::fromUtf8(":/wardenfort/wardenfort_word (1).png")));
        widget_2 = new QWidget(signup);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(345, 11, 407, 538));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;\n"
""));
        first_name = new QLineEdit(signup);
        first_name->setObjectName("first_name");
        first_name->setGeometry(QRect(383, 140, 334, 41));
        first_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 10px; \n"
"background-color: rgb(44, 60, 75);\n"
"	color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}\n"
"\n"
""));
        last_name = new QLineEdit(signup);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(383, 209, 334, 41));
        last_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 10px; \n"
"background-color: rgb(44, 60, 75);\n"
"	color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}\n"
"\n"
""));
        username = new QLineEdit(signup);
        username->setObjectName("username");
        username->setGeometry(QRect(383, 280, 334, 41));
        username->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 10px; \n"
"background-color: rgb(44, 60, 75);\n"
"	color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}\n"
"\n"
""));
        password = new QLineEdit(signup);
        password->setObjectName("password");
        password->setGeometry(QRect(383, 420, 334, 41));
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 10px; \n"
"background-color: rgb(44, 60, 75);\n"
"	color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}\n"
"\n"
""));
        email_address = new QLineEdit(signup);
        email_address->setObjectName("email_address");
        email_address->setGeometry(QRect(383, 350, 334, 41));
        email_address->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 10px; \n"
"background-color: rgb(44, 60, 75);\n"
"	color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}\n"
"\n"
""));
        email_address->setInputMask(QString::fromUtf8(""));
        email_address->setText(QString::fromUtf8(""));
        email_address->setMaxLength(32767);
        create_button = new QPushButton(signup);
        create_button->setObjectName("create_button");
        create_button->setGeometry(QRect(410, 490, 275, 34));
        create_button->setMinimumSize(QSize(275, 34));
        create_button->setMaximumSize(QSize(275, 34));
        create_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px; \n"
"background-color: rgb(22, 27, 46);\n"
"color: white;\n"
"}\n"
"QPushButton:hover {\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(24, 40, 55); /* Adjust pressed color if needed */\n"
"}"));
        back_button = new QCheckBox(signup);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(0, 10, 41, 22));
        back_button->setCursor(QCursor(Qt::PointingHandCursor));
        back_button->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/wardenfort/dd1_rotated.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_button->setIcon(icon2);
        fn_text = new QLabel(signup);
        fn_text->setObjectName("fn_text");
        fn_text->setGeometry(QRect(396, 132, 61, 16));
        fn_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        ln_text = new QLabel(signup);
        ln_text->setObjectName("ln_text");
        ln_text->setGeometry(QRect(396, 201, 61, 16));
        ln_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        un_text = new QLabel(signup);
        un_text->setObjectName("un_text");
        un_text->setGeometry(QRect(396, 271, 61, 16));
        un_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        emtext = new QLabel(signup);
        emtext->setObjectName("emtext");
        emtext->setGeometry(QRect(396, 341, 91, 16));
        emtext->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pd_text = new QLabel(signup);
        pd_text->setObjectName("pd_text");
        pd_text->setGeometry(QRect(396, 411, 91, 16));
        pd_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pass_rest = new QLabel(signup);
        pass_rest->setObjectName("pass_rest");
        pass_rest->setEnabled(false);
        pass_rest->setGeometry(QRect(0, 558, 49, 16));
        pass_rest->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->raise();
        widget_2->raise();
        eye_closed->raise();
        wf_logo->raise();
        eye_open->raise();
        wf_word->raise();
        first_name->raise();
        last_name->raise();
        username->raise();
        password->raise();
        email_address->raise();
        create_button->raise();
        back_button->raise();
        fn_text->raise();
        ln_text->raise();
        un_text->raise();
        pd_text->raise();
        pass_rest->raise();
        emtext->raise();

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Sign Up", nullptr));
        eye_closed->setText(QString());
        cyber_bg->setText(QString());
        wf_logo->setText(QString());
        eye_open->setText(QString());
#if QT_CONFIG(shortcut)
        eye_open->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        wf_word->setText(QString());
        first_name->setInputMask(QString());
        first_name->setText(QString());
        first_name->setPlaceholderText(QString());
        last_name->setInputMask(QString());
        last_name->setText(QString());
        last_name->setPlaceholderText(QString());
        username->setInputMask(QString());
        username->setText(QString());
        username->setPlaceholderText(QString());
        password->setInputMask(QString());
        password->setText(QString());
        password->setPlaceholderText(QString());
        email_address->setPlaceholderText(QString());
        create_button->setText(QCoreApplication::translate("signup", "Create", nullptr));
        back_button->setText(QString());
        fn_text->setText(QCoreApplication::translate("signup", "First Name", nullptr));
        ln_text->setText(QCoreApplication::translate("signup", "Last Name", nullptr));
        un_text->setText(QCoreApplication::translate("signup", "Username", nullptr));
        emtext->setText(QCoreApplication::translate("signup", "Email Address", nullptr));
        pd_text->setText(QCoreApplication::translate("signup", "Password", nullptr));
        pass_rest->setText(QCoreApplication::translate("signup", "null", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
