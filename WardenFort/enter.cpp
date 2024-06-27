#include "enter.h"
#include "ui_enter.h"
#include "forgotpass.h"
#include "login.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QtSql>
#include <QRandomGenerator>
#include <QtNetwork>
#include <QtNetwork/QSslSocket>
#include <QGridLayout> // Include QGridLayout
#include <QDialog> // Include QDialog
#include <database.h>
#include <QMessageBox>

// Gmail SMTP server settings
const QString SmtpServerAddress = "smtp.gmail.com";
const int SmtpServerPort = 465; // Port 465 for SSL
const QString SmtpUsername = "wardenfort.afp@gmail.com"; // Your Gmail email address
const QString SmtpName = "WardenFort";
const QString SmtpPassword = "dlac nvob epnu zzuq"; // Your Gmail app password

// Function to generate a 6-digit code
void enter::generateCode() {
    m_generatedCode.clear();
    for (int i = 0; i < 6; ++i) {
        m_generatedCode.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
}

forgotpass *forgotpassWindow = nullptr;

enter::enter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter)
{
    ui->setupUi(this);
    connect(ui->user_find, &QLineEdit::returnPressed, this, &enter::onSubmit);
    connect(ui->submitButton, &QPushButton::clicked, this, &enter::onSubmit);
    connect(ui->back_button, &QPushButton::clicked, this, &enter::onBackButtonClicked);
}

enter::~enter()
{
    delete ui;
}

void enter::sendEmail(const QString& recipientEmail, const QString& code) {
    // Set up SMTP connection
    QSslSocket socket;
    socket.connectToHostEncrypted(SmtpServerAddress, SmtpServerPort); // Using port 465 for SSL
    if (!socket.waitForConnected()) {
        return; // return from the function if connection fails
    }

    // Start the TLS handshake
    if (!socket.waitForEncrypted()) {
        return;
    }

    // Prepare authentication data
    QString username = SmtpUsername;
    QString name = SmtpName;
    QString password = SmtpPassword;

    // Authenticate with the SMTP server
    QTextStream stream(&socket);
    if (!socket.waitForReadyRead()) {
        return;
    }

    stream << "EHLO localhost\r\n"; // Send EHLO command
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    stream << "AUTH LOGIN\r\n"; // Specify authentication method as LOGIN
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    // Send base64-encoded username
    stream << QByteArray().append(username.toUtf8()).toBase64() << "\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    // Send base64-encoded password
    stream << QByteArray().append(password.toUtf8()).toBase64() << "\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    // Prepare email content
    QString from = SmtpName;
    QString to = recipientEmail;
    QString subject = "Wardenfort Verify User for Reset Password";
    QString message = "Your verification code is: [" + code + "] for Wardenfort reset password application.\r\n\r\nPlease use this code to complete your password change.\r\n\r\nFor security purposes, please do not share this OTP with anyone.\r\n\r\nThank you!";

    // Send email
    stream << "MAIL FROM:<" << from << ">\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    stream << "RCPT TO:<" << to << ">\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    stream << "DATA\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    stream << "From: " << from << "\r\n";
    stream << "To: " << to << "\r\n";
    stream << "Subject: " << subject << "\r\n";
    stream << "\r\n";
    stream << message << "\r\n";
    stream << ".\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }

    // Quit SMTP session
    stream << "QUIT\r\n";
    stream.flush();
    if (!socket.waitForReadyRead()) {
        return;
    }


}

void enter::onSubmit()
{
    qDebug() << "Submit button clicked";
    QString username = ui->user_find->text(); // Retrieve the entered username
    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    query.prepare("SELECT username FROM user_db WHERE username = :username");
    query.bindValue(":username", username); // Assuming the username is entered directly

    // Execute the query
    if (query.exec() && query.next()) {
        QString foundUsername = query.value(0).toString(); // Retrieve the username
        QSqlDatabase db = Database::getConnection();
        QSqlQuery emailQuery(db);
        emailQuery.prepare("SELECT email FROM user_db WHERE username = :username");
        emailQuery.bindValue(":username", foundUsername);

        // Execute the email query
        if (emailQuery.exec() && emailQuery.next()) {
            // Retrieve the email address from the query result
            QString userEmail = emailQuery.value(0).toString();

            // Now that we have the email address, generate the code and send the email
            generateCode();
            sendEmail(userEmail, m_generatedCode);

            if (!forgotpassWindow) {
                forgotpassWindow = new forgotpass(foundUsername, this); // Pass the username to forgotpass window
                forgotpassWindow->setAttribute(Qt::WA_DeleteOnClose);
            }
            QString MaskedEmail = forgotpassWindow->maskEmail(userEmail);
            forgotpassWindow->setEmail(MaskedEmail);
            forgotpassWindow->setExpectedOTP(m_generatedCode);
            forgotpassWindow->show();
            close(); // Close the enter window
        } else {
            qDebug() << "No email found for username:" << foundUsername;
            // Handle the case where no email is found for the given username
        }
    } else {
        qDebug() << "Username not found:" << username;

        // Add a popup message with customized font
        QMessageBox msgBox;
        msgBox.setText("Username not found");
        msgBox.setStyleSheet("QLabel { color : white; font-size: 16px; }");
        msgBox.setStyleSheet("QMessageBox { background-color: rgb(44, 60, 75); } QLabel { color : white; font-size: 16px; padding-right: 25px;}");
        msgBox.exec();
    }
}

void enter::onBackButtonClicked()
{
    // Create an instance of the login window and show it
    login* loginpage = new login;
    loginpage->show();
    this->close(); // Close the current window
}
