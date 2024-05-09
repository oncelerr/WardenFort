#include "signup.h"
#include "ui_signup.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QRegularExpression> // Include QRegularExpression header
#include "login.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

    // Connect the clicked() signal of the back_button to the onBackButtonClicked() slot
    connect(ui->back_button, &QPushButton::clicked, this, &signup::onBackButtonClicked);
    connect(ui->create_button, &QPushButton::clicked, this, &signup::onCreateButtonClicked);

    // Connect the textChanged() signal of the password line edit to the slot for live password strength feedback
    connect(ui->password, &QLineEdit::textChanged, this, &signup::onPasswordTextChanged);
}

signup::~signup()
{
    delete ui;
}

void signup::onCreateButtonClicked()
{
    // Perform signup process
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString username = ui->username->text();
    QString email = ui->email_address->text();
    QString password = ui->password->text();


    // Insert data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO user_db (firstName, lastName, username, email, passwd) "
                  "VALUES (:first_name, :last_name, :username, :email, :password)");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":username", username);
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Signup successful!");
    } else {
        QMessageBox::critical(this, "Error", "Signup failed!");
    }
}

void signup::onBackButtonClicked()
{
    login* loginpage = new login;
    loginpage->show();
    this->close();
}

void signup::onPasswordTextChanged(const QString &password)
{
    QString message;

    // Check password length
    if (password.length() < 8) {
        message = "Password must be at least 8 characters long.";
    } else {
        // Check if password contains at least one digit
        if (!password.contains(QRegularExpression("\\d"))) {
            message += "Password must contain at least one digit.\n";
        }

        // Check if password contains at least one special character
        if (!password.contains(QRegularExpression("[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]"))) {
            message += "Password must contain at least one special character.\n";
        }

        // Password is strong
        if (message.isEmpty()) {
            message = "Password is strong!";
        }
    }

    // Update the QLabel with the password strength message
    ui->pass_rest->setText(message);
}
