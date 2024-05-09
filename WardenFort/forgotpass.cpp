#include "forgotpass.h"
#include "ui_forgotpass.h"
#include "enter.h"
#include "login.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QCryptographicHash>
#include <QSslSocket>
#include <QTextStream>
#include <QSqlError>

forgotpass::forgotpass(const QString& username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotpass),
    m_username(username)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &forgotpass::onBackButtonClicked);
    connect(ui->reset_password_button, &QPushButton::clicked, this, &forgotpass::onResetPasswordClicked1);
    connect(ui->reset_password_button_2, &QPushButton::clicked, this, &forgotpass::changePass);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &forgotpass::updateTimer);
    timer->start(1000);
    m_expiryTime = QDateTime::currentDateTime().addSecs(120);
    updateTimer();

    ui->widget_2->setVisible(false);
}


forgotpass::~forgotpass()
{
    delete ui;
}

void forgotpass::setEmail(const QString& email)
{
    ui->email_show->setText(email);
}

QString forgotpass::maskEmail(const QString& email)
{
    QString maskedEmail = email;
    int atIndex = email.indexOf('@');
    if (atIndex > 1) {
        QString maskedPart = email.left(1) + "********" + email.mid(atIndex - 1);
        maskedEmail = maskedPart;
    }
    return maskedEmail;
}

void forgotpass::updateTimer()
{
    int remainingSeconds = QDateTime::currentDateTime().secsTo(m_expiryTime);
    if (remainingSeconds < 0) {
        ui->timer->setText("00:00");
    } else {
        int minutes = remainingSeconds / 60;
        int seconds = remainingSeconds % 60;
        QString timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        ui->timer->setText(timeString);
    }
}

void forgotpass::onBackButtonClicked()
{
    enter* enterpage = new enter;
    enterpage->show();
    this->close();
}

void forgotpass::onResetPasswordClicked1()
{
    qDebug() << "Reset password button clicked. Username:" << m_username; // Debug output

    // Ensure m_username is not empty
    if (m_username.isEmpty()) {
        qDebug() << "Username is empty. Aborting reset password operation.";
        return;
    }

    qDebug() << expectedOTP;

    QString pass = ui->pass_change->text();

    if (pass == expectedOTP){
        ui->widget->setVisible(false);
        ui->widget_2->setVisible(true);
    }else{
        // Inform the user
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel { color : white; }");
        msgBox.information(this, "Password Reset", "6 digit code has been sent to your email, verify yourself first before you reset your password");
    }
}

void forgotpass::changePass() {
    QString newPass = ui->pass_change_2->text();

    QSqlQuery query;
    query.prepare("UPDATE user_db SET passwd = :password WHERE username = :username");
    query.bindValue(":password", newPass);
    query.bindValue(":username", m_username); // Assuming the username is entered directly

    if (!query.exec()) {
        qDebug() << "Error updating password:" << query.lastError().text();
        // Handle the error here, such as displaying an error message to the user
    } else {
        qDebug() << "Password updated successfully";
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel { color : white; }");
        msgBox.information(this, "Password Reset", "Password changed successfuly");

        login* loginPage = new login;
        loginPage->show();
        this->close();
        // Optionally inform the user about the successful password update
    }
}


void forgotpass::setExpectedOTP(const QString& expectedOTP) {
    this->expectedOTP = expectedOTP;
}
