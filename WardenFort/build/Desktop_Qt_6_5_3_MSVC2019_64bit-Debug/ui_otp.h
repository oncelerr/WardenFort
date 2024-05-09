/********************************************************************************
** Form generated from reading UI file 'otp.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTP_H
#define UI_OTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_otp
{
public:
    QLabel *enter_text;
    QLabel *wardenfort;
    QWidget *widget;
    QLabel *email_show;
    QPushButton *resendButton;
    QLabel *timer;
    QLabel *code_text;
    QPushButton *submitButton;
    QLabel *cyber_bg;
    QLabel *verify_text;
    QTextEdit *text1;
    QTextEdit *text2;
    QTextEdit *text3;
    QTextEdit *text5;
    QTextEdit *text6;
    QTextEdit *text4;

    void setupUi(QDialog *otp)
    {
        if (otp->objectName().isEmpty())
            otp->setObjectName("otp");
        otp->resize(1088, 567);
        otp->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 31, 50);\n"
""));
        enter_text = new QLabel(otp);
        enter_text->setObjectName("enter_text");
        enter_text->setGeometry(QRect(200, 190, 291, 41));
        enter_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        wardenfort = new QLabel(otp);
        wardenfort->setObjectName("wardenfort");
        wardenfort->setGeometry(QRect(224, 80, 191, 51));
        wardenfort->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        wardenfort->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/wardenfort_word (1).png")));
        widget = new QWidget(otp);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(66, 67, 529, 461));
        widget->setAcceptDrops(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 60, 75, 0.6); \n"
"border-radius: 50px;"));
        email_show = new QLabel(widget);
        email_show->setObjectName("email_show");
        email_show->setGeometry(QRect(210, 152, 161, 61));
        email_show->setStyleSheet(QString::fromUtf8("color: rgb(1, 253, 245);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        resendButton = new QPushButton(widget);
        resendButton->setObjectName("resendButton");
        resendButton->setGeometry(QRect(290, 327, 80, 24));
        resendButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";"));
        timer = new QLabel(otp);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(310, 239, 51, 91));
        timer->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(1, 253, 245);\n"
""));
        code_text = new QLabel(otp);
        code_text->setObjectName("code_text");
        code_text->setGeometry(QRect(248, 360, 131, 91));
        code_text->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        submitButton = new QPushButton(otp);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(196, 470, 275, 34));
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
        cyber_bg = new QLabel(otp);
        cyber_bg->setObjectName("cyber_bg");
        cyber_bg->setGeometry(QRect(600, 150, 421, 331));
        cyber_bg->setCursor(QCursor(Qt::ArrowCursor));
        cyber_bg->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        cyber_bg->setPixmap(QPixmap(QString::fromUtf8("C:/Users/admin/Downloads/cyber (1).png")));
        verify_text = new QLabel(otp);
        verify_text->setObjectName("verify_text");
        verify_text->setGeometry(QRect(280, 130, 90, 50));
        verify_text->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        text1 = new QTextEdit(otp);
        text1->setObjectName("text1");
        text1->setGeometry(QRect(100, 310, 61, 51));
        text1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text1->setFocusPolicy(Qt::StrongFocus);
        text1->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        text1->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhSensitiveData);
        text2 = new QTextEdit(otp);
        text2->setObjectName("text2");
        text2->setGeometry(QRect(180, 310, 61, 51));
        text2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text2->setFocusPolicy(Qt::StrongFocus);
        text2->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        text2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhSensitiveData);
        text3 = new QTextEdit(otp);
        text3->setObjectName("text3");
        text3->setGeometry(QRect(260, 310, 61, 51));
        text3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text3->setFocusPolicy(Qt::StrongFocus);
        text3->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        text5 = new QTextEdit(otp);
        text5->setObjectName("text5");
        text5->setGeometry(QRect(420, 310, 61, 51));
        text5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text5->setFocusPolicy(Qt::StrongFocus);
        text5->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        text6 = new QTextEdit(otp);
        text6->setObjectName("text6");
        text6->setGeometry(QRect(500, 310, 61, 51));
        text6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text6->setFocusPolicy(Qt::StrongFocus);
        text6->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        text4 = new QTextEdit(otp);
        text4->setObjectName("text4");
        text4->setGeometry(QRect(340, 310, 61, 51));
        text4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        text4->setFocusPolicy(Qt::StrongFocus);
        text4->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border-radius: 15px; \n"
"background-color: rgb(44, 60, 75);\n"
"color: rgb(1, 253, 245);\n"
"	font: 700 18pt \"Segoe UI\";\n"
"    padding-left: 20px; padding-top: 6px;\n"
"}\n"
""));
        widget->raise();
        submitButton->raise();
        enter_text->raise();
        verify_text->raise();
        wardenfort->raise();
        cyber_bg->raise();
        code_text->raise();
        timer->raise();
        text1->raise();
        text2->raise();
        text3->raise();
        text5->raise();
        text6->raise();
        text4->raise();

        retranslateUi(otp);

        QMetaObject::connectSlotsByName(otp);
    } // setupUi

    void retranslateUi(QDialog *otp)
    {
        otp->setWindowTitle(QCoreApplication::translate("otp", "OTP Verification", nullptr));
        enter_text->setText(QCoreApplication::translate("otp", "Enter the code from the email we sent to", nullptr));
        wardenfort->setText(QString());
        email_show->setText(QCoreApplication::translate("otp", "null", nullptr));
        resendButton->setText(QCoreApplication::translate("otp", "Resend", nullptr));
        timer->setText(QCoreApplication::translate("otp", "null", nullptr));
        code_text->setText(QCoreApplication::translate("otp", "Didn\342\200\231t receive the code? ", nullptr));
        submitButton->setText(QCoreApplication::translate("otp", "Submit", nullptr));
        cyber_bg->setText(QString());
        verify_text->setText(QCoreApplication::translate("otp", "VERIFY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class otp: public Ui_otp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTP_H
