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

    // Connect the clicked signal of dd buttons to the toggle function
    connect(ui->dd1, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd2, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd3, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd4, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd5, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd6, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd7, &QPushButton::clicked, this, &passwordSec::toggleButtons);
    connect(ui->dd8, &QPushButton::clicked, this, &passwordSec::toggleButtons);

    // Initially hide dd5 to dd8 buttons
    ui->dd5->setVisible(false);
    ui->dd6->setVisible(false);
    ui->dd7->setVisible(false);
    ui->dd8->setVisible(false);
    ui->profileTab_2->setVisible(false);
    ui->profileTab_3->setVisible(false);
    ui->profileTab_4->setVisible(false);
    ui->profileTab_5->setVisible(false);
    ui->frame_2->setVisible(false);
}

passwordSec::~passwordSec()
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

void passwordSec::onChangePasswordButtonClicked() {
    disconnect(ui->changePassButton, &QPushButton::clicked, this, &passwordSec::onChangePasswordButtonClicked);
    QString newPass = ui->changePass->text(); // Get the new password from QLineEdit
    // Call the function to change the password
    changePassword(username, newPass);
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

void passwordSec::toggleButtons()
{
    int newY;
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton)
        return; // Safety check

    if (clickedButton == ui->dd1) {
        // Remove the border-top style
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");

        toggleButtonVisibility(ui->dd1, ui->dd5);
        //alerts tab
        newY = ui->alertsTab->y() + 90;
        ui->alertsTab->move(ui->alertsTab->x(), newY);
        //reports tab
        newY = ui->reportsTab->y() + 90;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() + 90;
        ui->calendarTab->move(ui->calendarTab->x(), newY);

        ui->profileTab_2->setVisible(true);
        ui->frame_2->setVisible(true);
    }

    else if (clickedButton == ui->dd2) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");

        toggleButtonVisibility(ui->dd2, ui->dd6);

        //reports tab
        newY = ui->reportsTab->y() + 65;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() + 65;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_3->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd3) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");
        toggleButtonVisibility(ui->dd3, ui->dd7);
        //calendarTab
        newY = ui->calendarTab->y() + 42;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_4->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd4) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");
        toggleButtonVisibility(ui->dd4, ui->dd8);
        ui->profileTab_5->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd5) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");

        toggleButtonVisibility(ui->dd5, ui->dd1);
        //alerts tab
        newY = ui->alertsTab->y() - 90;
        ui->alertsTab->move(ui->alertsTab->x(), newY);
        //reports tab
        newY = ui->reportsTab->y() - 90;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() - 90;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_2->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd6) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");

        toggleButtonVisibility(ui->dd6, ui->dd2);
        //reports tab
        newY = ui->reportsTab->y() - 65;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() - 65;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_3->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd7) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");
        toggleButtonVisibility(ui->dd7, ui->dd3);
        //calendarTab
        newY = ui->calendarTab->y() - 42;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_4->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd8) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");
        toggleButtonVisibility(ui->dd8, ui->dd4);
        ui->profileTab_5->setVisible(false);
        ui->frame_2->setVisible(false);
    }
}
