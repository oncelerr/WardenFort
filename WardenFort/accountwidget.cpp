#include "accountwidget.h"
#include "ui_accountwidget.h"
#include "wardenfort.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "globals.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

accountWidget::accountWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accountWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &accountWidget::changeEmail);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &accountWidget::changeUsername);

    // Set the placeholders with the logged-in user data
    ui->lineEdit->setPlaceholderText(loggedInUser.firstName);
    ui->lineEdit_2->setPlaceholderText(loggedInUser.lastName);
    setGenderComboBox(loggedInUser.gender); // Assuming gender is already part of the comboBox items
    ui->dateEdit->setDate(QDate::fromString(loggedInUser.dateOfBirth, "MM-dd-yyyy")); // Assuming dateOfBirth is in "yyyy-MM-dd" format
    ui->lineEdit_3->setPlaceholderText(loggedInUser.email);
    ui->lineEdit_4->setPlaceholderText(loggedInUser.username);

    // Optional: Set the current text directly if you want to show the values as entered text
    ui->lineEdit->setText(loggedInUser.firstName);
    ui->lineEdit_2->setText(loggedInUser.lastName);
    ui->lineEdit_3->setText(loggedInUser.email);
    ui->lineEdit_4->setText(loggedInUser.username);
}

accountWidget::~accountWidget()
{
    delete ui;
}

void accountWidget::changeEmail() {
    if (loggedInUser.userId != -1){
        bool ok;

        // Apply stylesheet to QInputDialog
        QInputDialog dialog;
        dialog.setStyleSheet("QInputDialog { color: white; background-color: #191F32; }"
                             "QInputDialog QLineEdit { color: white; background-color: #191F32; }"
                             "QInputDialog QPushButton { background-color: #01FDF5; color: black; border-radius: 15px; }");
        dialog.setFixedSize(300, 150); // Set a fixed size for the dialog
        QString newEmail = QInputDialog::getText(this, tr("Change Email"),
                                                 tr("New Email:"), QLineEdit::Normal,
                                                 "", &ok);

        if (ok && !newEmail.isEmpty() && loggedInUser.userId != -1) {
            // Validate the new email (basic validation)
            QRegularExpression emailRegex("[\\w\\.]+@[\\w\\.]+\\.[\\w\\.]+");
            QRegularExpressionMatch match = emailRegex.match(newEmail);
            if (!match.hasMatch()) {
                QMessageBox::warning(this, tr("Invalid Email"),
                                     tr("The email address you entered is not valid. Please enter a valid email address."));
                return;
            }

            // Update the email in the database
            QSqlQuery query;
            query.prepare("UPDATE user_db SET email = :email WHERE user_id = :user_id");
            query.bindValue(":email", newEmail);
            query.bindValue(":user_id", loggedInUser.userId);

            if (query.exec()) {
                QMessageBox emailChangedMsg;
                emailChangedMsg.setStyleSheet("QMessageBox { color: white; }"); // Set font color to white
                emailChangedMsg.information(this, tr("Email Changed"),
                                            tr("Your email address has been successfully changed."));
            } else {
                QMessageBox emailFailedMsg;
                emailFailedMsg.setStyleSheet("QMessageBox { color: white; }"); // Set font color to white
                emailFailedMsg.critical(this, tr("Error"),
                                        tr("Failed to change email: %1").arg(query.lastError().text()));
            }
        }
    } else {
        QMessageBox loginFirstMsg;
        loginFirstMsg.setStyleSheet("QMessageBox { color: white; }"); // Set font color to white
        loginFirstMsg.critical(this, tr("Error"),
                               tr("You must logged in first"));
    }
}

void accountWidget::changeUsername() {
    if (loggedInUser.userId != -1){
        bool ok;
        QString newUsername = QInputDialog::getText(this, tr("Change Username"),
                                                    tr("New Username:"), QLineEdit::Normal,
                                                    "", &ok);
        if (ok && !newUsername.isEmpty() && loggedInUser.userId != -1) {
            // Validate the new username (basic validation)
            if (newUsername.contains(QRegularExpression("[^a-zA-Z0-9_]"))) {
                QMessageBox::warning(this, tr("Invalid Username"),
                                     tr("The username can only contain letters, numbers, and underscores."));
                return;
            }

            // Update the username in the database
            QSqlQuery query;
            query.prepare("UPDATE user_db SET username = :username WHERE user_id = :user_id");
            query.bindValue(":username", newUsername);
            query.bindValue(":user_id", loggedInUser.userId);

            if (query.exec()) {
                QMessageBox::information(this, tr("Username Changed"),
                                         tr("Your username has been successfully changed."));
            } else {
                QMessageBox::critical(this, tr("Error"),
                                      tr("Failed to change username: %1").arg(query.lastError().text()));
            }
        }
    } else {
        QMessageBox::critical(this, tr("Error"),
                              tr("You must log in first"));
    }
}

void accountWidget::setGenderComboBox(const QString &gender)
{
    int index = ui->comboBox->findText(gender);
    if (index != -1) { // If the gender is found in the combo box items
        ui->comboBox->setCurrentIndex(index);
    }
}
