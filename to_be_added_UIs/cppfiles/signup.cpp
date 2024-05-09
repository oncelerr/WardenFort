#include "signup.h"
#include "ui_signup.h"
#include <QGraphicsOpacityEffect>
#include <QPushButton>
#include <QMessageBox> // Include the header for QMessageBox
#include <QSqlQuery>
#include <QSqlError>

signup::signup(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(0.5); // Set opacity to 50%
    ui->label->setGraphicsEffect(opacityEffect);
    connect(ui->pushButton, &QPushButton::clicked, this, &signup::on_pushButton_clicked, Qt::UniqueConnection);

}

signup::~signup()
{
    delete ui;
}


void signup::on_pushButton_clicked()
{
    QString firstname = ui->lineEdit->text(); // Assuming QLineEdit for username input
    QString lastname = ui->lineEdit_2->text(); // Assuming QLineEdit for password input
    QString username = ui->lineEdit_3->text(); // Assuming QLineEdit for username input
    QString email = ui->lineEdit_4->text(); // Assuming QLineEdit for password input
    QString password = ui->lineEdit_5->text(); // Assuming QLineEdit for username input
    
    QSqlQuery signQuery;
    signQuery.prepare("INSERT INTO login (user_id, pass_id) VALUES (:username, :password)");
    signQuery.bindValue(":username", username);
    signQuery.bindValue(":password", password);
    qDebug() << "signup successful for username:" << username;
    if (!signQuery.exec()) {
        qDebug() << "Error executing query:" << signQuery.lastError().text();
        // Handle the error as necessary
    }
    else {
        // Commit the transaction after successful execution of the query
        QSqlDatabase::database().commit();
        qDebug() << "Signup successful for username:" << username;
    }


}

