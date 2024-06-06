#include "passwordsec.h"
#include "ui_passwordsec.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

passwordSec::passwordSec(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::passwordSec)
{
    ui->setupUi(this);
    connect(ui->changePassButton, &QPushButton::clicked, this, &passwordSec::onChangePasswordButtonClicked);


}

passwordSec::~passwordSec()
{
    delete ui;
}

//void changePassword(const QString& username, const QString& newPassword) {
    // Assuming you have a database connection established
 //   QSqlDatabase db = QSqlDatabase::database();

    // Check if the database is open
//    if (!db.isOpen()) {
 //       qDebug() << "Database is not open";
 //       return;
  //  }

    // Prepare the SQL query to update the password
  //  QSqlQuery query;
  //  query.prepare("UPDATE user_db SET passwd = :passwd WHERE username = :username");
  //  query.bindValue(":passwd", newPassword);
  //  query.bindValue(":username", username);

    // Execute the query
 //   if (query.exec()) {
  //      qDebug() << "Password updated successfully for user:" << username;
  //  }
  //  else {
 //       qDebug() << "Error updating password:" << query.lastError().text();
 //   }
//}

void passwordSec::onChangePasswordButtonClicked() {
    disconnect(ui->changePassButton, &QPushButton::clicked, this, &passwordSec::onChangePasswordButtonClicked);
    QString newPass = ui->changePass->text(); // Get the new password from QLineEdit
    // Call the function to change the password
    //changePassword(username, newPass);
    connect(ui->changePassButton, &QPushButton::clicked, this, &passwordSec::onChangePasswordButtonClicked);
}

void passwordSec::getUsername(const QString& text)
{
    username = text;
    username.replace("Welcome,","");
    username.replace("!", "");
    username = username.simplified();
}

void passwordSec::toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow)
{
    buttonToHide->setVisible(false);
    buttonToShow->setVisible(true);
}
