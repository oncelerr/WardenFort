#include "chatswidget.h"
#include "globals.h"
#include "ui_chatswidget.h"
#include <QJsonDocument>
#include <QJsonObject>

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

    // Connect to the WebSocket server
    webSocket->open(QUrl("ws://localhost:12345"));
}

chats::~chats() {
    webSocket->close();
    delete webSocket;
    delete ui;
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
    qDebug() << "Server: " + message;
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

    webSocket->sendTextMessage(QJsonDocument(message).toJson(QJsonDocument::Compact));
    qDebug() << "You: " + messageText;
    ui->typeField_2->clear();
}
