/********************************************************************************
** Form generated from reading UI file 'forgot.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOT_H
#define UI_FORGOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_forgot
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *forgot)
    {
        if (forgot->objectName().isEmpty())
            forgot->setObjectName("forgot");
        forgot->resize(400, 300);
        buttonBox = new QDialogButtonBox(forgot);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(forgot);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, forgot, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, forgot, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(forgot);
    } // setupUi

    void retranslateUi(QDialog *forgot)
    {
        forgot->setWindowTitle(QCoreApplication::translate("forgot", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgot: public Ui_forgot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOT_H
