#include "chatswidget.h"
#include "globals.h"
#include "ui_chatswidget.h"
#include "contacts.h"
#include "chatmessagewidget.h"
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
#include <QFrame>
#include <QLabel>
#include <QMovie>
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>

QString recipient;

chats::chats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chats),
    webSocket(new QWebSocket)
{
    ui->setupUi(this);

    // Connect WebSocket signals
    connect(webSocket, &QWebSocket::connected, this, &chats::onConnected);
    connect(webSocket, &QWebSocket::disconnected, this, &chats::onDisconnected);
    connect(webSocket, &QWebSocket::textMessageReceived, this, &chats::onTextMessageReceived);
    connect(ui->sendButton_2, &QPushButton::clicked, this, &chats::onSendButtonClicked);
    connect(ui->uploadfileButton_2, &QPushButton::clicked, this, &chats::onUploadFileButtonClicked);

    // Connect listWidget itemClicked signal to handleListItemClicked slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, &chats::handleListItemClicked);

    // Connect to the WebSocket server
    webSocket->open(QUrl("ws://192.168.0.166:12345"));

    // Populate contacts list
    populateContactsList();

    // Set up chatHistory listWidget
    ui->chatHistory->setSelectionMode(QAbstractItemView::NoSelection);
    ui->chatHistory->setFocusPolicy(Qt::NoFocus);
}

chats::~chats() {
    webSocket->close();
    delete webSocket;
    delete ui;
}

void chats::onUploadFileButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file for reading";
        return;
    }

    QByteArray fileData = file.readAll();
    QString base64Data = QString::fromLatin1(fileData.toBase64());
    file.close();

    QJsonObject message;
    message["type"] = "file";
    message["recipient"] = recipient;
    message["filename"] = QFileInfo(fileName).fileName();
    message["content"] = base64Data;

    webSocket->sendTextMessage(QJsonDocument(message).toJson(QJsonDocument::Compact));

    // Optionally, you can also show the file upload in the chat history
    appendChatMessage(loggedInUser.username, "Uploaded file: " + QFileInfo(fileName).fileName());
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

    if (type == "message" || type == "private_message" || type == "file") {
        QString sender = jsonObj["sender"].toString();
        QString content = jsonObj["content"].toString();
        QString msgRecipient = jsonObj.value("recipient").toString();

        // Update the chat history only if the message is relevant to the current recipient
        if (msgRecipient == recipient || (sender == recipient && msgRecipient.isEmpty())) {
            if (type == "file") {
                QString filename = jsonObj["filename"].toString();
                QString downloadUrl = "http://192.168.0.166/uploaded_files/" + filename;  // Adjust the IP address and path as necessary
                QString downloadLink = "<a href=\"" + downloadUrl + "</a>";
                appendChatMessage(sender, downloadLink);
            } else {
                appendChatMessage(sender, content);
            }
        }
        qDebug() << sender + ": " + content;
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
    message["recipient"] = recipient;
    message["content"] = messageText;

    webSocket->sendTextMessage(QJsonDocument(message).toJson(QJsonDocument::Compact));
    ui->typeField_2->clear();

    // Add the sent message to the chat history
    appendChatMessage(loggedInUser.username, messageText);
}

void chats::handleListItemClicked(QListWidgetItem *item) {
    contacts *contactWidget = qobject_cast<contacts *>(ui->listWidget->itemWidget(item));
    if (contactWidget) {
        recipient = contactWidget->getLabel(); // Assuming getLabel() retrieves the username
        QJsonObject request;
        request["type"] = "history_request";
        request["recipient"] = recipient;
        webSocket->sendTextMessage(QJsonDocument(request).toJson(QJsonDocument::Compact));
        qDebug() << "Requesting history for" << recipient;

        QSqlDatabase db = Database::getConnection();
        QSqlQuery query(db);
        QString queryString = "SELECT firstName FROM user_db WHERE username = :username";
        query.prepare(queryString);
        query.bindValue(":username", recipient);

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            db.close();
            return;
        }

        if (query.next()) {
            QString firstName = query.value("firstName").toString();
            ui->user_name_2->setText(firstName);
        } else {
            ui->user_name_2->setText("Unknown");
        }

        db.close();
    }
    qDebug() << ui->listWidget->itemWidget(item);
}

void chats::displayChatHistory(const QJsonArray &history) {
    ui->chatHistory->clear(); // Clear existing chat history
    QFrame *frame = ui->frame_2;
    if (history.isEmpty()) {
        frame->setVisible(true);
        // Assuming frame_2 is a QFrame in your chats widget

        // Clear any existing content in frame_2
        // You may want to adjust this based on your actual requirement
        while (frame->layout()->count() > 0) {
            QLayoutItem *item = frame->layout()->takeAt(0);
            delete item->widget();
            delete item;
        }

        // Handle the case when history is empty
        // For example, display a default message or leave it blank
        QLabel *label = new QLabel(frame);
        label->setText("Say Hi!");
        label->setStyleSheet("font-size: 16px; color: white;");
        label->setAlignment(Qt::AlignCenter);
        frame->layout()->addWidget(label);

        // Add the GIF to frame_2 from the Qt resource file
        QString gifPath = ":/wardenfort/cathello.gif";  // Adjust path as per your resource file structure
        QMovie *movie = new QMovie(gifPath);
        QLabel *gifLabel = new QLabel(frame);
        gifLabel->setMovie(movie);
        movie->start();
        frame->layout()->addWidget(gifLabel);
    } else {
        frame->setVisible(false);
        for (const QJsonValue &value : history) {
            QJsonObject msg = value.toObject();
            QString sender = msg["sender"].toString();
            QString content = msg["content"].toString();
            if (msg.contains("filename")) {
                QString filename = msg["filename"].toString();
                QString downloadUrl = "http://192.168.0.166/uploaded_files/" + filename;  // Adjust the IP address and path as necessary
                QString downloadLink = "<a href=\"" + downloadUrl + "\" download=\"" + filename + "\">" + filename + "</a>";
                appendChatMessage(sender, downloadLink);
            } else {
                appendChatMessage(sender, content);
            }
        }
    }
}

void chats::appendChatMessage(const QString &sender, const QString &content) {
    bool isSentByUser = (sender == loggedInUser.username);
    ChatMessageWidget *chatMessageWidget = new ChatMessageWidget(content, isSentByUser);
    QListWidgetItem *item = new QListWidgetItem(ui->chatHistory);
    item->setSizeHint(chatMessageWidget->sizeHint());
    ui->chatHistory->addItem(item);
    ui->chatHistory->setItemWidget(item, chatMessageWidget);
}
