/********************************************************************************
** Form generated from reading UI file 'forgotpass.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASS_H
#define UI_FORGOTPASS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forgotpass
{
public:
    QWidget *widget;
    QLabel *timer;
    QPushButton *reset_password_button;
    QLineEdit *pass_change;
    QLabel *wardenfort;
    QLabel *verify_text;
    QLabel *email_show;
    QLabel *enter_text;
    QLabel *cyber_bg;
    QPushButton *back_button;
    QWidget *widget_2;
    QPushButton *reset_password_button_2;
    QLineEdit *pass_change_2;
    QLabel *wardenfort_2;
    QLabel *verify_text_2;
    QLabel *enter_text_2;

    void setupUi(QDialog *forgotpass)
    {
        if (forgotpass->objectName().isEmpty())
            forgotpass->setObjectName("forgotpass");
        forgotpass->resize(1088, 567);
        forgotpass->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 31, 50);\n"
""));
        widget = new QWidget(forgotpass);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(278, 81, 529, 411));
        widget->setAcceptDrops(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;"));
        timer = new QLabel(widget);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(246, 150, 51, 91));
        timer->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);\n"
""));
        reset_password_button = new QPushButton(widget);
        reset_password_button->setObjectName("reset_password_button");
        reset_password_button->setGeometry(QRect(129, 330, 275, 34));
        reset_password_button->setMinimumSize(QSize(275, 34));
        reset_password_button->setMaximumSize(QSize(275, 34));
        reset_password_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px; \n"
"background-color: rgb(22, 27, 46);\n"
"color: rgb(1,253,245);\n"
"}\n"
"QPushButton:hover {\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(24, 40, 55); /* Adjust pressed color if needed */\n"
"}"));
        pass_change = new QLineEdit(widget);
        pass_change->setObjectName("pass_change");
        pass_change->setGeometry(QRect(80, 220, 371, 51));
        pass_change->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
""));
        wardenfort = new QLabel(widget);
        wardenfort->setObjectName("wardenfort");
        wardenfort->setGeometry(QRect(170, 10, 191, 51));
        wardenfort->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/wardenfort_word (1).png")));
        verify_text = new QLabel(widget);
        verify_text->setObjectName("verify_text");
        verify_text->setGeometry(QRect(140, 60, 241, 50));
        verify_text->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"qproperty-alignment: AlignCenter;"));
        email_show = new QLabel(widget);
        email_show->setObjectName("email_show");
        email_show->setGeometry(QRect(300, 130, 161, 31));
        email_show->setMaximumSize(QSize(1920, 16777215));
        email_show->setStyleSheet(QString::fromUtf8("color: rgb(1, 253, 245);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        enter_text = new QLabel(widget);
        enter_text->setObjectName("enter_text");
        enter_text->setGeometry(QRect(96, 125, 291, 41));
        enter_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        cyber_bg = new QLabel(forgotpass);
        cyber_bg->setObjectName("cyber_bg");
        cyber_bg->setGeometry(QRect(610, 120, 421, 331));
        cyber_bg->setCursor(QCursor(Qt::ArrowCursor));
        cyber_bg->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/cyber (1).png")));
        back_button = new QPushButton(forgotpass);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(10, 13, 41, 24));
        back_button->setCursor(QCursor(Qt::PointingHandCursor));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton::indicator {\n"
"    border: none; /* Remove border */\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; /* Remove background color */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/admin/Downloads/dd1_rotated.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_button->setIcon(icon);
        widget_2 = new QWidget(forgotpass);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(280, 80, 529, 411));
        widget_2->setAcceptDrops(false);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;"));
        reset_password_button_2 = new QPushButton(widget_2);
        reset_password_button_2->setObjectName("reset_password_button_2");
        reset_password_button_2->setGeometry(QRect(129, 330, 275, 34));
        reset_password_button_2->setMinimumSize(QSize(275, 34));
        reset_password_button_2->setMaximumSize(QSize(275, 34));
        reset_password_button_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px; \n"
"background-color: rgb(22, 27, 46);\n"
"color: rgb(1,253,245);\n"
"}\n"
"QPushButton:hover {\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(24, 40, 55); /* Adjust pressed color if needed */\n"
"}"));
        pass_change_2 = new QLineEdit(widget_2);
        pass_change_2->setObjectName("pass_change_2");
        pass_change_2->setGeometry(QRect(80, 220, 371, 51));
        pass_change_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
""));
        wardenfort_2 = new QLabel(widget_2);
        wardenfort_2->setObjectName("wardenfort_2");
        wardenfort_2->setGeometry(QRect(170, 10, 191, 51));
        wardenfort_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/wardenfort_word (1).png")));
        verify_text_2 = new QLabel(widget_2);
        verify_text_2->setObjectName("verify_text_2");
        verify_text_2->setGeometry(QRect(140, 60, 241, 50));
        verify_text_2->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"qproperty-alignment: AlignCenter;"));
        enter_text_2 = new QLabel(widget_2);
        enter_text_2->setObjectName("enter_text_2");
        enter_text_2->setGeometry(QRect(114, 125, 291, 41));
        enter_text_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"qproperty-alignment: AlignCenter;"));

        retranslateUi(forgotpass);

        QMetaObject::connectSlotsByName(forgotpass);
    } // setupUi

    void retranslateUi(QDialog *forgotpass)
    {
        forgotpass->setWindowTitle(QCoreApplication::translate("forgotpass", "Forgot Password", nullptr));
        timer->setText(QCoreApplication::translate("forgotpass", "null", nullptr));
        reset_password_button->setText(QCoreApplication::translate("forgotpass", "Submit", nullptr));
        pass_change->setPlaceholderText(QCoreApplication::translate("forgotpass", "Enter 6 digit code", nullptr));
        wardenfort->setText(QString());
        verify_text->setText(QCoreApplication::translate("forgotpass", "Verify User", nullptr));
        email_show->setText(QCoreApplication::translate("forgotpass", "null", nullptr));
        enter_text->setText(QCoreApplication::translate("forgotpass", "The 6 digit code has been sent to", nullptr));
        cyber_bg->setText(QString());
        back_button->setText(QString());
        reset_password_button_2->setText(QCoreApplication::translate("forgotpass", "Submit", nullptr));
        pass_change_2->setPlaceholderText(QCoreApplication::translate("forgotpass", "Enter your new Password", nullptr));
        wardenfort_2->setText(QString());
        verify_text_2->setText(QCoreApplication::translate("forgotpass", "Reset Password", nullptr));
        enter_text_2->setText(QCoreApplication::translate("forgotpass", "Enter your new password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgotpass: public Ui_forgotpass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASS_H
