#include "signup.h"
#include "ui_signup.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QRegularExpression> // Include QRegularExpression header
#include "login.h"
#include <QCryptographicHash>

bool strongPass = false;

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

    connect(ui->nextButton, &QPushButton::clicked, this, &signup::checkEmail);
    connect(ui->nextButton_2, &QPushButton::clicked, this, &signup::checkUsername);

    ui->error_1->setVisible(false);
    ui->error_2->setVisible(false);
    ui->error_3->setVisible(false);
    ui->username_widget->setVisible(false);
    ui->pass_widget->setVisible(false);
}

signup::~signup()
{
    delete ui;
}

void signup::checkEmail() {
    QString email = ui->email_address->text();

    // Regular expression to validate the email
    QRegularExpression regex("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    QRegularExpressionMatch match = regex.match(email);

    if (!match.hasMatch()) {
        ui->error_1->setText("Please enter a valid email address.");
        ui->error_1->setVisible(true);
        return;
    }else{
        QSqlDatabase db = Database::getConnection();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM user_db WHERE email = :email");
        query.bindValue(":email", email);
        if (query.exec() && query.next()) {
            ui->error_1->setText("Email already exists. Please choose a different email.");
            ui->error_1->setVisible(true);
        }else{
            ui->error_1->setVisible(false);
            ui->email_widget->setVisible(false);
            ui->username_widget->setVisible(true);
        }
    }
}

void signup::checkUsername() {
    QString username = ui->username->text();

    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user_db WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        ui->error_2->setText("Username already exists. Please choose a different Username.");
        ui->error_2->setVisible(true);
    }else{
        ui->error_2->setVisible(false);
        ui->username_widget->setVisible(false);
        ui->pass_widget->setVisible(true);
    }
}

void signup::onPasswordTextChanged(const QString &password)
{
    // Check password length
    if (password.length() < 8) {
        ui->error_3->setText("Password must be at least 8 characters long.");
        ui->error_3->setVisible(true);
    } else {
        // Check if password contains at least one digit
        if (!password.contains(QRegularExpression("[a-z]"))) {
            ui->error_3->setText("Password must contain at least one digit.");
        }
        else if (!password.contains(QRegularExpression("[A-Z]"))) {
            ui->error_3->setText("Password must contain at least one Capital Letter.");
        }
        // Check if password contains at least one special character
        else if (!password.contains(QRegularExpression("[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]"))) {
            ui->error_3->setText("Password must contain at least one special character.");
        }
        else if (!password.contains(QRegularExpression("[0-9]"))) {
            ui->error_3->setText("Password must contain at least one number.");
        }else{
            ui->error_3->setVisible(false);
            strongPass = true;
        }
    }
}

void signup::onCreateButtonClicked()
{
    // Perform signup process
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString username = ui->username->text();
    QString email = ui->email_address->text();
    QString password = ui->password->text();
    QSqlDatabase db = Database::getConnection();

    if(strongPass){
        if(ui->conf_pass->text() == ui->password->text()){
            QSqlQuery query1(db);
            query1.prepare("INSERT INTO user_db (firstName, lastName, username, email, passwd) "
                           "VALUES (:first_name, :last_name, :username, :email, :password)");
            query1.bindValue(":first_name", firstName);
            query1.bindValue(":last_name", lastName);
            query1.bindValue(":username", username);
            query1.bindValue(":email", email);
            query1.bindValue(":password", password);

            if (query1.exec()) {
                QMessageBox information(QMessageBox::Information, "Success", "Signup successful!");
                information.setStyleSheet("background-color: white;");
                login* loginpage = new login;
                loginpage->show();
                this->close();
            }else {
                QMessageBox errorMessageBox(QMessageBox::Critical, "Error", "Signup failed!", QMessageBox::Ok, this);
                errorMessageBox.setStyleSheet("background-color: white;");
                errorMessageBox.exec();
            }
        }else{
            ui->error_3->setVisible(true);
            ui->error_3->setText("Password do not match.");
        }
    }
}

void signup::onBackButtonClicked()
{
    login* loginpage = new login;
    loginpage->show();
    this->close();
}
