#include "passwordsecwidget.h"
#include "ui_passwordsecwidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

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
    // Assuming you have a database connection established
    QSqlDatabase db = QSqlDatabase::database();

    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return;
    }

    // Prepare the SQL query to update the password
    QSqlQuery query;
    query.prepare("UPDATE user_db SET passwd = :passwd WHERE username = :username");
    query.bindValue(":passwd", newPassword);
    query.bindValue(":username", username);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Password updated successfully for user:" << username;
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
