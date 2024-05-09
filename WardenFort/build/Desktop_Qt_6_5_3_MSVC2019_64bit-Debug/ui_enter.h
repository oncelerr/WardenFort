/********************************************************************************
** Form generated from reading UI file 'enter.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTER_H
#define UI_ENTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enter
{
public:
    QLabel *wardenfort;
    QWidget *widget;
    QPushButton *submitButton;
    QLineEdit *user_find;
    QLabel *enter_text;
    QLabel *cyber_bg;
    QLabel *verify_text;
    QPushButton *back_button;

    void setupUi(QDialog *enter)
    {
        if (enter->objectName().isEmpty())
            enter->setObjectName("enter");
        enter->resize(1088, 567);
        enter->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 31, 50);\n"
""));
        wardenfort = new QLabel(enter);
        wardenfort->setObjectName("wardenfort");
        wardenfort->setGeometry(QRect(446, 120, 191, 51));
        wardenfort->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/wardenfort_word (1).png")));
        widget = new QWidget(enter);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(281, 107, 529, 361));
        widget->setAcceptDrops(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;"));
        submitButton = new QPushButton(widget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(130, 280, 275, 34));
        submitButton->setMinimumSize(QSize(275, 34));
        submitButton->setMaximumSize(QSize(275, 34));
        submitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px; \n"
"background-color: rgb(22, 27, 46);\n"
"color: rgb(1,253,245);\n"
"}\n"
"QPushButton:hover {\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(24, 40, 55); /* Adjust pressed color if needed */\n"
"}"));
        user_find = new QLineEdit(widget);
        user_find->setObjectName("user_find");
        user_find->setGeometry(QRect(80, 180, 371, 51));
        user_find->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"	font: 700 12pt \"Segoe UI\";\n"
"    padding-left: 20px; \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        enter_text = new QLabel(widget);
        enter_text->setObjectName("enter_text");
        enter_text->setGeometry(QRect(211, 119, 121, 41));
        enter_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 15pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);\n"
"font: 700 9pt \"Segoe UI\";"));
        cyber_bg = new QLabel(enter);
        cyber_bg->setObjectName("cyber_bg");
        cyber_bg->setGeometry(QRect(640, 130, 401, 331));
        cyber_bg->setCursor(QCursor(Qt::ArrowCursor));
        cyber_bg->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/cyber (1).png")));
        verify_text = new QLabel(enter);
        verify_text->setObjectName("verify_text");
        verify_text->setGeometry(QRect(428, 170, 241, 50));
        verify_text->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        back_button = new QPushButton(enter);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(5, 10, 41, 24));
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
        widget->raise();
        wardenfort->raise();
        cyber_bg->raise();
        verify_text->raise();
        back_button->raise();

        retranslateUi(enter);

        QMetaObject::connectSlotsByName(enter);
    } // setupUi

    void retranslateUi(QDialog *enter)
    {
        enter->setWindowTitle(QCoreApplication::translate("enter", "Dialog", nullptr));
        wardenfort->setText(QString());
        submitButton->setText(QCoreApplication::translate("enter", "Submit", nullptr));
        user_find->setText(QString());
        enter_text->setText(QCoreApplication::translate("enter", "Enter your username", nullptr));
        cyber_bg->setText(QString());
        verify_text->setText(QCoreApplication::translate("enter", "RESET PASSWORD", nullptr));
        back_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class enter: public Ui_enter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTER_H
