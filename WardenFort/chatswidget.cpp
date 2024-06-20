#include "chatswidget.h"
#include "globals.h"
#include "ui_chatswidget.h"
#include "contacts.h"
#include "database.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QListWidgetItem>
#include <QWebSocket>

chats::chats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chats),
    webSocket(new QWebSocket)
{
    ui->setupUi(this);

    connect(webSocket, &QWebSocket::connected, this, &chats::onConnected);
    connect(webSocket, &QWebSocket::disconnected, this, &chats::onDisconnected);
    connect(webSocket, &QWebSocket::textMessageReceived, this, &chats::onTextMessageReceived);
    connect(ui->sendButton_2, &QPushButton::clicked, this, &chats::onSendButtonClicked);

    // Connect listWidget itemClicked signal to handleListItemClicked slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, &chats::handleListItemClicked);

    // Connect to the WebSocket server
    webSocket->open(QUrl("ws://192.168.0.166:12345"));

    // Populate contacts list
    populateContactsList();
}

chats::~chats() {
    webSocket->close();
    delete webSocket;
    delete ui;
}

void chats::populateContactsList() {
    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    QString queryString = "SELECT username FROM user_db WHERE username != :username";
    query.prepare(queryString);
    query.bindValue(":username", loggedInUser.username);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        db.close();
        return;
    }

    // Clear existing items in listWidget (optional, but recommended)
    ui->listWidget->clear();

    // Populate listWidget with usernames
    while (query.next()) {
        QString username = query.value(0).toString();
        qDebug() << "Fetched username:" << username;

        // Create contacts widget and add to listWidget
        contacts *contactWidget = new contacts(username); // Ensure contacts constructor handles the username correctly
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(contactWidget->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, contactWidget);
    }

    // Select the first item in the listWidget and trigger handleListItemClicked
    if (ui->listWidget->count() > 0) {
        ui->listWidget->setCurrentRow(0);
        handleListItemClicked(ui->listWidget->item(0));
    }

    // Close the database connection
    db.close();
}

void chats::onConnected() {
    qDebug() << "Connected to the chat server.";

    // Send initial message with user info
    QJsonObject loginMessage;
    loginMessage["type"] = "login";
    loginMessage["username"] = loggedInUser.username;
    webSocket->sendTextMessage(QJsonDocument(loginMessage).toJson(QJsonDocument::Compact));
}

void chats::onDisconnected() {
    qDebug() << "Disconnected from the chat server.";
}

void chats::onTextMessageReceived(const QString &message) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    QString type = jsonObj["type"].toString();

    if (type == "message") {
        QString sender = jsonObj["sender"].toString();
        QString content = jsonObj["content"].toString();
        qDebug() << sender + ": " + content;
    } else if (type == "private_message") {
        QString sender = jsonObj["sender"].toString();
        QString content = jsonObj["content"].toString();
        qDebug() << "[Private] " + sender + ": " + content;
    } else if (type == "error") {
        QString content = jsonObj["content"].toString();
        qDebug() << "[Error] " + content;
    } else if (type == "history") {
        QJsonArray history = jsonObj["content"].toArray();
        displayChatHistory(history);
    }
}

void chats::onSendButtonClicked() {
    QString messageText = ui->typeField_2->text();
    if (messageText.isEmpty()) {
        return;
    }

    QJsonObject message;
    message["type"] = "message";
    message["username"] = loggedInUser.username;
    message["content"] = messageText;

    // Check if it's a private message
    if (messageText.startsWith("/msg")) {
        QStringList parts = messageText.split(" ");
        if (parts.size() >= 3) {
            QString recipient = parts[1];
            message["type"] = "message";
            message["recipient"] = recipient;
            message["content"] = parts.mid(2).join(" ");
        } else {
            qDebug() << "[Error] Invalid private message format.";
            return;
        }
    }

    webSocket->sendTextMessage(QJsonDocument(message).toJson(QJsonDocument::Compact));
    ui->typeField_2->clear();
}

void chats::handleListItemClicked(QListWidgetItem *item) {
    contacts *contactWidget = qobject_cast<contacts *>(ui->listWidget->itemWidget(item));
    if (contactWidget) {
        QString recipient = contactWidget->getLabel(); // Assuming getLabel() retrieves the username
        QJsonObject request;
        request["type"] = "history_request";
        request["recipient"] = recipient;
        webSocket->sendTextMessage(QJsonDocument(request).toJson(QJsonDocument::Compact));
        qDebug() << "Requesting history for" << recipient;

        ui->user_name_2->setText(recipient);
    }
    qDebug() << ui->listWidget->itemWidget(item);
}

void chats::displayChatHistory(const QJsonArray &history) {
    ui->chatHistory->clear(); // Clear existing chat history
    if (history.isEmpty()) {
        ui->chatHistory->addItem("Say Hi!");
    } else {
        for (const QJsonValue &value : history) {
            QJsonObject msg = value.toObject();
            QString sender = msg["sender"].toString();
            QString content = msg["content"].toString();
            ui->chatHistory->addItem(sender + ": " + content);
        }
    }
}
