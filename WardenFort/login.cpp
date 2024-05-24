#include "login.h"
#include "ui_login.h"
#include "otp.h"
#include "signup.h"
#include "enter.h"
#include "forgotpass.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel> // Include QLabel header
#include <QtSql>
#include <QRandomGenerator>
#include <QtNetwork>
#include <QtNetwork/QSslSocket>
#include <QGridLayout> // Include QGridLayout
#include <QDialog> // Include QDialog
#include "wardenfort.h"
#include "loginsession.h"
#include "wardenfort.h"

QString userEmail;

// Gmail SMTP server settings
const QString SmtpServerAddress = "smtp.gmail.com";
const int SmtpServerPort = 465; // Port 465 for SSL
const QString SmtpUsername = "heyaoican@gmail.com"; // Your Gmail email address
const QString SmtpName = "WardenFort";
const QString SmtpPassword = "noay rbpe mnbb meku"; // Your Gmail app password

// Function to generate a 6-digit code
void login::generateCode() {
    m_generatedCode.clear();
    for (int i = 0; i < 6; ++i) {
        m_generatedCode.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
}

// Function to generate a random username in the format q********
QString generateRandomUsername() {
    QString username;
    username.append("q");
    for (int i = 0; i < 8; ++i) {
        username.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
    return username;
}

// Function to generate a random domain in the format ***.***.ph
QString generateRandomDomain() {
    QString domain;
    for (int i = 0; i < 3; ++i) {
        domain.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
    domain.append(".");
    for (int i = 0; i < 3; ++i) {
        domain.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
    domain.append(".ph");
    return domain;
}

// Function to send email using Gmail SMTP
void login::sendEmail(const QString& recipientEmail, const QString& code) {
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
    QString subject = "Wardenfort One-Time Password (OTP)";
    QString message = "Your verification code is: [" + code + "] for Wardenfort application.\r\n\r\nPlease use this code to complete your authentication process.\r\n\r\nFor security purposes, please do not share this OTP with anyone.\r\n\r\nThank you!";

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

signup *signupWindow = nullptr; // Declaration of signupWindow

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    // Set the echo mode of the password input field to Password
    ui->typePASS_box->setEchoMode(QLineEdit::Password);

    // Connect the clicked() signal of the loginButton to the on_loginButton_clicked() slot
    connect(ui->loginButton, &QPushButton::clicked, this, &login::on_loginButton_clicked);

    // Connect the stateChanged() signal of the QCheckBox to the on_eye_open_clicked() and on_eye_closed_clicked() slots
    connect(ui->eye_open, &QCheckBox::stateChanged, this, &login::on_eye_open_clicked);
    connect(ui->eye_closed, &QCheckBox::stateChanged, this, &login::on_eye_closed_clicked);

    // Connect the clicked() signal of the signup_button to the on_signup_button_clicked() slot
    connect(ui->signup_button, &QPushButton::clicked, this, &login::on_signup_button_clicked);

    //Enter password implementation
    connect(ui->forgot_pass, &QPushButton::clicked, this, &login::openEnterWindow);

    connect(ui->forgot_pass, &QPushButton::clicked, this, &login::on_forgot_pass_clicked);


    // Initialize alertWindow to nullptr
    otpWindow = nullptr;
    signupWindow = nullptr;
}

login::~login()
{
    delete ui;
}


void login::on_loginButton_clicked()
{
    // Your existing login functionality
    QString username = ui->typeUN_box->text();
    QString password = ui->typePASS_box->text();

    // Query the database to check if the entered credentials are valid
    QSqlQuery query;
    query.prepare("SELECT * FROM user_db WHERE username = :username AND passwd = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Credentials are valid, proceed with login

        // Fetch user's email address from the database
        userEmail = query.value("email").toString();

        // Manipulate the email address to hide characters
        QString hiddenEmail = userEmail;
        int atIndex = hiddenEmail.indexOf('@');
        if (atIndex > 1 && atIndex < hiddenEmail.length() - 1) {
            // Hide characters between the first and last characters before '@'
            for (int i = 1; i < atIndex - 1; ++i) {
                hiddenEmail[i] = '*';
            }
        }
        
        // Generate OTP
        generateCode();

        // Send OTP to the email in the database
        sendEmail(userEmail, m_generatedCode);

        // Check if the otpWindow is already open
        if (!otpWindow) {
            // If not, create an instance and show it
            otpWindow = new otp();
            otpWindow->show();
            otpWindow->setText(userEmail, hiddenEmail);
            otpWindow->setExpectedOTP(m_generatedCode); // Set the expected OTP in the otpWindow

            // Connect the successfulLogin signal from otpWindow to the openAlertNotif slot in login
            connect(otpWindow, &otp::successfulLogin, this, &login::openAlertNotif);
        }

        // Close the login window
        this->close();
    } else {
        // Invalid credentials, display an error message
        QMessageBox::warning(this, "Login Error", "Invalid username or password.");
    }
}

void login::resubMail(){
    generateCode();
    sendEmail(userEmail, m_generatedCode);
    otpWindow = new otp();
    otpWindow->setExpectedOTP(m_generatedCode); // Set the expected OTP in the otpWindow

    // Connect the successfulLogin signal from otpWindow to the openAlertNotif slot in login
    connect(otpWindow, &otp::successfulLogin, this, &login::openAlertNotif);
}

void login::on_eye_closed_clicked()
{
    // Set the echo mode of the password input field to Password
    ui->typePASS_box->setEchoMode(QLineEdit::Password);

    // Change the icon to open eye
    ui->eye_open->setVisible(true);
    ui->eye_closed->setVisible(false);
}

void login::on_eye_open_clicked()
{
    // Set the echo mode of the password input field to Normal
    ui->typePASS_box->setEchoMode(QLineEdit::Normal);

    // Change the icon to closed eye
    ui->eye_open->setVisible(false);
    ui->eye_closed->setVisible(true);
}

void login::on_typePASS_box_returnPressed()
{
    // Trigger the login process
    on_loginButton_clicked();
}

void login::openAlertNotif() {
    // Create an instance of the alertnotif window
    WardenFort* wardenfortWindow = new WardenFort;
    // Show the alertnotif window
    wardenfortWindow->show();

    QString userName;

    QSqlQuery query;
    query.prepare("SELECT username FROM user_db WHERE email = :email");
    query.bindValue(":email", userEmail);

    if (query.exec()) {
        if (query.next()) {
            userName = query.value(0).toString();
            // Use userName as needed
            wardenfortWindow->setWelcomeText("Welcome, " + userName + "!");
        } else {
            // No rows found for the specified email
        }
    } else {
        // Error occurred while executing the query
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

void login::on_signup_button_clicked() {
    if (!signupWindow) {
        signupWindow = new signup();
    }
    // Show the signup window
    signupWindow->show();
    this->close();
}

void login::openEnterWindow() {
    // Create an instance of the enterpass window
    enter *enterWindow = new enter();
    // Show the enterpass window
    enterWindow->show();
    // Close the login window
    this->close();
}

void login::on_forgot_pass_clicked() // Implementation of on_forgot_pass_clicked
{
    QSqlQuery query;
    query.prepare("SELECT username FROM user_db WHERE email = :useremail");
    query.bindValue(":useremail", userEmail);

    if(query.exec() && query.next()) {
        QString user_id = query.value(0).toString(); // Retrieve user_id from the query result
        forgotpass* forgotpassWindow = new forgotpass(user_id);
        forgotpassWindow->show();
    } else {
        qDebug() << "Failed to retrieve user_id for email:" << userEmail;
    }
}
