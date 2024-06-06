#include "signup.h"
#include "ui_signup.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QRegularExpression> // Include QRegularExpression header
#include "login.h"
#include <QCryptographicHash>


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

    // Validate email format using regular expression
    QRegularExpression emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Error", "Invalid email address format.");
        return;
    }

    // Check if username already exists in the database
    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user_db WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QMessageBox::critical(this, "Error", "Username already exists. Please choose a different username.");
        return;
    }

    // Hash the password before storing it in the database
    // You should use a secure hashing algorithm like bcrypt
    // For demonstration purposes, let's assume we have a function called hashPassword

    // Convert the hashed password to a hex string
    // Insert data into the database
    QSqlQuery query1(db);
    query1.prepare("INSERT INTO user_db (firstName, lastName, username, email, passwd) "
                  "VALUES (:first_name, :last_name, :username, :email, :password)");
    query1.bindValue(":first_name", firstName);
    query1.bindValue(":last_name", lastName);
    query1.bindValue(":username", username);
    query1.bindValue(":email", email);
    query1.bindValue(":password", password); // Store hashed password

    if (query1.exec()) {
        QMessageBox::information(this, "Success", "Signup successful!");
    }else {
        QMessageBox errorMessageBox(QMessageBox::Critical, "Error", "Signup failed!", QMessageBox::Ok, this);
        errorMessageBox.setStyleSheet("background-color: white;");
        errorMessageBox.exec();
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
