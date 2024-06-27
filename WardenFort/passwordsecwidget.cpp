#include "passwordsecwidget.h"
#include "ui_passwordsecwidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <database.h>
#include <globals.h>

passwordSecWidget::passwordSecWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::passwordSecWidget)
{
    ui->setupUi(this);
    connect(ui->changePassButton, &QPushButton::clicked, this, &passwordSecWidget::onChangePasswordButtonClicked);

}

passwordSecWidget::~passwordSecWidget()
{
    delete ui;
}


void changePassword(const QString& username, const QString& newPassword) {
    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    query.prepare("UPDATE user_db SET passwd = :passwd WHERE username = :username");
    query.bindValue(":passwd", newPassword);
    query.bindValue(":username", loggedInUser.username);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Password updated successfully for user:" << loggedInUser.username;
    }
    else {
        qDebug() << "Error updating password:" << query.lastError().text();
    }
}

void passwordSecWidget::onChangePasswordButtonClicked() {
    disconnect(ui->changePassButton, &QPushButton::clicked, this, &passwordSecWidget::onChangePasswordButtonClicked);
    QString newPass = ui->changePass->text(); // Get the new password from QLineEdit
    // Call the function to change the password
    changePassword(username, newPass);
    connect(ui->changePassButton, &QPushButton::clicked, this, &passwordSecWidget::onChangePasswordButtonClicked);
}

void passwordSecWidget::getUsername(const QString& text)
{
    username = text;
    username.replace("Welcome,","");
    username.replace("!", "");
    username = username.simplified();
}

void passwordSecWidget::toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow)
{
    buttonToHide->setVisible(false);
    buttonToShow->setVisible(true);
}
