#ifndef CHATSWIDGET_H
#define CHATSWIDGET_H

#include <QWidget>
#include <QWebSocket>
#include "ui_chatswidget.h"
#include "contacts.h"

namespace Ui {
class chats;
}

class chats : public QWidget
{
    Q_OBJECT

public:
    explicit chats(QWidget *parent = nullptr);
    ~chats();

private slots:
    void populateContactsList();
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &message);
    void onSendButtonClicked();
    void handleListItemClicked(QListWidgetItem *item); // New slot declaration
    void displayChatHistory(const QJsonArray &history);

private:
    Ui::chats *ui;
    QWebSocket *webSocket;

    // Add any other private members as needed
};

#endif // CHATSWIDGET_H
