#include "fortchat.h"
#include "ui_fortchat.h"  // Include the generated header file for FortChat UI

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

FortChat::FortChat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FortChat)
{
    ui->setupUi(this);
    initializeDatabase();
}

FortChat::~FortChat()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void FortChat::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("fortchat.db");

    if (!db.open()) {
        qDebug() << "Error: Unable to open database" << db.lastError().text();
    } else {
        qDebug() << "Database connection established.";

        // Create tables if they don't exist
        QSqlQuery query;
        QString createUsersTable = "CREATE TABLE IF NOT EXISTS users ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                   "username TEXT NOT NULL UNIQUE, "
                                   "password TEXT NOT NULL)";
        if (!query.exec(createUsersTable)) {
            qDebug() << "Error: Could not create users table -" << query.lastError();
        }

        QString createMessagesTable = "CREATE TABLE IF NOT EXISTS messages ("
                                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "sender_id INTEGER NOT NULL, "
                                      "receiver_id INTEGER NOT NULL, "
                                      "message TEXT NOT NULL, "
                                      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP)";
        if (!query.exec(createMessagesTable)) {
            qDebug() << "Error: Could not create messages table -" << query.lastError();
        }
    }
}

bool FortChat::addUser(const QString &username, const QString &password) {
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error: Failed to add user" << query.lastError().text();
        return false;
    }
    return true;
}

bool FortChat::storeMessage(int senderId, int receiverId, const QString &message) {
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO messages (sender_id, receiver_id, message) VALUES (:sender_id, :receiver_id, :message)");
    query.bindValue(":sender_id", senderId);
    query.bindValue(":receiver_id", receiverId);
    query.bindValue(":message", message);

    if (!query.exec()) {
        qDebug() << "Error: Failed to store message" << query.lastError().text();
        return false;
    }
    return true;
}

void FortChat::onLoginSuccessful(const QString &username) {
    currentUsername = username;
    qDebug() << "User logged in:" << username;
}
